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
    vector<ListNode*> revk(ListNode* head,ListNode* tail) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode*stop=tail->next;
        while(curr&&curr!=stop) {
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return {prev,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode dummy(0,head);
        ListNode* start=head;
        ListNode* prevTail=&dummy;
        while(start) {
            ListNode* end=start;
            for(int i=1;i<k;i++) {
                end=end->next;
                if(!end) break;
            }
            if(!end) break;
            ListNode* nextBlock = end->next;
            std::vector<ListNode*> vec1 = revk(start,end);
            ListNode* newHead=vec1[0];
            ListNode* newTail=vec1[1];
            prevTail->next=newHead;
            newTail->next=nextBlock;
            prevTail=newTail;
            start=nextBlock;
        }
        return dummy.next;
    }
};