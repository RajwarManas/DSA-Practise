/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr=headA;
        unordered_set<ListNode*> us;
        while(curr) {
            us.insert(curr);
            curr=curr->next;
        }
        curr=headB;
        while(curr&&us.find(curr)==us.end()) {
            curr=curr->next;
        }
        return curr;
    }
};