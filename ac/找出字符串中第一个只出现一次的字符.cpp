#include<iostream>
#include<string>

using namespace std;
 
int main()
{
    string str;
    while (cin >> str)
    {
        int a[26] = { 0 };
        bool flag = true;
        // 统计各字符出现的次数
        for (int i = 0; i < str.size(); i++)
        {
            a[str[i] - 'a']++;
        }
        // 遍历原字符串中的字符，根据数组a判断是否只出现一次
        for (int i = 0; i < str.size(); i++)
        {
            if (a[str[i] - 'a'] == 1)
            {
                cout << str[i] << endl;
                flag = false;
                break;
            }
        }
        // 如果不存在输出 -1
        if (flag)
            cout <<"-1"<<endl;
    }
    return 0;
}