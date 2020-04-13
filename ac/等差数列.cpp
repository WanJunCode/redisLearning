// 等差数列

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int a=2;
        int sum=2;
        for(int i=1;i<n;i++)
        {
            a=a+3;
            sum=sum+a;
        }
        cout<<sum<<endl;
    }
    return 0;
}