#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int i;
	cin >> i;
	do {
		cout<<(char) (i % 10 + 48);
		i = i / 10;
	} while (i);
 
	return 0;
}