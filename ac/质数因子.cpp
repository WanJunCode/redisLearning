#include <iostream>
using namespace std;
 
int main(void)
{
	long input;
    cin>>input;
    for(int i=2;i<input;i++){
        if(input%i==0){
            input=input/i;
            cout<<i<<" ";
            i--;
        }
    }
	return 0;
}