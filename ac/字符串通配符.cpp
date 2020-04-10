#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

#define max(a,b) (a>b)?a:b;
 
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {      
        int len1=str1.size();
        int len2=str2.size();
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        dp[0][0]=1;
        for(int i=1;i<len1+1;i++)
        {
            char ch=str1[i-1];
            dp[i][0]=dp[i-1][0]&&(ch=='*');
            for(int j=1;j<len2+1;j++)
            {
                if(str1[i-1]=='*')
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }else{
                    dp[i][j]=dp[i-1][j-1]&&(str1[i-1]=='?'||str1[i-1]==str2[j-1]);
                }
            }
        }
        if(dp[len1][len2]==1)
        {
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}