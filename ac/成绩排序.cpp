#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int flag;
        cin >> flag;
        int arr[1000];
        string str[1000];
        for (int i = 0; i < n; i++)
            cin >> str[i] >> arr[i];//利用cin输入特性依次输入姓名与成绩
        int j;

        for (int i = 0; i < n; i++)
        {
            int max = arr[0], min = arr[0];
            int x = 0;
            for (j = 0; j < n; j++)
            {
                if (flag == 0)
                {
                    if (max<arr[j])//找到最大的成绩，并取出下标
                    {
                        max = arr[j];
                        x = j;
                    }
                }
                else if (flag == 1)
                {
                    if (min>arr[j])
                    {
                        min = arr[j];
                        x = j;
                    }
                }
            }
            cout << str[x] << " " << arr[x] << endl;
            if (flag == 0)
                arr[x] = -1;
            else if (flag == 1)
                arr[x] = 10000;
        }
    }
    return 0;
}