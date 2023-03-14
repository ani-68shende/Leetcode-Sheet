class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        sum=0;
        DFS(root, 0);
        return sum;
    }
    
    void DFS(TreeNode *&node, int currentSum)
    {
        currentSum=currentSum*10+node->val;
        if(!node->left&&!node->right)
            sum+=currentSum;
        if(node->left)
            DFS(node->left, currentSum);
        if(node->right)
            DFS(node->right, currentSum);
    }
private:
    int sum;
};