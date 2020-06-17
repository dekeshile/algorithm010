/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderVec;
    vector<int> inorderTraversal(TreeNode* root) {
       inorderVec.clear();
       inorderTra(root);  
       return   inorderVec;
    }
    void inorderTra(TreeNode* root) {
        if(root == NULL)
            return;
        inorderTra(root->left);
        inorderVec.push_back(root->val);
        inorderTra(root->right);
    }
};