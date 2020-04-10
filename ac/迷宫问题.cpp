#include<iostream>
#include<cstdio>

using namespace std;

void deprintf(int a[][3],int k){
    int i,j;
    if(a[k][2]!=-1){
        deprintf(a,a[k][2]);
        printf("(%d,%d)\n",a[k][0],a[k][1]);
  
    }
}
  
int main(){
    int N,M;
    while(scanf("%d %d",&N,&M)!=EOF){
        int a[500][500]={0};
        int b[1024][3]={0};
        int i,j,k;
        int n,m;
        int head,rear;
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                scanf("%d",&a[i][j]);
            }
        }

        head=0;
        rear=1;
        b[0][0]=0;
        b[0][1]=0;
        b[0][2]=-1;
        
        while(head!=rear){
            n=b[head][0];
            m=b[head][1];
            if(m+1<M&&a[n][m+1]==0){
                b[rear][0]=n;
                b[rear][1]=m+1;
                b[rear][2]=head;
                rear++;
            }
            if(n+1<N&&a[n+1][m]==0){
                b[rear][0]=n+1;
                b[rear][1]=m;
                b[rear][2]=head;
                rear++;
            }
            head++;
        }
        printf("(0,0)\n");
        deprintf(b,rear-1);
    }
    return 0;
}
