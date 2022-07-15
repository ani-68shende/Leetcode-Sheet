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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_map<int, int>isChild;
        for(auto x : descriptions){
            int par = x[0];
            int child = x[1];
            if(mp.find(par)==mp.end()){
                TreeNode* parent = new TreeNode(par);
                mp[par] = parent;
            }
            if(mp.find(child)== mp.end()){
                TreeNode* ch = new TreeNode(child);
                mp[child] = ch;
            }
            if(x[2] == 1) mp[par]->left = mp[child];
            else mp[par]->right= mp[child];
            isChild[child] = true;
        }
        TreeNode* root;
        for(auto x : descriptions){
            if(!isChild[x[0]]){
                root = mp[x[0]];
            }
        }
        return root;
    }
};