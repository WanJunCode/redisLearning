#include <iostream>
#include <stack>
#include <string>
using namespace std;
 
int main()
{
	stack<string> ss;
	string s;
	while (cin >> s)
	{
		ss.push(s);
	}
	while (!ss.empty())
	{
		cout << ss.top();
		ss.pop();
		if (!ss.empty())
			cout << ' ';
	}
	cout << endl;
    return 0;
}