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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        if(root == NULL){
            return v;
        }
        q.push(root);
        while(q.size()){
            int s = q.size();
            vector<int>small;
            for(int i = 0 ; i < s ; i++){
                TreeNode* node = q.front();
                q.pop();
                small.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            //cout << small.size() << endl;
            for(int i = 0 ; i < small.size() ; i++){
                if(i == small.size()-1)v.push_back(small[i]);
            }
        }
        return v;
    }
};