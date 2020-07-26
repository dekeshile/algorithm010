目录
- [第13课 | 字典树和并查集](#第13课--字典树和并查集)
  - [一、字典树](#一字典树)
    - [1.概念](#1概念)
    - [3.实战题目](#3实战题目)
      - [208. 实现 Trie (前缀树)](#208-实现-trie-前缀树)
  - [二、并查集](#二并查集)
- [第14课 | 高级搜索](#第14课--高级搜索)
  - [1.概念](#1概念-1)
  - [2.实战题目](#2实战题目)
    - [127. 单词接龙](#127-单词接龙)
- [第15课 | 红黑树和AVL树](#第15课--红黑树和avl树)
  - [1.概念](#1概念-2)

# 第13课 | 字典树和并查集

## 一、字典树

### 1.概念

**基本结构**

![img](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1595760083738-2b435f01-5420-47f9-885a-a113e3727ba8.png)

字典树，即 Trie 树，又称单词查找树或键树，是一种树形结构。典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。 

它的优点是：最大限度地减少无谓的字符串比较，查询效率比哈希表高。



**基本性质**

1. 结点本身不存完整单词；
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串；
3. 每个结点的所有子结点路径代表的字符都不相同。



**结点的内部实现**

**![图片.png](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1595760136953-23f65f1d-8b0f-4bb7-bd9d-5ee86baf0e69.png)**

**核心思想**

Trie 树的核心思想是空间换时间。 

利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的



**2.应用**

1. 自动补全
2. 拼写检查
3. IP 路由 (最长前缀匹配)
4. T9 (九宫格) 打字预测
5. 单词游戏



### 2.实战题目

#### [208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

> 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
>
> 示例:
>
> Trie trie = new Trie();
>
> trie.insert("apple");
>
> trie.search("apple");  // 返回 true
>
> trie.search("app");   // 返回 false
>
> trie.startsWith("app"); // 返回 true
>
> trie.insert("app");  
>
> trie.search("app");   // 返回 true
>
> 说明:
>
>    你可以假设所有的输入都是由小写字母 a-z 构成的。
>
>    保证所有输入均为非空字符串。

**代码实现**

```c++
struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> next;
};

class Trie {
private:
    TrieNode *root;
    
public:
    Trie(): root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode *p = root;
        for (const char c : word) {
            if (!p->next.count(c)) {
                p->next[c] = new TrieNode();
            }
            p = p->next[c];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *p = root;
        for (const char c : word) {
            if (!p->next.count(c)) {
                return false;
            }
            p = p->next[c];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (const char c : prefix) {
            if (!p->next.count(c)) {
                return false;
            }
            p = p->next[c];
        }
        return p != nullptr;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```



## 二、并查集

**适用场景**

• 组团、配对问题 

• Group or not ? 

**基本操作**

• makeSet(s)：建立一个新的并查集，其中包含 s 个单元素集合。 

• unionSet(x, y)：把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在

的集合不相交，如果相交则不合并。 

• fifind(x)：找到元素 x 所在的集合的代表，该操作也可以用于判断两个元

素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

**初始化**

![图片.png](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1595762403400-c50de0d5-d76e-4747-b45a-08536957d029.png)

**查询、合并**

![图片.png](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1595762431954-5357d724-e85e-425b-82ba-ccf34e7bb6fa.png)

**路径压缩**

![图片.png](https://cdn.nlark.com/yuque/0/2020/png/1458680/1595762469300-d0d6a995-cf59-4477-805d-8b3e84c8526f.png)



 **C++版并查集**

```c++
#include <vector>
class DisjSet
{
  private:
    std::vector<int> parent;
    std::vector<int> rank; // 秩

  public:
    DisjSet(int max_size) : parent(std::vector<int>(max_size)),
                            rank(std::vector<int>(max_size, 0))
    {
        for (int i = 0; i < max_size; ++i)
            parent[i] = i;
    }
    int find(int x)
    {
        return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }
    void to_union(int x1, int x2)
    {
        int f1 = find(x1);
        int f2 = find(x2);
        if (rank[f1] > rank[f2])
            parent[f2] = f1;
        else
        {
            parent[f1] = f2;
            if (rank[f1] == rank[f2])
                ++rank[f2];
        }
    }
    bool is_same(int e1, int e2)
    {
        return find(e1) == find(e2);
    }
};
```



# 第14课 | 高级搜索

## 1.概念

**初级搜索**

1. 朴素搜索 
2. 优化方式：不重复（fifibonacci）、剪枝（生成括号问题） 
3. 搜索方向： 

- DFS: depth fifirst search 深度优先搜索 
- BFS: breadth fifirst search 广度优先搜索 

双向搜索、启发式搜索

**回溯法**

回溯法采用试错的思想，它尝试分步的去解决一个问题。在分步解决问题的过程中，当

它通过尝试发现现有的分步答案不能得到有效的正确的解答的时候，它将取消上一步甚

至是上几步的计算，再通过其它的可能的分步解答再次尝试寻找问题的答案。 

回溯法通常用最简单的递归方法来实现，在反复重复上述的步骤后可能出现两种情况： 

• 找到一个可能存在的正确的答案 

• 在尝试了所有可能的分步方法后宣告该问题没有答案 

在最坏的情况下，回溯法会导致一次复杂度为指数时间的计算

**双向 BFS**

**![1_meitu_2.jpg](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1595763633915-37e77ca6-9982-42ef-b54a-6bb923421e93.jpeg)**



**启发式搜索 Heuristic Search (A\*)**

| **基于 BFS 代码**                                            | A*search                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ``` def BFS(graph, start, end):  queue = []  queue.append([start])  visited.add(start) while queue:  node = queue.pop() # can we add more intelligence here ?  visited.add(node)  process(node)  nodes = generate_related_nodes(node)  queue.push(nodes)``` | ```def AstarSearch(graph, start, end):  pq = collections.priority_queue() # 优先级 —> 估价函数 pq.append([start])  visited.add(start) while pq:  node = pq.pop() # can we add more intelligence here ?  visited.add(node)  process(node)  nodes = generate_related_nodes(node)  unvisited = [node for node in nodes if node not in visited]  pq.push(unvisited)``` |

**估价函数**

启发式函数： h(n)，它用来评价哪些结点最有希望的是一个我们要找的结

点，h(n) 会返回一个非负实数,也可以认为是从结点n的目标结点路径的估

计成本。 

启发式函数是一种告知搜索方向的方法。它提供了一种明智的方法来猜测

哪个邻居结点会导向一个目标。



## 2.实战题目

### [127. 单词接龙](https://leetcode-cn.com/problems/word-ladder/)

> 给定两个单词（*beginWord* 和 *endWord*）和一个字典，找到从 *beginWord* 到 *endWord* 的最短转换序列的长度。转换需遵循如下规则：
>
> 1. 每次转换只能改变一个字母。
> 2. 转换过程中的中间单词必须是字典中的单词。
>
> **说明:**
>
> - 如果不存在这样的转换序列，返回 0。
> - 所有单词具有相同的长度。
> - 所有单词只由小写字母组成。
> - 字典中不存在重复的单词。
> - 你可以假设 *beginWord* 和 *endWord* 是非空的，且二者不相同。
>
> **示例 1:**
>
> **输入:**
>
> beginWord = "hit",
>
> endWord = "cog",
>
> wordList = ["hot","dot","dog","lot","log","cog"]
>
> **输出:** 5
>
> **解释:** 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
>
>    返回它的长度 5。
>
> **示例 2:**
>
> **输入:**
>
> beginWord = "hit"
>
> endWord = "cog"
>
> wordList = ["hot","dot","dog","lot","log"]
>
> **输出:** 0

**代码实现**

双向BFS

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset{wordList.begin(),wordList.end()}; //处理endWord不在wordList中的特殊情况
        if(wordset.find(endWord) == wordset.end()) return 0;
        unordered_set<string> begintoend{beginWord}; //用来存放从起点开始，匹配到的单词
        unordered_set<string> endtobegin{endWord};//用来存放从终点开始，匹配到的单词

        queue<string> beginQ; //从起点开始，可能的单词入队
        queue<string> endQ; //从终点开始，可能的单词入队
        beginQ.push(beginWord);
        endQ.push(endWord);

        int depth = 0;

        while(!beginQ.empty()&&!endQ.empty()){  //任何一个队列为空，都是线索断了的意思，所以要用&&
            int flag_begintoend = 1;
            if(beginQ.size() > endQ.size()){ //这里选择一个较短的队列进行搜索
                swap(beginQ,endQ); //交换的意义在于，后面代码我们只准备用一个队列变量来进行搜索，所以要把较短的队列统一到beginQ上，便于后面做搜索，当然也可以重新写个bfs函数，就不需要交换了。
                flag_begintoend = 0; //flag用于判断下方代码while使用的BeginQ是真的BeginQ，还是假的BeginQ
            }else{
                flag_begintoend = 1;
            }

            int size = beginQ.size(); //当前较短队列中存放的元素个数
            depth++;
            while(size--){
                string hop = beginQ.front();
                beginQ.pop();
                for(auto & w:wordList){
                    //排除重复遍历单词
                    //当前beginQ是begintoend的路径上的元素
                    if(flag_begintoend && begintoend.find(w)!=begintoend.end()) continue;
                    //当前beginQ是endtobegin的路径上的元素
                    if(!flag_begintoend && endtobegin.find(w)!= endtobegin.end()) continue;
                    int diff = 0;
                    for(int i = 0;i<hop.size();i++){
                        if(hop[i]!=w[i]){
                            diff++;
                        }
                        if(diff > 1) break;
                    }

                    if(diff == 1){
                        //当前beginQ是begintoend的路径上的元素
                        //但是找到的新元素已经出现在了endtobegin的路径中
                        if(flag_begintoend && endtobegin.find(w)!=endtobegin.end() ) return depth+1;
                        //当前beginQ是endtobegin的路径上的元素
                        //但是找到的新元素已经出现在了begintoend的路径中
                        if(!flag_begintoend && begintoend.find(w)!=begintoend.end() ) return depth+1;

                        beginQ.push(w);

                        if(flag_begintoend ){
                            begintoend.insert(w);//记录出现在了begintoend的路径中的元素，避免重复遍历
                        }else{
                            endtobegin.insert(w);//记录出现在了endtobegin的路径中的元素，避免重复遍历
                        }
                    }
                }
            }
            //最后还是需要还原队列对应关系
            if(!flag_begintoend){
                swap(beginQ,endQ);
            }
        }
        return 0;
    }
};
```



# 第15课 | 红黑树和AVL树

## 1.概念

**二叉搜索树 Binary Search Tree**

二叉搜索树，也称二叉搜索树、有序二叉树（Ordered Binary Tree）、排序二叉树（Sorted Binary Tree），是指一棵空树或者具有下列性质的二叉树：

1. 左子树上所有结点的值均小于它的根结点的值；
2. 右子树上所有结点的值均大于它的根结点的值；
3. 以此类推：左、右子树也分别为二叉查找树。 （这就是 重复性！）

中序遍历：升序排列



**AVL 树**

1. 发明者 G. M. Adelson-Velsky和 Evgenii Landis

2. Balance Factor（平衡因子）：是它的左子树的高度减去它的右子树的高度（有时相反）。

   ​	balance factor = {-1, 0, 1}

3. 通过旋转操作来进行平衡（四种）

4.  [https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_)



**AVL 总结**

1. 平衡二叉搜索树
2.  每个结点存 balance factor = {-1, 0, 1}
3. 四种旋转操作

不足：结点需要存储额外信息、且调整次数频繁



**Red-black Tree**

红黑树是一种近似平衡的二叉搜索树（Binary Search Tree），它能够确保任何一

个结点的左右子树的高度差小于两倍。具体来说，红黑树是满足如下条件的二叉

搜索树： 

-  每个结点要么是红色，要么是黑色
- 根结点是黑色
- 每个叶结点（NIL结点，空结点）是黑色的。 
- 不能有相邻接的两个红色结点 
- 从任一结点到其每个叶子的所有路径都包含相同数目的黑色



**关键性质**

从根到叶子的最长的可能路径不多于最短的可能路径的两倍



**对比**

- AVL trees provide faster lookups than Red Black Trees because they are more strictly balanced. 
- Red Black Trees provide faster insertion and removal operations than AVL trees as fewer rotations are done due to relatively relaxed balancing.
- AVL trees storebalance factors or heights with each node, thus requires storage for an integer per node whereas Red Black Tree requires only 1 bit of information per node.
- Red Black Trees are used in most of the language libraries like map, multimap, multisetin C++ whereas AVL trees are used in databases where faster retrievals are required.