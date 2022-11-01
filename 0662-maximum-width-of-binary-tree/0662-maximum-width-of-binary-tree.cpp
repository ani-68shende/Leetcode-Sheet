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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long max_diam = 0;
        if(!root)return max_diam;
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root, 0});
        while(q.size()){
            int siz = q.size();
            unsigned long long prev = q.front().second, start, end;
            for(int i = 0 ; i < siz ; i++){
                TreeNode* ndoe = q.front().first;
                unsigned long long val = q.front().second-prev;
                q.pop();
                if(i ==0 ){
                    start = val;
                }
                if(i == siz-1){
                    end = val;
                }
                if(ndoe->left){
                    q.push({ndoe->left,val*2+1});
                }
                if(ndoe->right){
                    q.push({ndoe->right,val*2+2});
                }
            }
            max_diam = max(max_diam, end-start+1);
        }
        return max_diam;
    }  
};