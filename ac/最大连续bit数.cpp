#include<iostream>
using namespace std;
 
int main()
{
    int n;
    while(cin>>n)
    {
        int num=0,max=0;
        while(n)
        {
            if(n&0x01==1)
            {
                num++;
                if(num>max)
                   max=num;
            }else{
               num=0;
            }
            n>>=1;
        }
        cout<<max<<endl;
    }
    return 0;
}