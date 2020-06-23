class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        /*
            自底向上的交换左右子树
            左右孩子都有，交换左右子树
            只有左孩子，把左孩子变成右孩子
            只有右孩子，把右孩子变成左孩子
        */
        if(root == NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        if(root->left != NULL || root->right !=NULL){
             TreeNode*temp = root->left;
             root->left = root->right;
              root->right =temp;
        }
        else if(root->left != NULL || root->right == NULL){
            root->right = root->left;
            root->left = NULL;
         }
        else if(root->right != NULL || root->left == NULL){
            root->left = root->right;
            root->right = NULL;
         }
         return root;
    }
};