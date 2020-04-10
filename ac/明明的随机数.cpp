#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int>v;
        v.reserve(1024);
        int j;
        for(int i=0;i<n;++i)
        {
            cin >> j;
            v.push_back(j);
        }
        // 排序
        sort(v.begin(),v.end());
        // 去重
        v.erase(unique(v.begin(),v.end()),v.end());
        if(v.capacity()<1024)
            vector<int>(v).swap(v);

        for(int i=0;i<v.size();++i)
            cout<<v[i]<<endl;
    }
    return 0;
}