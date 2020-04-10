#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
  
void get_type(int *type, char *card)
{
    if (strlen(card)!=5)
        {*type=(strlen(card)+1)/2;}
    else if (card[0]=='j'||card[0]=='J')
        {*type=1;}
    else if (card[0]=='1')
        {*type=2;}
    else {*type=3;}
}
  
bool a_dayu_b(char a, char b)
{
    char order[]={'3','4','5','6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A', '2'};
    int i=strlen(order)-1;
    while (true)
    {
        if (order[i]==a)
        {return true;}
        if (order[i]==b)
        {return false;}
        --i;
    }
}
  
  
int main()
{
    char str[100], card1[50];
    char card2[50];
    int type[2];
    int i,j;
  
    while (cin.getline(str,100))
    {
        for (i=0;str[i]!='-';++i)
            card1[i]=str[i];
        card1[i]='\0';
        ++i;
        j=i;
        for  (;i<strlen(str);++i){
            card2[i-j]=str[i];
        }
        card2[i-j]='\0';
        
        get_type(type,card1);
        get_type(type+1,card2);
    
        if (max(type[0],type[1])==6)
        {
            if (type[0]==6)
                cout<<card1<<endl;
            else      
                cout<<card2<<endl;
            continue;
        }
        if (type[0]==4||type[1]==4)
        {
            if (type[0]==4&&type[1]==4)
            {
                if (a_dayu_b(card1[0],card2[0]))
                    cout<<card1<<endl;
                else
                    cout<<card2<<endl;
            }
            else if (type[0]==4) 
                cout<<card1<<endl;
            else 
                cout<<card2<<endl;
            continue;
        }
    
        if (type[0]!=type[1]){
            cout<<"ERROR"<<endl; 
            continue;
        }
            
        if ((strlen(card1)!=strlen(card2))&& ((card1[0]=='j')||(card1[1]=='j')||(card1[0]=='J')||(card1[1]=='J')))
        {
            if (strlen(card1)>strlen(card2))
                cout<<card1<<endl;
            else
                cout<<card2<<endl;
        }
        else
        {
            if (a_dayu_b(card1[0],card2[0]))
                cout<<card1<<endl;
            else
                cout<<card2<<endl;    
        }

    }
    return 0;
}