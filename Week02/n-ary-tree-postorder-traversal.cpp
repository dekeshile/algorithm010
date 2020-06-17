/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> Vec;
    vector<int> postorder(Node* root) {
       Vec.clear();
       postTra(root);  
       return  Vec;
    }
     void postTra(Node* root) {
        if(root == NULL)
            return;
        for(int i=0;i<root->children.size();i++){
             postTra(root->children[i]);
        }
        Vec.push_back(root->val);
    }
};