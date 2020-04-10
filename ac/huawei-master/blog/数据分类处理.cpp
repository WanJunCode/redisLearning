#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool contain(int n,int i)
{
    string x1=to_string(n);
    string x2=to_string(i);
    return (x1.find(x2)==string::npos)?false:true;
}

int main(int argc,char **argv)
{
    int In;
    int Rn;

    while(cin>>In)
    {
        int tmp;
        vector<int> I;
        vector<int> R;
        I.reserve(1024);
        R.reserve(1024);
        for(int i=0;i<In;++i)
        {
            cin>>tmp;
            I.push_back(tmp);
        }
        cin>>Rn;
        for(int i=0;i<Rn;++i)
        {
            cin>>tmp;
            R.push_back(tmp);
        }

        // 对 R 进行排序去重
        sort(R.begin(),R.end());
        R.erase(unique(R.begin(),R.end()),R.end());
        bool flag;

        // 所有需要输出的都保存在 fin
        vector<int> fin;
        // 遍历序列 R
        for(int i=0; i<R.size() ;++i)
        {
            vector<int> result; // 存储匹配的索引和值
            flag=false;
            // 遍历 I 序列，查看是否有匹配的，存储匹配项的索引和值
            for(int j=0;j<In;++j)
            {
                if(contain(I[j],R[i]))
                {
                    flag=true;
                    result.push_back(j);
                    result.push_back(I[j]);
                }
            }

            // 具有匹配的 I 序列，才会输出
            if(flag)
            {
                fin.reserve(1024);
                // R[i]  匹配的数量
                fin.push_back(R[i]);
                fin.push_back(result.size()/2);
                // 输出 R[i] 匹配的数量  索引 值 [***]
                for(int i=0;i<result.size();++i)
                {
                    fin.push_back(result[i]);
                }
            }
        }
        
        cout<<fin.size()<<" ";
        for(int i=0;i<fin.size()-1;++i)
        {
            cout<<fin[i]<<" ";
        }
        cout<<fin[fin.size()-1]<<endl;
    }
    return 0;
}