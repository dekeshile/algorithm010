/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
本题要注意，结点若其中一颗子树为空，则结点的最小深度并不是1，而是非空的那颗子树的最小深度
 */
#include<algorithm>
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL  && root->right != NULL)
             return minDepth(root->right) + 1;
        if(root->right == NULL   && root->left != NULL)
             return minDepth(root->left) + 1;
        return min( minDepth(root->left), minDepth(root->right) ) +1;
    }
};