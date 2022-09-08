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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>ret = new ArrayList<>();
        inorderTraversal1(root,ret);
        return ret;
    }
    private List<Integer> inorderTraversal1(TreeNode root, List<Integer>ret)
    {
        if(root!=null)
        {
            inorderTraversal1(root.left,ret);
            ret.add(root.val);
            inorderTraversal1(root.right,ret);
        }
        return ret;
    }
}