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
    vector<int> preorder(Node* root) {
       Vec.clear();
       preTra(root);  
       return  Vec;
    }
     void preTra(Node* root) {
        if(root == NULL)
            return;
        Vec.push_back(root->val);            
        for(int i=0;i<root->children.size();i++){
             preTra(root->children[i]);
        }
    }
};