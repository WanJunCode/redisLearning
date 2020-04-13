#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string str;
    map<char, int> tb;
    while (cin >> str) {
        // str 存入 map 中
        for (int i = 0; i < str.size(); i++) {
            if (tb.find(str[i]) != tb.end()) {
                tb[str[i]] += 1;
            }
            else {
                tb[str[i]] = 1;
            }
        }

        // 不断删除 map 中出现次数最多的字符
        while(!tb.empty()) {
            char maxch;
            int maxcount = 0;
            for (std::map<char, int>::iterator iter = tb.begin(); iter != tb.end(); iter++) {
                if (iter->second > maxcount) {
                    maxcount = iter->second;
                    maxch = iter->first;
                }
            }
            cout << maxch;
            tb.erase(maxch);
        }
        cout << endl;
    }
}