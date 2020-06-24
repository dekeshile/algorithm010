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
	vector<int> mypreorder,myinorder;
	vector<int>::iterator it;

	TreeNode*  dep(int preleft,int preright,int inleft,int inright){
		if(preleft > preright  || inleft > inright)
			return NULL;
		TreeNode* root = new TreeNode();
		root->val = mypreorder[preleft];
		it = find(myinorder.begin(),myinorder.end(),root->val);
        int index=&*it-&myinorder[0];
	//	int leftRootNum = index -inleft;
		root->left = dep(preleft+1,preleft+(index -inleft),inleft,index-1);
		root->right = dep(preleft+(index -inleft)+1,preright,index+1,inright);
		return root;
	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		mypreorder = preorder;
		myinorder = inorder;
        return dep(0,mypreorder.size()-1,0,myinorder.size()-1);
    }
};