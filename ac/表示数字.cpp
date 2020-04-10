#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin>>str;
	int length=str.size();
	for(int i=0;i<length;)
	{
		int k=i;
		while (!isdigit(str[k]))
			k++;
		str.insert(k,"*");
		length++;
		k=k+2;
		while (isdigit(str[k]))
			k++;
		str.insert(k,"*");
		length++;
		i=k+2;	  
	}
	cout<<str<<endl;
}