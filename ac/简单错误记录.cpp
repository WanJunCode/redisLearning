#include <iostream>
#include <string.h>
using namespace std;
  
struct memory
{
    char s[100];
    int line;
    int count;
};
int main()
{
    char input[100];
    int line;
    int cnt = 0;
    memory record[1000];
    while(cin>>input>>line)
    {
        char *p = strrchr(input, '\\');
        p++;
        if(strlen(p) > 16)
        {
            p = p + strlen(p) - 16;
        }
        int flag = 0;
          
        for(int i = 0; i < cnt; i++)
        {
            if(strcmp(record[i].s, p) == 0)
            {
                if(record[i].line == line)
                {
                    flag = 1;
                    record[i].count++;
                    break;
                }
            }
                  
        }
        if(!flag)
        {
            strcpy(record[cnt].s, p);
            record[cnt].line  = line;
            record[cnt].count = 1;
            cnt++;
        }      
    }
    int j;
    if(cnt > 8)
        j = cnt - 8;
    else
        j = 0;
    for(;j < cnt; j++)
    {
        cout << record[j].s << ' ' << record[j].line << ' ' << record[j].count << endl;
    }
    return 0;
}