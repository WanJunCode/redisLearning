#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int j;
	j = s.length() - 1 - s.rfind(' ');
	cout << j;
	return 0;
}