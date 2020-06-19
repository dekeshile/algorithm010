#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> resVec;
        queue<Node*> myqueue;
        vector<int> layerVec;
        if(root == NULL)
            return resVec;
        myqueue.push(root);
        Node* ele;
        while(!myqueue.empty()){
            vector<int> layerVec;
            for(int layerNums=myqueue.size();0<layerNums;layerNums--){
                ele = myqueue.front();
                for(int i=0;i<ele->children.size();i++){
                    myqueue.push(ele->children[i]);
                 }
                layerVec.push_back(ele->val);
                myqueue.pop();
            }
            resVec.push_back(layerVec);
        }  
        return resVec;
    }
};