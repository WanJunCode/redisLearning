// 输入的字符串都是小写字母

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getIndex(char ch){
    return ch - 'a';
}

int main()
{
    string s;
    while(cin>>s)
    {
        int a[26]={0};
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            a[getIndex(s[i])]++;
        }

        int mi=a[getIndex(s[0]];//出现最少的字符次数
        for(int i=1;i<n;++i)
        {
            if (a[getIndex(s[i]]<mi)
            {
                mi=a[getIndex(s[i]];//出现最少的字符次数
            }
        }
        for(int i=0;i<n;++i)
        {
            if (a[getIndex(s[i]]>mi)
                cout<<s[i];      
        }
        cout<<endl;
    }
    return 0;
}