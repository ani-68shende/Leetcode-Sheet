/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* headA, Node * headB) {
        Node *a = headA;
        Node *b = headB;
        while(a!=b){
            a = a == NULL ? headB : a->parent;
            b = b == NULL ? headA : b->parent;
        }
        return a; 
    }
};