#include <stdio.h>
#include <string.h>
 
void ip2num(long long int a,int b,int c,int d){
    long long int n=(a<<24)+(b<<16)+(c<<8)+d;
    printf("%lld\n",n);
}
 
void num2ip(int n){
    int a,b,c,d;
    a=(n&0xFF000000)>>24;
    b=(n&0x00FF0000)>>16;
    c=(n&0x0000FF00)>>8;
    d=n&0x000000FF;
    printf("%d.%d.%d.%d\n",a,b,c,d);
}

int main(void){
    int a,b,c,d,num;
    while(scanf("%d.%d.%d.%d\n%d",&a,&b,&c,&d,&num)!=EOF){
        ip2num(a,b,c,d);
        num2ip(num);
    }
    return 0;
}