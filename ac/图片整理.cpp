#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[1000],temp;
    int i,j,len;
    while(gets(arr)!=NULL){
        len = strlen(arr);
        // 冒泡排序
        for(i=0;i<len-1;i++){
            for(j=i+1;j<len;j++){
                if(arr[i]>arr[j]){
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        puts(arr);
    }
    return 0;
}