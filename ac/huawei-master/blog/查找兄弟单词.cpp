#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int judge(string findString,string v) 
{ 
    sort(findString.begin(),findString.end()); 
    sort(v.begin(),v.end()); 
    if(findString==v) 
        return 1; 
    else 
        return 0; 
} 

int main() 
{ 
    int n,i,index; 
    vector<string> words;       // 存储所有的单词
    vector<string> bother; 
    string findWord; 
    string temp; 
    while((cin>>n)!=0) 
    { 
        words.clear();
        bother.clear();
        for(i=0; i<n; i++)
        {
            cin>>temp;
            words.push_back(temp);
        }

        // 获得需要查找的单词，输出查找到的bro单词的第index个
        cin>>findWord; 
        cin>>index; 
   
        for(i=0; i<n; i++) 
        { 
            if(findWord!=words[i] && judge(findWord,words[i])) 
            { 
                bother.push_back(words[i]); 
            } 
        }
        
        sort(bother.begin(),bother.end()); 
        cout<<bother.size()<<endl; 
        if(index<=bother.size()) 
            cout<<bother[index-1]<<endl; 
    } 
    return 0; 
} 