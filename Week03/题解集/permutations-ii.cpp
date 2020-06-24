/*
           1                         1                             2
  1        1       2      |   1      1        2       |     1      1       2
1 1 2    1 1 2   1 1 2      1 1 2   1 1 2     1 1 2       1 1 2   1 1 2    1 1 2

*/

#include<algorithm>
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;//标记原始数组中已经被使用的位置
    vector<int> orgNums;
    vector<int> solOne;
    int orgLen;

    void dep(){
        if(solOne.size() == orgLen ){
            res.push_back(solOne);
            return;
        }
        for(int i=0;i<orgLen;i++){
            if(!used[i]){
            /*
              !used[i-1] 代表本层orgNums循环，并且orgNums中排在自己前面一个数字已经被清空使用标记
              必须要判断要有!used[i-1] 才能保证是去重同一层的，而不是误去充了不同层不同位置相同的数
            */
                if(i>0 && orgNums[i] == orgNums[i-1] && !used[i-1])
                    continue;
                solOne.push_back(orgNums[i]);
                used[i] = true;
                dep();
                //撤销选择，回退
                used[i] = false;
                solOne.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        orgNums = nums;
        sort(orgNums.begin(),orgNums.end());
        orgLen = nums.size();
        for(int i=0;i<orgLen;i++)
            used.push_back(false);
        dep();
        return res;
    }
};