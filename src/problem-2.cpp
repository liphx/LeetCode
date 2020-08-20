/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t=new ListNode(0);
        ListNode *re=t;
        int k=0;
        while(l1!=nullptr && l2!=nullptr){
            ListNode *p=new ListNode((l1->val+l2->val+k)%10);
            k=(l1->val+l2->val+k)/10;
            t->next=p;
            t=t->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr){
            ListNode *p=new ListNode((l1->val+k)%10);
            k=(l1->val+k)/10;
            t->next=p;
            t=t->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
            ListNode *p=new ListNode((l2->val+k)%10);
            k=(l2->val+k)/10;
            t->next=p;
            t=t->next;
            l2=l2->next;
        }
        if(k>0){
            ListNode *p=new ListNode(k);
            t->next=p;
        }
        return re->next;
    }
};

int main()
{
    ListNode *l1, *l2;
    ListNode L[6]{2, 4, 3, 5, 6, 4};
    l1 = &L[0], l2 = &L[3];
    L[0].next = &L[1];
    L[1].next = &L[2];
    L[3].next = &L[4];
    L[4].next = &L[5];
    
    ListNode *ans = Solution().addTwoNumbers(l1, l2);
    while( ans!=NULL ){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    //7 0 8
    return 0;
}
