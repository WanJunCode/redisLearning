#include<iostream>
 
using namespace std;
 
bool is_perfect_num(int i){
    int sum = 0, j=1,t=i/2;
    while (j<t){
        if (i%j == 0) {
            sum += j;
            if (j != 1) {
                t = i / j;
                if (j != i / j) sum += i/j;
            }          
        }
        ++j;
        if (sum>i) return false;
    }
    return (sum == i)?true:false;
}
 
int count_perfect_num(int n){
    if (n<=0||n>500000) return -1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (is_perfect_num(i)) ++cnt;
    return cnt;
}
 
int main(){
    int range;
    while (cin >> range){
        cout << count_perfect_num(range) << endl;
    }
    return 0;
}
