/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> treeQueue;
        vector<int> res;
        if(root == NULL)
            return res;
        treeQueue.push(root);
        while(!treeQueue.empty()) {
            int maxVal = INT_MIN;//每一层都要重置maxVal
            for(int i = treeQueue.size();i > 0;i--) {
                TreeNode* top = treeQueue.front();
                treeQueue.pop();
                if( top->left )
                    treeQueue.push(top->left);
                if( top->right )
                    treeQueue.push(top->right);
                maxVal = top->val > maxVal ? top->val : maxVal;
            }
            res.push_back(maxVal);
        }
        return res;
    }
};