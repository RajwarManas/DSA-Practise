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
    ListNode* prevMid(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right) {
        ListNode dummy(-1);
        ListNode* temp =&dummy;
        while(left&&right) {
            if(left->val<=right->val) {
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else {
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        while(left) {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right) {
            temp->next=right;
            temp=right;
            right=right->next;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* middle=prevMid(head);
        ListNode* right=middle->next;
        middle->next=nullptr;
        ListNode* left=head;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};