#include<map>
#include<iterator>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       //map的第一个元素代表数值，第二个元素代表其在数组中的下标
       map<int,int> mymap;
       vector<int> res;
       for(int i=0;i<nums.size();i++){
            int pair_num  =  target - nums[i];
            if(mymap.find(pair_num) != mymap.end()){
                res.push_back(mymap[pair_num]);
                res.push_back(i);
                return res;
            }
            mymap[nums[i]] = i;
        }
        return res;
    }
};