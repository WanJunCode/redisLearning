#include<iostream>
#include<string>

using namespace std;
 
int main()
{
    int m;
    while(cin>>m)
    {
        int s=m*m-m+1;
        for(int i=0;i<m-1;++i)
        {
            cout<<s<<'+';
            s=s+2;
        }
        cout<<s<<endl;
    }
    return 0;
}