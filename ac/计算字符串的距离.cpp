#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        int i,j,len1=str1.size(),len2=str2.size();
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        for(i=1;i<=len1;i++)
            dp[i][0]=i;
        for(i=1;i<=len2;i++)
            dp[0][i]=i;
        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++)
            {
                int m1=min(dp[i-1][j],dp[i][j-1])+1;
                dp[i][j]=min((str1[i-1]==str2[j-1]?0:1)+dp[i-1][j-1],m1);
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}