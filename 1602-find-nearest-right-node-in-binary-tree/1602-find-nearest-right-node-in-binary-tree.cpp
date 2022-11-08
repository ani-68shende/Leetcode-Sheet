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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            int flag = 0;
            for(int i = 0 ; i < siz ; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(flag == 1){
                    return temp;
                }
                if(temp == u){
                    flag = 1;
                }
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return nullptr;
    }
};