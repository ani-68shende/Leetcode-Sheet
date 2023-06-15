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
    int maxLevelSum(TreeNode* root) {
        vector<int>v;
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int maxu = INT_MIN;int depth = 0;int depu = 0;
        while(q.size()){
            int s = q.size();
            vector<int>small;
            int sum = 0;
            for(int i =0 ; i < s ; i++){
                TreeNode* node = q.front();
                q.pop();
                sum+= node->val;
                small.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            depth++;
            if(sum > maxu){
                maxu = sum;
                depu = depth;
            }
        }
        return depu;
    }
};