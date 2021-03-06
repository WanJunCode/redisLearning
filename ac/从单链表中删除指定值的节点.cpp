#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int  val;
    ListNode* next;
};

int main(){
    int n,head_value;
    while(cin>>n>>head_value){
        ListNode *p,*q,*head=new ListNode;
        head->val=head_value;
        head->next=NULL;
        q=head;
        // x 是要插入的数值，y表示x插入到y后面
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            p=new ListNode;
            p->val=x;
            p->next=NULL;
            while(q){
                if(q->val==y){
                    p->next=q->next;
                    q->next=p;
                    break;
                }else
                    q=q->next;
            }
            q=head;
        }
        // 输入需要删除的数值
        int denum;
        cin>>denum;
        q=head;
        while(q){
            if(q->val==denum){
                if(q==head){
                    head=q->next;
                    delete q;
                }else{
                    p->next=q->next;
                    delete q;
                }
                break;
            }else{
                 p=q;
                 q=q->next;
            } 
        }
        q=head;
        while(q){
            cout<<q->val<<' ';
            q=q->next;
        }
        cout<<endl;
    }
    return 0;
}