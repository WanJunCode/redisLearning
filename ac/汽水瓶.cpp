#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d\n",&n)!=EOF)
    {
        if(n==0)
            break;
        int count = 0;
        while(n>=3)
        {
            count = count + n/3;
            n = n%3 +n/3;
        }
        if(n==2)
            count++;
        printf("%d\n",count);
    }
    return 0;
}
