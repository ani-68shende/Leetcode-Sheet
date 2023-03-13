/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null)
        {
            return true;
        }
        return isSymmetric1(root.left, root.right);
        
    }
    public boolean isSymmetric1(TreeNode l,TreeNode r)
    {
        if(l == null && r == null)
        {
            return true;
        }
        else if(l == null || r == null)
        {
            return false;
        }
        if(l.val == r.val) 
            return isSymmetric1(l.left,r.right) && isSymmetric1(l.right,r.left);
        else
        return false;
    }
};