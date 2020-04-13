// 记票统计
// 统计投票人数

// 输入候选人的人数，第二行输入候选人的名字，第三行输入投票人的人数，第四行输入投票。
// 每行输出候选人的名字和得票数量。
// example
// input    ============================
// 4
// A B C D
// 8
// A B C D E F G H
// output   ============================
// A : 1
// B : 1
// C : 1
// D : 1
// Invalid : 4

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int numVotee, people;
    
    while (cin >> numVotee)
    {
        vector<string> name, vote;
        string temp;
        // 输入所有的候选人名称
        for (int i = 0; i < numVotee; i++)
        {
            cin >> temp;
            name.push_back(temp);
        }
        // 输入投票人数，以及对应的投票
        cin >> people;
        for (int i = 0; i < people; i++)
        {
            cin >> temp;
            vote.push_back(temp);
        }
        
        // 最后一位存储无效的投票数量
        vector<int> num(numVotee + 1, 0);
        for (int i = 0; i < people; i++)
        {
            vector<string>::iterator pos = find(name.begin(), name.end(), vote[i]);
            if (pos != name.end())
                num[pos-name.begin()]++;        // 为对应的候选人票数加1
            else
                num[numVotee]++;
        }

        for (int i = 0; i < numVotee; i++)
        {
            cout << name[i] << " : " << num[i] << endl;
        }
        cout << "Invalid : " << num[numVotee] << endl;
    }
    return 0;
}
