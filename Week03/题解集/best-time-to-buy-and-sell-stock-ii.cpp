class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int resProfit = 0;
        int adjacentProfit = 0;
        int len = prices.size();
        for(int i=1;i<len;i++){              
           adjacentProfit = ( prices[i]-prices[i-1]);
           if( adjacentProfit > 0 )
                resProfit += adjacentProfit;
        }
        return resProfit;
    }
};