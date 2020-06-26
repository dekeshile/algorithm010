/*
开始假设输出子集为空，每一步都向子集添加新的整数，并生成新的子集。
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subSet;
        res.push_back({});
        // i是遍历原始数组的下标
        for(int i=0;i<nums.size();i++){
            //遍历现在已经有的所有子集，向所有子集中添加新的整数
            int subSetNums = res.size();
            for(int j=0;j<subSetNums;j++){
                subSet = res[j];
                subSet.push_back({nums[i]});
                res.push_back(subSet);
            }
        }
        return res;
    }
};