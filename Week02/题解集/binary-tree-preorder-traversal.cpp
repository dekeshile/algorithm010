class Solution {
public:
    vector<int>  preorderVec;
    vector<int> preorderTraversal(TreeNode* root) {
        preorderVec.clear();
        preorderTra(root);  
       return    preorderVec;
    }
    void  preorderTra(TreeNode* root) {
        if(root == NULL)
            return;
         preorderVec.push_back(root->val);
         preorderTra(root->left);
         preorderTra(root->right);
    }
};