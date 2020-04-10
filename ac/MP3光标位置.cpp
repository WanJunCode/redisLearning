#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
 
int main(){
    int n,i,num,step;
    char str[1000];

    while(scanf("%d",&n)!=EOF){
        scanf("%s",str);
        i=0,num=1,step;
        while(str[i]!='\0'){
            if(str[i]=='U'){
                if(num-1==0){
                    num=n;
                    step=4;
                }else{
                    num-=1;
                    if(step!=1) step--;
                } 
            }
            if(str[i]=='D'){
                if(num==n){
                    num=1;
                    step=1;
                }else{
                    num+=1;
                    if(step!=4) step++;
                }
            }
            i++;
        }

        if(n<=4){
            for(i=1;i<=n;i++){
                if(i==n) 
                    printf("%d\n",i);
                else 
                    printf("%d ",i);
            }
        }
        else{
            for(i=num-step+1;i<=num-step+4;i++){
                if(i==num-step+4) 
                    printf("%d\n",i);
                else 
                    printf("%d ",i);     
            }
        }
        printf("%d\n",num);
    }
}