#include<map>
#include<utility>
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int mycash5 = 0;
        int mycash10 = 0;
        int mycash20 = 0;
        int billsLen = bills.size();
        for( int i = 0; i < billsLen ; i++) {
            if ( bills[i] == 5){
                 mycash5++; 
            }else if(bills[i] == 10 ){
                if( mycash5 == 0)
                    return false;
                else{
                    mycash5--;
                    mycash10++;
                }
            }else{
                if( mycash10 != 0 && mycash5 != 0) {//至少一张10元和一张5元
                    mycash10--;
                    mycash5--;
                }else if (mycash5 > 2 ) {//至少有3张5元
                    mycash5 -= 3;
                }else
                    return false;
                mycash20++;
            }
        }
        return true;
    }
};