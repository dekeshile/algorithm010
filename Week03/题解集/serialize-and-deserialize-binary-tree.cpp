/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<string>
class Codec {
public:
    string serialize(TreeNode* root) {
        string ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())//这个步骤和先序是u一样
        {
            TreeNode* p = s.top();
            s.pop();
            if(p) {
                    s.push(p->right);
                   s.push(p->left);
                  ret += to_string(p->val) + ",";
                  }
            else
                ret += "n,";
        }
        ret.erase(ret.end()-1);//把尾巴上多的一个逗号去掉
        return ret;
    }
    TreeNode*  desDep(vector<string>& treeVec,int& pos){
        if( treeVec[pos] == "n"){
            pos++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(treeVec[pos]));
        pos++;
        root->left = desDep(treeVec,pos);
        root->right = desDep(treeVec,pos);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> treeVec;
        stringstream ss;
        ss << data;
        string temp;
        while(getline(ss, temp, ','))
        {
            treeVec.push_back(temp);//和python里的split一个功能
        }
        int pos = 0;
        return desDep(treeVec,pos);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));