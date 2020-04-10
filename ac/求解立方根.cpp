#include<iostream>

using namespace std;

double abs(double n){
    return n>0?n:-n;
}
 
double cube(double y){
    double x;
    for(x=1.0;abs(x*x*x-y)>1e-7;x=(2*x+y/x/x)/3);  //通过牛顿迭代思想，计算一个实数的立方根
    return x;
}
 
int main(void){
    cout.precision(2);
    double y;
    while(cin>>y){
        cout<<cube(y)<<endl;
    }
}