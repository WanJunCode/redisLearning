#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	string s;
	getline(cin, s);
	int a[128] = { 0 }, num = 0;
	for (int i = 0; i<s.size(); i++) {
		a[(int)s.at(i)]++;
	}
	for (int i = 0; i < 128; i++) {
		if (a[i] != 0)
			num++;
	}
	cout << num;
 
	return 0;
}