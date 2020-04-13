// 合法IP，判断输入的字符串表示的IP地址是否合法
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
 
int main()
{
    string s;
    while( cin>>s )
    {
        bool yes=true;
        int cnt=count(s.begin(),s.end(),'.');
        if(cnt!=3)
            yes=false;
        vector<int> V;
        if(yes)
        {
            for(int i=0;i<4;i++)
            {
                int idx=s.find('.');
                V.push_back( stoi(s.substr(0,idx) ) ); 
                s=s.substr(idx+1);
            }
        }
        
        for(int i=0;i<V.size();i++)
        {
            if(V[i]<0 || V[i]>255)
                yes=false;
        }

        if(yes)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
