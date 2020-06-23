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
 方法一：
 递归，层层往下，不回溯
 LONG_MIN，LONG_MAX定义在头文件 <limits.h>中
 leftmin，rightmax要定义成long型，因为如果有root->val = 1 时，和LONG_MIN比大小时，会
 计算 LONG_MIN -1 ，而这个值约了int的范围导致出错
 方法二：
 二叉搜索树的中序遍历是有序的
 */
 #include <limits.h>
class Solution {
public:
    bool dep(TreeNode* root,long leftmin,long rightmax){
         if(root == NULL)
            return true;
        if(root->val <= leftmin || root->val >= rightmax)
            return false;
        return dep(root->left,leftmin,root->val) &&  dep(root->right,root->val,rightmax);
    }
    bool isValidBST(TreeNode* root) {
        return dep(root,LONG_MIN,LONG_MAX);
    }
};




