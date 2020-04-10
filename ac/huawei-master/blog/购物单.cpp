#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;

    // n 总钱数     m 希望购买的物品数量
    while(cin>>n>>m)
    {
        vector<int> v(m+1);//value     价格
        vector<int> p(m+1);//importance     重要度
        vector<int> q(m+1);//major or minor     主键0  附件，表示依附的主键编号
        
        // m 希望购买的物品数量  n 总钱数
        vector<vector<int> > dp(m+1,vector<int>(n+1));//dp  动态规划，创建二维数组，初始值都是 0
        
        //input
        for(int i=1;i<=m;++i)
        {
            cin>>v[i]>>p[i]>>q[i];
        }

        // dp[希望购买的物品数量][总钱数]
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                // 拿 i 件物品，总金钱是 j 。  dp[i][j] 记录最大的期望值

                if(!q[i])//major
                {
                    // 如果物品 i 是主要物品，并且目前的总价格可以购买
                    if(v[i]<=j)     // 只有当前的 金钱 j 可以买物品 i 才进行下面的更新
                    {
                        // 最大值：  少买一个物品的总期望值   |   少买一个物品并且少了该物品价格的总期望值+买这件物品的期望值
                        dp[i][j]=max( dp[i-1][j] , dp[i-1][j-v[i]]+v[i]*p[i] );
                    }
                }
                else// minor
                {
                    // 物品 i 是附送的物品，  并且附送的物品价格+主物品的价格  小于总金额
                    if(v[i]+v[q[i]]<=j) // 当前的金钱 j 可以买主要物品q[i]和附件 i 才考虑下面的更新 
                    {
                        dp[i][j]=max( dp[i-1][j] , dp[i-1][j-v[i]]+v[i]*p[i] );
                    }
                }
            }
        }//end for
        
        // m 希望购买的物品数量  n 总钱数
        cout<<dp[m][n]<<endl;
    }
}