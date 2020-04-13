// 放苹果
/*  解题分析：
        设f(num_apple,n) 为num_apple个苹果，n个盘子的放法数目，则先对n作讨论，
        当n>num_apple：必定有n-num_apple个盘子永远空着，去掉它们对摆放苹果方法数目不产生影响。即if(n>num_apple) f(num_apple,n) = f(num_apple,num_apple)　　
        当n<=num_apple：不同的放法可以分成两类：
        1、有至少一个盘子空着，即相当于f(num_apple,n) = f(num_apple,n-1); 
        2、所有盘子都有苹果，相当于可以从每个盘子中拿掉一个苹果，不影响不同放法的数目，即f(num_apple,n) = f(num_apple-n,n).
        而总的放苹果的放法数目等于两者的和，即 f(num_apple,n) =f(num_apple,n-1)+f(num_apple-n,n)
    递归出口条件说明：
        当n=1时，所有苹果都必须放在一个盘子里，所以返回１；
        当没有苹果可放时，定义为１种放法；
        递归的两条路，第一条n会逐渐减少，终会到达出口n==1;
        第二条num_apple会逐渐减少，因为n>num_apple时，我们会return f(num_apple,num_apple)　所以终会到达出口num_apple==0．
*/


#include<stdio.h>
int func(int num_apple,int plane)
{
    if((num_apple==1)||(plane==1)) return 1;
    if(plane>num_apple) {int i=func(num_apple,num_apple); return i;}
    if(num_apple==plane) {int i=func(num_apple,num_apple-1)+1; return i;}
    if(num_apple>plane) {int i=func(num_apple,plane-1)+func(num_apple-plane,plane); return i;}
    return 0;
}

int main()
{
    int num_apple,num_pan;
    while(scanf("%d %d",&num_apple,&num_pan)!=EOF)
    {
        int r=func(num_apple,num_pan);
        printf("%d\n",r);
    }
    return 0;
}