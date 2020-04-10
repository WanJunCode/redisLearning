#include<iostream>
#include<string.h>
 
using namespace std;
#define M 1000
 
bool ismatch(char *str1,char *str2)
{
    int l=strlen(str1),flag=0;
    for(int i=0;i<l&&str2[i]!='\0';i++)
    {
        if(str1[i]!=str2[i])
            flag=1;
    }
    if(flag)
        return false;
    else
        return true;
}
 
int main()
{
    char str[M][M];
    int count=0;
    while(gets(str[count]))
    {
        count++;
    }
    for(int i=0;i<count;i++)
    {
        int l=strlen(str[i]);
        char s1[M][M];
        int f1=0,f2=0;
        for(int j=0;j<l;j++)
        {
            if(str[i][j]==' ')
            {
                j++;
                while(str[i][j]==' ')
                {
                    j++;
                }
                j--;
 
                s1[f1][f2]='\0';
                f1++;
                f2=0;
                continue;      
            }
            s1[f1][f2++]=str[i][j];
        }
        s1[f1][f2]='\0';
        f1++;
 
        if(f1==1)
        {
            if(ismatch(s1[0],"reset"))
                cout<<"reset what"<<endl;
            else
                cout<<"unkown command"<<endl;  
        }
        else
        {
            if((ismatch(s1[0],"reset")&&ismatch(s1[1],"board"))&&(!ismatch(s1[0],"reboot")||(ismatch(s1[0],"reboot")&&!ismatch(s1[1],"backplane"))))
                cout<<"board fault"<<endl;
            else if((ismatch(s1[0],"reboot")&&ismatch(s1[1],"backplane"))&&(!ismatch(s1[0],"reset")||(ismatch(s1[0],"reset")&&!ismatch(s1[1],"board"))))
                cout<<"impossible"<<endl;
            else if((ismatch(s1[0],"board")&&ismatch(s1[1],"add"))&&(!ismatch(s1[0],"backplane")||(ismatch(s1[0],"backplane")&&!ismatch(s1[1],"abort"))))
                cout<<"where to add"<<endl;
            else if((ismatch(s1[0],"backplane")&&ismatch(s1[1],"abort"))&&(!ismatch(s1[0],"board")||(ismatch(s1[0],"board")&&!ismatch(s1[1],"add"))))
                cout<<"install first"<<endl;
            else if(ismatch(s1[0],"board")&&ismatch(s1[1],"delet"))
                cout<<"no board at all"<<endl;
            else
                cout<<"unkown command"<<endl;  
        }
    }
    return 0;
}