#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
// Longest common continuous substring 最长公共连续子串
// str2 长度大于 str1
string LCCS(const string& str1, const string& str2) {
    string ret;
    int sz1 = str1.size(), sz2 = str2.size();

    // 动态规划
    vector<vector<int> > dp(sz1+1, vector<int>(sz2+1, 0));
    for (int i = 1; i <= sz1; ++i) {
        for (int j = 1; j <= sz2; ++j)
        {
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > ret.size())
                    ret = str1.substr(i-dp[i][j], dp[i][j]);
            }
        }
    }
    return ret;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2){
        if(str1.size() > str2.size())
            swap(str1, str2);
        cout << LCCS(str1, str2) << endl;
    }
    return 0;
}