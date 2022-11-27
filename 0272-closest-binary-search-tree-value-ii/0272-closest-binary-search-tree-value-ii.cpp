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
    priority_queue<pair<double, double>,vector<pair<double, double>>, greater<pair<double, double>>>q;
    double t;
    void trav(TreeNode* root){
        if(root==NULL)return ;
        q.push({abs(root->val-t), root->val});
        trav(root->left);
        trav(root->right);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        t = target;
        trav(root);
        vector<int>ans;
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};