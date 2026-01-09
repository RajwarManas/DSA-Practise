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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        int count=1;
        ListNode* curr=head;
        while(curr->next) {
            count++;
            curr=curr->next;
        }
        ListNode* last=curr;
        k%=count;
        if(k>0) {
            last->next=head;
            int count2=1;
            curr=head;
            while(count2<count-k) {
                curr=curr->next;
                count2++;
            }
            head=curr->next;
            curr->next=nullptr;
        }
        return head;
    }
};