/*
注意：每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
*/
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
      map<string, string> mymap;
      for(int i=0;i<bank.size();i++)
            mymap.insert(pair<string,string>(bank[i],bank[i]));
       //目标基因序列都不合法
      if(mymap.find(end) == mymap.end())
            return -1;
      char basic[] = {'A','C','G','T'};
      int nums = 0;
      queue<string> options;
      options.push(start);
      while(!options.empty()){
        //遍历所有备选基因串
        nums++;
        for(int k=options.size();k >0 ;k--) {
            string top = options.front();
            options.pop();
            //改变备选基因串的每一个字符，看是否与目标基因串相等或是否合法
            for(int i=0;i<top.length();i++) {
                char temp = top[i];
                for( int j = 0;j < 4 ;j++ ) {
                    top[i] = basic[j];
                    if(top == end)
                        return nums;
                    //是一个合法的基因串
                    if(   mymap.find(top) !=  mymap.end() ){
                        options.push(top);
                        mymap.erase(top);
                    }
                }
                top[i] = temp;
            }
        }
      }
     return -1;
    }
};