#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str1[500], str2[500];
    while (cin >> str1 >> str2)
    {
        int num1[500] = { 0 };
        int num2[500] = { 0 };
        int result[501] = { 0 };
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        for (int i = 0; i < length1; i++)
            num1[i] = str1[length1 - 1 - i] - '0';
        for (int i = 0; i < length2; i++)
            num2[i] = str2[length2 - 1 - i] - '0';
        
        // core code
        int carry = 0, i = 0;
        for (i = 0; i < length1 + 1 || i < length2 + 1; ++i)
        {
            // carry 存储是否进位
            result[i] = (num1[i] + num2[i] + carry) % 10;
            carry = ((num1[i] + num2[i] + carry) > 9 ? 1 : 0);
        }
        
        // 注意上层循环结束后 i++ 
        for (int j = i - 1; j >= 0; --j)
        {
            // import
            if ((j == i - 1) && result[j] == 0)
                continue;
            else
                cout << result[j];
        }
        cout << endl;
    }
    return 0;
}