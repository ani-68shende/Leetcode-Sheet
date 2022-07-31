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
    // postStart is from end
    TreeNode* helper_boi(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp){
        if(postStart > postEnd || inStart > inEnd)return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int in_root = mp[postorder[postEnd]];
        
        int numsleft = in_root - inStart;
        
        
        root -> left = helper_boi(postorder, postStart, postStart + numsleft-1, inorder,  inStart, in_root-1, mp);
        
        root->right = helper_boi(postorder, postStart + numsleft, postEnd-1, inorder, in_root+1, inEnd, mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>mp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        return helper_boi(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};