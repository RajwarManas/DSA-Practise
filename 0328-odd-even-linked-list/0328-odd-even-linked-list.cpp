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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* curr=head;
        ListNode* even=head->next;
        while(curr&&curr->next) {
            ListNode* nxt = curr->next;
            curr->next=curr->next->next;
            curr=nxt;
        }
        curr->next=even;
        return head;
    }
};