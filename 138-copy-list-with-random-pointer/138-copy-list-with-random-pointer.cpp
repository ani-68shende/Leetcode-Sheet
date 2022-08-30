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
    // mapping bois
    Node* copyRandomList(Node* head) {
        Node* org = head;
        Node* dummy = new Node(-101);
        Node* temp = dummy;
        
        //magzine
        unordered_map<Node*, Node*>mp;
        // emptying the magzine
        while(org){
            Node* newnode = new Node(org->val);
            mp[org] = newnode;
            temp -> next = newnode;
            temp = temp -> next;
            org = org -> next;
        }
        // load the 6x
        org = head;
        temp = dummy->next;
        
        // emptying the magzine
        while(org){
            if(mp[org]!=NULL)
                temp->random = mp[org->random];
            org = org -> next;
            temp = temp -> next;
        }
        return dummy-> next;
    }
};