/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return nullptr ;
        if(!l1) return l2;
        if(!l2) return l1;
        int carry=0;
        ListNode* res = new ListNode(0);
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* curr3=res;
        while(curr1||curr2) {
            int sum=0;
            if(curr1) sum+=curr1->val;
            if(curr2) sum+=curr2->val;
            sum+=carry;
            if(sum/10==1) carry=1;
            else carry=0;
            sum%=10;
            ListNode* temp= new ListNode(sum);
            curr3->next=temp;
            curr3=curr3->next;
            if(curr1) curr1=curr1->next;
            if(curr2) curr2=curr2->next;
        }
        if(carry==1) {
            ListNode* temp = new ListNode(1);
            curr3->next=temp;
        }
        return res->next;
    }
};