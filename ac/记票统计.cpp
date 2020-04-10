#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N)
    {
        vector<string> name, vote;
        string temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            name.push_back(temp);
        }
        cin >> M;
        for (int i = 0; i < M; i++)
        {
            cin >> temp;
            vote.push_back(temp);
        }
        
        vector<int> num(N + 1, 0);
        for (int i = 0; i < M; i++)
        {
             
            vector<string>::iterator pos = find(name.begin(), name.end(), vote[i]);
            if (pos != name.end())
                num[pos-name.begin()]++;
            else
                num[N]++;
        }

        for (int i = 0; i < N; i++)
        {
            cout << name[i] << " : " << num[i] << endl;
        }
        cout << "Invalid : " << num[N] << endl;
    }
    return 0;
}
