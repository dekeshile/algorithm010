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
      3
   /    \
  9     20
 / \    / \
6   8  15  7  

 */
 #include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root != NULL)
            que.push(root);
        while(!que.empty()){
            vector<int> layer;
        /*此处不可以为 for(int i=0;i<que.size();i++) 
        因为这样que.size()会随着上次循环的push操作而动态变化*/
            for(int i=que.size();0<i;i--){
                TreeNode* top = que.front();
                que.pop();
                if(top->left != NULL)
                    que.push(top->left);
                if(top->right != NULL)
                    que.push(top->right);
                layer.push_back(top->val);
            }
            res.push_back(layer);
        }
        return res;
    }
};