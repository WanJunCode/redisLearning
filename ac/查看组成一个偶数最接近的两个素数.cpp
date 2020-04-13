// 查看组成一个偶数最接近的两个素数

#include <iostream>
#include <string>

using namespace std;
 
//  判断是否是素数
bool isS(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
 
void FindNum(int num)
{
    if (num <= 2|| num%2 != 0)
        return;
    
    int middle = num / 2;
    for (int i = middle; i >= 2; i--)
    {
        if (isS(i) == true && isS(num-i) == true)
        {
            cout << i << endl;
            cout << num-i << endl;
            break;
        }
    }
}
 
int main()
{
    int num;
    while (cin>>num)
    {
        FindNum(num);
    }
    return 0;
}