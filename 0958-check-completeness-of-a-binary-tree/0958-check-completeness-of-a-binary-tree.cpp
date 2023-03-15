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
    bool isCompleteTree(TreeNode* root) {
        vector<vector<int>>finala;
        queue<TreeNode*>q;
        q.push(root);
        int ht = 0;
        while(q.empty() == false){
            int siz = q.size();
            vector<int>ans;
            for(int i = 0 ; i < siz ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node)
                    ans.push_back(node->val);
                else{
                    ans.push_back(-1);
                    continue;
                }
                if(node->left)q.push(node->left);
                else q.push(NULL);
                if(node->right)q.push(node->right);
                else q.push(NULL);
            }
            finala.push_back(ans);
            ht++;
        }
        int u = finala.size(), i(0);
        while(i<finala[u-1].size() && finala[u-1][i] == -1){
            i++;
        }
        if(i == pow(2,ht-1)){cout << "dang";return true;}
        for(int i = 0 ; i < finala.size()-2 ; i++){
            for(auto x : finala[i]){
                // cout << x << " ";
                if(x == -1){
                    return false;
                }
            }
            // cout << "\n";
        }
        i = 0;
        u--;
        for(i = 0 ; i < finala[u-1].size() ; i++){
            if(finala[u-1][i] == -1){
                while(i<finala[u-1].size() && finala[u-1][i] == -1){
                    i++;
                }
                break;
            }
        }
        // cout << i << "\n";
        return i == finala[u-1].size();
    }
};