/*
 用位置下标来判断
 nums[N] = {....,nums[x],...,nums[y]....,nums[last]}
 若位置x想要能到达位置y，则必须有 x + nums[x] >= y
 如 nums[5] = {2,3,1,1,4}, 位置11最远可达位置为 1+3 =4
 即判断遍历完数组后是否存有元素的最远可达下标能大于等于最后一个元素的位置下标
 所以要判断是否到达最有一个位置last,则前面必然存在某个位置x,有x + nums[x] >= last
 而要到达位置x，前面也必然存在位置a,有 a+nums[a] >= x
 前面是反推，现在从正推来看 从第一个位置0开始，看其能否到达第位置0，又从位置0判断能否到达位置1，.....
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if( i > max)
                return false;
            if( i + nums[i] > max)
                max = i + nums[i];
        }
        return true;
    }
};