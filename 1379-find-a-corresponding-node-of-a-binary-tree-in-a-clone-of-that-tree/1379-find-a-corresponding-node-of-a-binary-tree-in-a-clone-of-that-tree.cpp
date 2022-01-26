/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* root, TreeNode* target) {
    vector<int>v;
    if(root==NULL)
        return NULL;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int s = q.size();
        vector<TreeNode*>small;
        for(int i = 0 ; i < s ; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node;
            int va = temp->val;
            small.push_back(temp);
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        int n1 = small.size();
        for(int i = 0 ; i < n1 ; i++)
        {
            if(small[i]->val == target->val){
                return small[i];
            }
        }
    }
    return NULL;
    }
};