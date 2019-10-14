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

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
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
