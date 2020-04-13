// 查找输入整数二进制中1的个数

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int cnt = 0;
        while (n)
        {
            if (n%2)
                cnt++;
            n = n >> 1;
        }
        cout << cnt << endl;
    }
    return 0;
}