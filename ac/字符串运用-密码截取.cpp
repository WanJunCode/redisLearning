// 链接：https://www.nowcoder.com/questionTerminal/12e081cd10ee4794a2bd70c7d68f5507
// 来源：牛客网

// Catcher 是MCA国的情报员，他工作时发现敌国会用一些对称的密码进行通信，比如像这些ABBA，ABA，A，123321，
// 但是他们有时会在开始或结束时加入一些无关的字符以防止别国破解。比如进行下列变化 ABBA->12ABBA,ABA->ABAKK,123321->51233214　。
// 因为截获的串太长了，而且存在多种可能的情况（abaaab可看作是aba,或baaab的加密形式），Cathcer的工作量实在是太大了，
// 他只能向电脑高手求助，你能帮Catcher找出最长的有效密码串吗？

// （注意：记得加上while处理多个测试用例）
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    string str;
    while (cin>>str)
    {
        int len=str.size();
        vector< vector <int> > dp(len+1,vector<int>(len+1,0));
        string res(str);
        reverse(res.begin(),res.end());

        //  动态规划
        int max=0;
        for (int i=1;i<=len;i++){
            for(int j=1;j<=len;j++)
            {
                if (str[i-1]==res[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }

                // 记录最大的期望值
                if (dp[i][j]>max)
                {
                    max=dp[i][j];
                }
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
