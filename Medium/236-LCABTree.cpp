/**
 * Question: 236. Lowest Common Ancestor of a Binary Tree
 * 
 * Author Yifan Yuan
 * Date 2022-03-15
 * Description: 
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. 
 * According to the definition of LCA on Wikipedia: 
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
 * that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Input:  root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 *              3
 *            /   \
 *           5     1
 *         /  \   /  \
 *        6   2   0   8
 *           / \
 *          7   4
 * Output: 3
 * 
 * Constraints:
 *     The number of nodes in the tree is in the range [2, 105].
 *     -109 <= Node.val <= 109
 *     All Node.val are unique.
 *     p != q
 *     p and q will exist in the tree.
 * 
 * Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

// Recursion
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    
    if (root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left != NULL && right != NULL) return root;
    
    if (left == NULL && right == NULL) return NULL;
    
    return left != NULL ? left : right;
}