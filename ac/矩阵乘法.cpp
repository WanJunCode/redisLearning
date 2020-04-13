// 矩阵乘法

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int m1[100][100],m2[100][100],x,y,z,r[100][100];
    while(cin >> x >> y >> z)
    {
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                cin >> m1[i][j];
            }
        }
        for (int i = 0; i < y; ++i)
        {
            for (int j = 0; j < z; ++j)
            {
                cin >> m2[i][j];
            }
        }
        // 计算矩阵乘法 x,y,z
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < z; ++j)
            {
                int k=0,ans=0;
                while(k < y)
                {
                    ans += m1[i][k] * m2[k][j];
                    k++;
                }
                r[i][j] = ans;             
            }      
        }
        
        for (int i = 0; i < x; ++i)
        {
            // z-1 ，因为最后一个元素输出后要换行
            for (int j = 0; j < z-1; ++j)
            {
                cout << r[i][j] << ' ';
            }
            cout << r[i][z-1] << endl;
        }
    }
    return 0;
}
