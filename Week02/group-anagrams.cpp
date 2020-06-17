#include<map>
#include<iterator>
#include<algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mymap;
        vector<vector<string>> myvec;
        map<string,vector<string>>::iterator it;
        string tempStr;
        for(int i=0;i<strs.size();i++){
            vector<string> temp;
            tempStr = strs[i];
            sort(tempStr.begin(),tempStr.end());
            it = mymap.find(tempStr);
            if(it!=mymap.end()){
                temp = it->second;
            }
            temp.push_back(strs[i]);
            mymap[tempStr] = temp;
        }
        for(it = mymap.begin();it!=mymap.end();it++){
            myvec.push_back(it->second);
        }
        return myvec;
    }
};