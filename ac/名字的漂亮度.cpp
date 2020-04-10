#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    while (cin >> N)
    {
        while (N--)
        {
            string str;
            cin >> str;
            vector<int> n;
            vector<char> alph;
            for (int i = 0; i < str.length(); i++)
            {
                bool flag = 1;
                for (int j = 0; j < alph.size(); j++)
                {
                    if (str[i] == alph[j])
                    {
                        n[j]++;
                        flag = 0;
                    }
                }

                if (flag)
                {
                    alph.push_back(str[i]);
                    n.push_back(1);
                }
            }
            int sum = 0;
            sort(n.begin(), n.end(),compare);
            for (int i = 0; i < n.size(); i++)
                sum += (26 - i)*n[i];
            cout << sum << endl;
        }
    }
    return 0;
}