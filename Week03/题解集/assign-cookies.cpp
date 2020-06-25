#include<algorithm>
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int glen = g.size();
        int slen = s.size();
        int i=0,j=0,num = 0;
        while( i<glen && j<slen ){
            if( g[i] <= s [j]){
                i++;j++;num++;
            }
            else
                j++;
        }
        return num;
    }
};