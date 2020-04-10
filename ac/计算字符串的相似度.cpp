#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define min(a,b) (a<b)?a:b;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i<len2 + 1; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 0; i<len1 + 1; i++)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i<len1 + 1; i++)
        {
            for (int j = 1; j<len2 + 1; j++)
            {
                int one = dp[i - 1][j]+1, two = dp[i][j - 1]+1, three = dp[i - 1][j - 1];
                if (str1[i-1] != str2[j-1])
                {
                    three++;
                }
                int tmp = min(one, two);
                dp[i][j] = min(tmp,three);
            }
        }

        cout << "1/" << dp[len1][len2] + 1 << endl;
    }
    return 0;
}