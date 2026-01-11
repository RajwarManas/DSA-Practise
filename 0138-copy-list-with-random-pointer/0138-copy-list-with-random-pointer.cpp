/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> um;
        Node* curr=head;
        while(curr) {
            um[curr]= new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr) {
            um[curr]->next=curr->next?um[curr->next]:nullptr;
            um[curr]->random=curr->random?um[curr->random]:nullptr;
            curr=curr->next;
        }
        return um[head];
    }
};