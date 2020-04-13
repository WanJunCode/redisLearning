// 公共字串计算

// 计算两个字符串的最大公共字串的长度，字符不区分大小写

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
    string str1,str2;
    while(cin>>str1)
    {
        cin>>str2;
        // 动态规划
        vector<vector<int> > dp(str1.size(),vector<int>(str2.size()));
        int max_num=0;  // 初始化不能忘记
        for(int i=0;i<str1.size();i++)
        {
            for(int j=0;j<str2.size();j++)
            {
                // 或者
                if(i==0||j==0){
                    dp[i][j]=1;
                    if(max_num<1)
                        max_num=1;
                }else if(str1[i]!=str2[j]){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>max_num)
                        max_num=dp[i][j];
                }
            }
        }
        cout<<max_num<<endl;
    }
    return 0;
}