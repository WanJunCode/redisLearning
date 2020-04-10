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
        for (int i = 0; i < str.size(); i++)
        {
            a[str[i] - 'a']++;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (a[str[i] - 'a'] == 1)
            {
                cout << str[i] << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout <<"-1"<<endl;
    }
    return 0;
}