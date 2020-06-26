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
	void findNode(TreeNode* root, TreeNode* p,vector<TreeNode*>& trase,vector<TreeNode*>& res){
        if(root == NULL)
			return;

    	if(root->val == p->val){
            res = trase;
            return;
        }

		trase.push_back(root->left);
		findNode(root->left,p,trase,res);
		trase.pop_back();

		trase.push_back(root->right);
		findNode(root->right,p,trase,res);
		trase.pop_back();
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
		vector<TreeNode*> trasep,traseq,resp,resq;
        findNode(root,p,trasep,resp); 
		findNode(root,q,traseq,resq); 
       //将root插入到第一个位置
        resp.insert(resp.begin(),root);
        resq.insert(resq.begin(),root);
		int i=0,j=0;
        while(i<resp.size() && j < resq.size()){
            if( resp[i]->val != resq[j]->val)
                break;
             i++;j++;
        };
    	return  resp[--i];
    }
};