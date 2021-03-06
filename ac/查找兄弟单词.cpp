// 1.兄弟单词输入要先排序，这是一个坑，因为题目说了字典序
// 2.判断两个单词是否是兄弟单词，倒是很简单。
// 3.输出是个坑，比如如果要输出第2个兄弟单词，但实际上字典中只有1个符合要求
// 这个时候只输出2,

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool judgeBrother(const string &a,const string &b)
{
    if(a==b)//same string
	return false;
    if(a.size()!=b.size())
	return false;
    string ta(a.begin(),a.end());
    sort(ta.begin(),ta.end());
    string tb(b.begin(),b.end());
    sort(tb.begin(),tb.end());
    return ta==tb;
}

int main()
{
    int n;

    while(cin>>n)
    {
        vector<string>input(n);
        for(int i=0;i<n;++i)
        {
            cin>>input[i];
        }
        sort(input.begin(),input.end());
        string target;
        cin>>target;
        int k;
        cin>>k;

        vector<string>res;
        res.reserve(1024);
        int count=0;
        for(int i=0;i<input.size();++i)
        {
            if(judgeBrother(input[i],target))
            {
                ++count;
                res.push_back(input[i]);
            }
        }
        cout<<count<<endl;
        if(k<=count)
            cout<<res[k-1]<<endl;
    }
    return 0;
}