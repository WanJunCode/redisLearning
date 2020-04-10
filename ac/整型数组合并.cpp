#include <iostream>
#include <set>

using namespace std;

int main() 
{
    int num1,num2, tmp;
    while (cin >> num1) {
        set<int> res;
        while (num1--) {
            cin >> tmp;
            res.insert(tmp);
        }
        cin >> num2;
        while (num2--) {
            cin >> tmp;
            res.insert(tmp);
        }
        set<int>::iterator iter;
        for(iter=res.begin();iter!=res.end();iter++)
            cout<<*iter;
        res.clear();
        cout << endl;
    }
    return 0;
}