#include <stdio.h>

int main(void){
    int n,m;
    int a[10]={0,0,0,0,0,0,0,0,0,0};//标记
    scanf("%d",&n);
    while(n){
       m=n%10;
       if(a[m]!=1){
          a[m]=1;
          printf("%d",m);
       }
       n=n/10;
    }
    return 0;
}