#include <iostream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;
 
int main()
{
    int ip[2][4];
    int net[2][4];
    int mask[4];

    while(scanf("%d.%d.%d.%d",&mask[0],&mask[1],&mask[2],&mask[3])!=EOF&&
    scanf("%d.%d.%d.%d",&ip[0][0],&ip[0][1],&ip[0][2],&ip[0][3])!=EOF&&
    scanf("%d.%d.%d.%d",&ip[1][0],&ip[1][1],&ip[1][2],&ip[1][3])!=EOF)
    {
        for(int i=0;i<4;i++)
        {
            if((ip[0][i]>=0&&ip[0][i]<256)&&(ip[1][i]>=0&&ip[1][i]<256)&&(mask[i]>=0&&mask[i]<256))
            {
                net[0][i]=ip[0][i]&mask[i];
                net[1][i]=ip[1][i]&mask[i];
            }else{
                printf("%d\n",1);
                return -1;
            }
        }
        if(net[0][0]==net[1][0]&&net[0][1]==net[1][1]&&net[0][2]==net[1][2]&&net[0][3]==net[1][3])
            printf("%d\n",0);
        else
            printf("%d\n",2);
    }

    return 0;
}