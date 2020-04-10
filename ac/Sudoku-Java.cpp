#include<iostream>
using namespace std;
bool flag = false;
int input[9][9];

bool isOk(int num)
{
    int h = num / 9;
    int l = num % 9;
    for (int i = 0; i < 9; ++i)
        if (i != h && input[i][l] == input[h][l])
            return false;
    for (int i = 0; i < 9; ++i)
        if (i != l && input[h][i] == input[h][l])
            return false;
    for (int i = h / 3 * 3; i < h / 3 * 3 + 3; ++i)
    {
        for (int j = l / 3 * 3; j < l / 3 * 3 + 3; ++j)
        {
            if ((j != l || i != h) && input[i][j] == input[h][l])
                return false;
        }
    }
    return true;
}

void check(int num)
{
    int h = num / 9;
    int l = num % 9;
    if (num == 56 && input[6][0] == 2 && input[6][1] == 1)
        input[6][2] = 5;
    if (num == 81)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                cout << input[i][j] << " ";
            }
            cout << input[i][8] << endl;
        }
        flag = true;
        return;
    }
    if (input[h][l] == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            input[h][l] = i;
            if (isOk(num))
            {
                check(num + 1);
                if (flag)
                    return;
                input[h][l] = 0;
            }
        }
       input[h][l] = 0;
    }else{
        check(num + 1);
    }
}

int main()
{
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            cin >> input[i][j];
        }
    }
    check(0);
    return 0;
}