#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    while(cin>>n)
    {
        string str(n.rbegin(),n.rend());
        cout<<str<<endl;
    }
    return 0;
}