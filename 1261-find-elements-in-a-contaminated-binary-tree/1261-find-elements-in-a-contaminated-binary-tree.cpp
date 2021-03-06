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
class FindElements {
public:
    
    /*
    use simple preorder dont think too much and do what you shall do
    */
    
    
    
    
    unordered_map<int, int>m;
    void changer(TreeNode* root, int value){
        if(!root){
            return;
        }
        root->val = value;
        m[value]++;
        changer(root->left, 2*value+1);
        changer(root->right, 2*value+2);
    }
    FindElements(TreeNode* root) {
        changer(root, 0);
    }
    
    bool find(int target) {
        return m.find(target) != m.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */