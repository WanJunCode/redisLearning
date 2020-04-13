// 尼科彻斯定理
// 任何一个整数m的立方都可以写成m个连续奇数之和

#include<iostream>
#include<string>

using namespace std;
 
int main()
{
    int m;
    while(cin>>m)
    {
        int s=m*m-m+1;
        // m-1 因为最后一个输出不要 + 后缀
        for(int i=0;i<m-1;++i)
        {
            cout<<s<<'+';
            s=s+2;
        }
        cout<<s<<endl;
    }
    return 0;
}