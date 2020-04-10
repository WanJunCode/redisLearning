#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int data;
    while(cin >> data){
        double sum = data;
        double height = data;
        for(int i = 2; i <= 5; ++i){
            height /= 2;
            sum += height * 2;          
        }
        cout << sum << endl << height/2 << endl;
    }
    return 0;
}