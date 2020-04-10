// 三个约束：
// 1.字母排序
// 2.大小写同时出现按照输入顺序，例如BxbaA -> aABbx
// 3.其他字符不变

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        vector<char> result_final;
        // 遍历字母表，从原始字符串中提取所有字符
        for(int j=0; j<26; j++)
        {
            for(int i=0; i<str.size(); i++)
            {
                if(str[i]-'a'==j||str[i]-'A'==j)
                {
                    result_final.push_back(str[i]);
                }
            }
        }

        // 遍历原始字符串，将其中的字母全部替换为 result_final 中的字符顺序
        int M = 0;
        for (int i = 0; i<str.size(); i++)
        {
            if ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z'))
            {
                if (M<result_final.size())
                {
                    cout << result_final[M];
                    M++;
                }
            }else{
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}