#include<iostream>

using namespace std;
 
int main()
{
    int num,index,value;
    int db[1000] = {0};

    cin >> num;
     
    for(int i = 1;i <= num;i++)
    {
        cin >> index >> value;
        db[index] += value;
    }

    for(int i = 0;i < 1000;i++)
    {
        if(db[i])
            cout << i << " " << db[i] << endl;
    }

    return 0;
}