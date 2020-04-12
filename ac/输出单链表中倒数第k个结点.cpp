#include <iostream>
#include <string> 
using namespace std;

struct ListNode
{
    int key;
    ListNode *next;
};

// 释放内存
void ClearList(ListNode *L)
{
    ListNode *p,*q;
    p=L->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}

int main()
{
    int n,x;
    while(cin>>n)
    {
        ListNode *p,*q,*rear=new ListNode;
        cin>>x;
        rear->key=x;
        rear->next=NULL;
        q=rear;

        int i;
        for(i=0;i<n-1;i++)
        {
            cin>>x;
            p=new ListNode;
            p->key=x;
            //尾插法
            q->next=p;
            q=p;
        }
        q->next=NULL;

        int k;
        cin>>k;
        q=rear;
        if(k==0){
            cout<<0<<endl;
        }
        else{
            for(i=0;i<n-k;i++)
            {
                q=q->next;
            }
            cout<<q->key<<endl;
        }
        // 清除内存
        ClearList(rear);
    }
    return 0;
}