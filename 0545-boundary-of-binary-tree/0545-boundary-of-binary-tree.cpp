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
    vector<int>ans;
    bool is_leaf(TreeNode * node){
        return (!node->left && !node->right);
    }
    void left(TreeNode* root){
        vector<int>left;
        while(root){
            if(root->left){
                while(root->left){
                    left.push_back(root->val);
                    root = root->left;
                }
            }else{
                left.push_back(root->val);
                root = root->right;
            }
        }
        if(left.size()) left.pop_back();
        ans.insert(ans.end(), left.begin(), left.end());
    }
    void right(TreeNode* root){
        vector<int>right;
        while(root){
            if(root->right){
                while(root->right){
                    right.push_back(root->val);
                    root = root->right;
                }
            }else{
                right.push_back(root->val);
                root = root->left;
            }
        }
        if(right.size()) right.pop_back();
        reverse(right.begin(),right.end());
        ans.insert(ans.end(), right.begin(), right.end());
    }
    void leaves(TreeNode* root){
        if(!root)return ;
        leaves(root->left);
        if(is_leaf(root))ans.push_back(root->val);
        leaves(root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root->left || root->right)
        ans.push_back(root->val);
        left(root->left);
        // for(auto x: ans)cout << x << " ";
        // cout << endl;
        leaves(root);
        // for(auto x: ans)cout << x << " ";
        // cout << endl;
        right(root->right);
        // for(auto x: ans)cout << x << " ";
        // cout << endl;
        return ans;
    }
};