class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        map<string,vector<string>> wordMap;
        //标记该单词是否被访问过，防止出现环
        map<string,int> visited;
        //对所有单词预处理，以单词的通配符为hash的key，对应的value为具有这个通配符的形式的单词集合
        for(int i=0;i<wordList.size();i++){
            //初始化visited
            visited.insert(pair<string,int>(wordList[i],0));
             string tempWord = wordList[i];
            for(int j=0;j<tempWord.length();j++){
                char temp = tempWord[j];
                tempWord[j] = '*';
                wordMap[tempWord].push_back(wordList[i]);
                tempWord[j] = temp;
             }
        }
        queue<string> que;
        que.push(beginWord);
        int nums = 1;
        while(!que.empty()){
            nums++;
            //遍历每个备选单词
            for(int i = que.size();i >0;i--){
                 string top = que.front();
                 string oldTop = top;
                 que.pop();
                 //遍历每个单词的所有通配形式
                 for(int k=0;k<top.length();k++) {
                    char temp = top[k];
                    top[k] = '*';
                     //遍历每个单词与它只相差一个字母的所有单词
                    for(int j=0;j<wordMap[top].size();j++){
                        string word = wordMap[top][j];
                        if( word == endWord )
                            return nums;
                        if(word != oldTop && visited[word] == 0){
                            que.push(wordMap[top][j]);
                            visited[word] =1;
                        }
                    }
                    top[k] = temp;
            } 
         }
        }
        return 0;
    }
};