/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ind = 0;
    TreeNode* helper(string &trav, int depth){
        if(ind == trav.size())return NULL;
        int stat = ind;
        int d = 0; 
        string to_be_converted_to_number;
        while(ind < trav.size() && trav[ind] == '-'){
            d++;
            ind++;
        }
        if(depth != d){
            ind = stat;
            return NULL;
        }
        while(ind < trav.size() && trav[ind] != '-'){
            to_be_converted_to_number += trav[ind];
            ind++;
        }
        int actual_number = stoi(to_be_converted_to_number);
        TreeNode* root = new TreeNode(actual_number);
        root->left = helper(trav, depth+1);
        root->right = helper(trav, depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string trav) {
        return helper(trav, 0);
    }
};