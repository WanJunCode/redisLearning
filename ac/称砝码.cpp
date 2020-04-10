// 现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
// 每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。

// 输入包含多组测试数据。
// 对于每组测试数据：
// 第一行：n --- 砝码数(范围[1,10])
// 第二行：m1 m2 m3 ... mn --- 每个砝码的重量(范围[1,2000])
// 第三行：x1 x2 x3 .... xn --- 每个砝码的数量(范围[1,6])

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int m[10]={0};//砝码的重量
        int x[10]={0};//相应砝码的数量
        for(int i=0;i<n;i++)
            cin>>m[i];
        for(int i=0;i<n;i++)
            cin>>x[i];
        int v[120000]={0};
        int max = 0;
        for(int i=0;i<n;i++)
            max+=m[i]*x[i];

        for(int i=0;i<n;i++)
        {
            for(int k=max;k>=0;k--)
            {
                for(int j=1;j<=x[i];j++)
                {
                    if(k==0||(v[k]==1))
                        v[k+j*m[i]]=1;
                }
            }
        }

        int cnt=1;
        for(int i=1;i<=max;i++){
            if(v[i]==1){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
