/**
 * Question: 235. Lowest Common Ancestor of a Binary Search Tree
 * 
 * Author Yifan Yuan
 * Date 2022-03-17
 * Description: 
 * Given a binary search tree(BST), find the lowest common ancestor (LCA) of two given nodes in the tree. 
 * According to the definition of LCA on Wikipedia: 
 * “The lowest common ancestor is defined between two nodes p and q as the lowest node in T 
 * that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Input:  root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 *              6
 *            /   \
 *           2     8
 *         /  \   /  \
 *        0   4   7   9
 *           / \
 *          3   5
 * Output: 2
 * 
 * Constraints:
 *     The number of nodes in the tree is in the range [2, 105].
 *     -109 <= Node.val <= 109
 *     All Node.val are unique.
 *     p != q
 *     p and q will exist in the BST.
 * 
 * Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return NULL;
    
    if (root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left != NULL && right != NULL) return root;
    
    if (left == NULL && right == NULL) return NULL;
    
    return left != NULL ? left : right;
}