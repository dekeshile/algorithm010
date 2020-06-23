#include<map>
#include<string>
class Solution {
public:
    map<char,string> numMap;
    vector<string>  res;
    string ori_digits;
    int digits_len;

    void dep(string cur,int index){
        if(index == digits_len){
            res.push_back(cur);
            return;
        }
        char map_index =  ori_digits[index];
        int bra_len = numMap[map_index].length();
        for(int i=0;i<bra_len;i++){
            string acc =  cur + numMap[map_index][i];
            dep(acc,index+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        ori_digits = digits;
        digits_len = digits.length();
        if(digits_len == 0)
            return res;
        numMap['2']="abc";
        numMap['3']="def";
        numMap['4']="ghi";
        numMap['5']="jkl";
        numMap['6']="mno";
        numMap['7']="pqrs";
        numMap['8']="tuv";
        numMap['9']="wxyz";
        dep("",0);
        return res;
    }
};