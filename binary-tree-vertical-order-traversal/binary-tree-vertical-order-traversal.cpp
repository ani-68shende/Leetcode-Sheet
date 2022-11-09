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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>finala;
        if(!root)return finala;
        map<int, vector<int>>mp;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(q.empty() == false){
            int siz = q.size();
            vector<int>ans;
            for(int i = 0 ; i < siz ; i++){
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();
                mp[level].push_back(node->val);
                if(node->left)q.push({node->left,level-1});
                if(node->right)q.push({node->right,level+1});
            }
        }
        for(auto x : mp){
            vector<int>vec;
            for(auto y : x.second)
                vec.push_back(y);
            finala.push_back(vec);
        }
        return finala;
    }
};