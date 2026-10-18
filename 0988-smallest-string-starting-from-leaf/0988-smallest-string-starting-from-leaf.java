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

    void traverse(TreeNode root,String str,List<String> list){
        if(root==null) return;
        if(root.left==null && root.right==null){
            str = str + (char)(root.val+97);
            StringBuilder s = new StringBuilder(str);
            s.reverse();
            String ss = s.toString();
            list.add(ss);
            return;
        }
        traverse(root.left,str+(char)(root.val+97),list);
        traverse(root.right,str+(char)(root.val+97),list);
    }

    public String smallestFromLeaf(TreeNode root) {
        List<String> list = new ArrayList<>();
        traverse(root,"",list);
        Collections.sort(list);
        return list.get(0);
    }
}