#include<iostream>
 
using namespace std;
 
bool Ifseven(int m)
{
    bool flag=false;
    while(m>0)
    {
        if(m%10==7)
        {
            flag=true;
            break;
        }
        else
            m=m/10;
    }
    return flag;
}
 
int main()
{
    int n;
    while(cin>>n)
    {
        int count=0;
        if(n<7)
        {
            count=0;
        }
        else
        {
            for(int i=7;i<=n;i++)
            {
                // 判断是否是7的倍数
                if(i%7==0)
                    count++;
                else if(Ifseven(i))
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}