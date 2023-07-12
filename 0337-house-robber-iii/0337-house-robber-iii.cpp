class Solution {
private:
    map<TreeNode*, int>mp;
    int z(TreeNode* root) {
        if (!root) return 0;
        int take = root->val;
        if(mp.count(root))return mp[root];
        if(root->left){
            if((root->left->left)){
                take += z(root->left->left);
            }
            if((root->left->right)){
                take += z(root->left->right);
            }
        }
        if(root-> right){
            if((root->right->left)){
                take += z(root->right->left);
            }
            if((root->right->right)){
                take += z(root->right->right);
            }
        }
        int nottake = z(root->right) + z(root->left);
        return mp[root]=max(take, nottake);
    }
public:
    int rob(TreeNode* root) {
        return z(root);
    }
};