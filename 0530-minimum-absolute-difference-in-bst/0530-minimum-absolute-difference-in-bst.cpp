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
    int getMinimumDifference(TreeNode* root) {
        vector<int>v;
    if(root==NULL)
        return 0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node->val);
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
    }
        int mini = INT_MAX;
        for(int i = 0 ; i < v.size() ; i++){
            for(int j = i+1 ; j < v.size() ; j++){
                mini = min(mini,abs(v[i]-v[j]));
            }
        }
        return mini;
    }
};