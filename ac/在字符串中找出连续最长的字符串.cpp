#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main ()
{
    string str;
    while (getline (cin, str))
    {
        vector <string> array;
        string temp;
       
        for (int i = 0; i <= str.size(); ++i){
            if (str[i] >= '0' && str[i] <= '9')
                temp += str[i];
            else
                {
                if (temp.length() != 0)
                    array.push_back(temp);
                 temp.clear();
                }
        }
        int max = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            if (max < (array[i]).size())
                max = (array[i]).size();
        }
         
          for (int i = 0; i < array.size(); ++i)
        {
            if (max == (array[i]).size())
                cout << array[i];
        }
        cout << ',' << max  << endl;
    }
    return 0;
}