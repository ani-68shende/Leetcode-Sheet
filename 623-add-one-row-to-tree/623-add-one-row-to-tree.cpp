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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        d -= 1;
        if(d == 0){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        d--;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                TreeNode* cur = q.front();q.pop();
                if(d != 0){
                    if(cur->left)q.push(cur->left);
                    if(cur->right)q.push(cur->right);
                }else{
                    TreeNode* l = new TreeNode(val);
                    TreeNode* r = new TreeNode(val);
                    l->left = cur->left;
                    cur->left = l;
                    r->right=cur->right;
                    cur->right=r;
                }
            }
            d--;
        }
        return root;
    }
};