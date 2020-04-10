#include <iostream>
#include <iomanip>
  
using namespace std;
  
int main() 
{
    int n;
    int cnt_neg = 0;
    int cnt_pos = 0;
    double sum = 0;
    while (cin >> n)
    {
        if (n >= 0)
        {
            sum += n;
            cnt_pos++;
        }
        else
            cnt_neg++;
    }
    cout << cnt_neg << endl;
    cout <<  setprecision(1)<<fixed << sum / cnt_pos << endl;
    return 0;
}