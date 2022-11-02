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
    unordered_map<TreeNode*, TreeNode*>mp;
    void fillarray(TreeNode* root){
        TreeNode* temp = root;
        queue<TreeNode* > q;
        q.push(temp);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left]  = node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right]  = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        fillarray(root);
        int depth = 0;
        TreeNode* temp = target;
        queue<TreeNode* > q;
        q.push(temp);
        set<TreeNode* >visited;
        visited.insert(temp);
        while(!q.empty()){
            if(depth == k)break;
            int siz= q.size();
            for(int kk =0 ; kk < siz ; kk+=1){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(mp[node] && !visited.count(mp[node])){
                    q.push(mp[node]);
                    visited.insert(mp[node]);
                }
            }
            depth++;
        }
        vector<int>ans;
        if(depth == k){
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
        }
        return ans;
    }
};