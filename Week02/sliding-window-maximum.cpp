//注意保留上一次的最大和最新一次窗口进来的那个元素做比较即可
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> res;
         if(k > nums.size())
            return res;
        int max = getMax(nums,0,k-1);
        res.push_back(max);
        for(int i=1;i<nums.size()&&i+k<=nums.size();i++){
            //判断这个max是不是窗口滑动掉的元素，是的话就要调用getMax了
            max = ( max == nums[i-1] ? getMax(nums,i,i+k-1) : 
                         ( nums[i+k-1] > max ?  nums[i+k-1] : max) 
                     ) ;
           res.push_back(max);
        }
        return res;
    }
    #在区间 [left,right]里找最大值 O(n)
    int getMax(vector<int>& nums,int left,int right){
        int max = nums[left];
        for(int i=left;i<=right;i++){
            max = nums[i] > max ? nums[i]:max;
        }
        return max;
    }
};