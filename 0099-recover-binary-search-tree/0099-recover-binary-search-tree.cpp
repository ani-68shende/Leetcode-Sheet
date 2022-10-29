//idk how this qn was left out
class Solution {
    private:
        TreeNode* first, *middle, *last, *prev;
public:
    void inorder(TreeNode* root){
        if(!root)return ;
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(!first){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first and last)swap(first->val, last->val);
        else if(first and middle)swap(first->val, middle->val);
    }
};