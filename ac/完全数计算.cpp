#include<iostream>
 
using namespace std;
 
bool is_perfect_num(int i){
    int sum = 0, j=1,t=i/2;
    while (j<t){
        if (i%j == 0) {
            sum += j;
            if (j != 1) {
                t = i / j;
                // 防止 5*5=25 的情况
                if (j != i / j) sum += t;
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
    // 遍历小于 n 的所有数，判断是否是完全数
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
