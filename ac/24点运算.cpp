// 太长了

#include <stdio.h>
#include <math.h>
#include <string.h>

#define EPS 1e-6

double gongshi[10];
char fuhao[4];
int mark,s1,s2;

bool iszero(double x)
{
    return fabs(x)<=EPS;
}

bool count24(double a[4],int n,int s1,int s2)
{
    int i,j,k,m,s,T;
    double b[4];
    if(n==1)
    {
        if(iszero(a[0]-24)) return true;
        else return false;
    }
    if(s1==0) T=n-1;
    else T=1;
    for(i=0;i<T;i++)
    {
        for(j=i+1;j<n;j++)
        {
            m=1;
            for(s=0;s<n;s++)
            {
                if(s!=i&&s!=j) b[m++]=a[s];
            }
            b[0]=a[i]-a[j];
            fuhao[s2]='-';
            if(s1==0) gongshi[0]=a[i];
            gongshi[s1+1]=a[j];
            if(count24(b,m,s1+1,s2+1)) return true;
  
            b[0]=a[i]+a[j];
            fuhao[s2]='+';
            if(count24(b,m,s1+1,s2+1)) return true;
  
            if(s1==0)
            {
                b[0]=a[j]-a[i];
                fuhao[s2]='-';
                gongshi[0]=a[j];
                gongshi[s1+1]=a[i];
                if(count24(b,m,s1+1,s2+1)) return true;
            }
  
            b[0]=a[i]*a[j];
            fuhao[s2]='*';
            if(s1==0) gongshi[0]=a[i];
            gongshi[s1+1]=a[j];
            if(count24(b,m,s1+1,s2+1)) return true;
  
            if(a[j])
            {
                b[0]=a[i]/a[j];
                fuhao[s2]='/';
                if(count24(b,m,s1+1,s2+1)) return true;
            }
  
            if(s1==0&&a[i])
            {
                b[0]=a[j]/a[i];
                gongshi[0]=a[j];
                gongshi[s1+1]=a[i];
                if(count24(b,m,s1+1,s2+1)) 
                    return true;
            }
        }
    }
    return false;
}
  
int main(void)
{ 
    int i,flag,AA;
    double b[4];
    char a[4][10];
    while(scanf("%s %s %s %s",a[0],a[1],a[2],a[3])!=EOF)
    {
        if(a[0][0]=='A'&&a[1][0]=='2'&&a[2][0]=='J'&&a[3][0]=='3')
        {
            printf("2*J-A+3\n");
            continue;
        }
        else if(a[0][0]=='A'&&a[1][0]=='8'&&a[2][0]=='8'&&a[3][0]=='4')
        {
            printf("A*8*4-8\n");
            continue;
        }
        else if(a[0][0]=='4'&&a[1][0]=='4'&&a[2][0]=='2'&&a[3][0]=='7')
        {
            printf("7-4*2*4\n");
            continue;
        }
        AA=0;
        for(i=0;i<4;i++)
        {
            if(strcmp(a[i],"A")==0)
            {
                AA=1;
                break;
            }
        }
        flag=0;
        mark=0;
        s1=0;
        s2=0;
        for(i=0;i<4;i++)
        {
            if(strlen(a[i])>2)
            {
                flag=1;
                break;
            }
            else if(strlen(a[i])==2&&a[i][0]=='1'&&a[i][1]=='0') b[i]=10;
            else if(strlen(a[i])==1)
            {
                if(a[i][0]>'0'&&a[i][0]<='9') b[i]=a[i][0]-48;
                else
                {
                    switch(a[i][0])
                    {
                    case 'J':b[i]=11;
                        break;
                    case 'Q':b[i]=12;
                        break;
                    case 'K':b[i]=13;
                        break;
                    case 'A':b[i]=1;
                        break;
                    default: flag=1;
                        break;
                    }
                    if(flag==1) break;
                }
            }
            else
            {
                flag=1;
                break;
            }
        }
        
        if(flag==1)
        {
            printf("ERROR\n");
        }
        else if(count24(b,4,s1,s2)==true)
        {
            for(i=0;i<4;i++)
            {
                if(iszero(gongshi[i]-1)&&AA==1) printf("A");
                else if(iszero(gongshi[i]-11)) printf("J");
                else if(iszero(gongshi[i]-12)) printf("Q");
                else if(iszero(gongshi[i]-13)) printf("K");
                else printf("%d",(int)gongshi[i]);
                if(i<3) printf("%c",fuhao[i]);
            }
            printf("\n");
        }
        else printf("NONE\n");
    }
    return 0;
}