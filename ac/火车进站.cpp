#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N;//火车数量
    while(cin>>N)
    {
        int train[9]={0};//火车进号码
        int temp[9]={1,2,3,4,5,6,7,8,9};//进站先后顺序
        int i,j;
        for(i=0;i<N;i++)
        {
            cin>>train[i];//train记录进站火车号，需要对它字典序输出
            temp[train[i]]=i;//temp记录进站先后顺序，需要对它进行比较（是否符合出栈要求）
        }
        sort(train,train+N);
        int count = 0;
        do
        {
            int flag=1;//该排列不符合，则置零
            for(i=0;i<N-1;i++)//对于每一个出栈数temp[train[i]]，（接下）
            {
                int current=temp[train[i]];
                int cmp=current;
                for(j=i;j<N;j++)//它之后所有比它小的数
                {
                    if(temp[train[j]]<current && temp[train[j]]<=cmp)//必须保持顺序号递减
                        cmp=temp[train[j]];
                    else if(temp[train[j]]<current && temp[train[j]]>cmp)//否则这个排序不符合
                        flag=0;//此排序不符合，flag标记为0
                    else
                        continue;
                }
            }
            if(flag==0)
                continue;
            else
                for(int k=0;k<N-1;k++)
                    cout<<train[k]<<" ";
            cout<<train[N-1]<<endl;
            count++;
        }
        while(next_permutation(train,train+N));
    }
    return 0;
}