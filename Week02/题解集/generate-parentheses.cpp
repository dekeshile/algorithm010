/*
在序列仍然保持有效时才添加 '(' or ')'
如果左括号数量不大于 n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。
*/
class Solution {

    void generate_all(string& current,int leftNums, int rightNums,int n, vector<string>& result) {
        if (n*2 == current.size()) {
            result.push_back(current);
            return;
        }
        if(leftNums < n){
            current += '(';
            generate_all(current,leftNums+1,rightNums, n, result);
            current.pop_back();
        }
        if(rightNums < leftNums ){
            current += ')';
            generate_all(current,leftNums,rightNums+1, n, result);
            current.pop_back();
        }
      
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, 0, 0, n, result);
        return result;
    }
};