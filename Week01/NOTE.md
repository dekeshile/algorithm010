预习

## 如何高效学习算法训练营课程

**五毒神掌**

刷题第一遍： 5分钟：读题+思考 直接看解法：注意！多解法，**比较**不同解法的优劣。 **背诵、默写**好的解法 

刷题第二遍： **马上自己写**——&gt;LeetCode提交 多种解法比较、体会——&gt;优化！ 

刷题第三遍： 过了一天之后，再**重复做题** 不同解法的熟练程度——&gt;**专项练习** 

刷题第四遍： 过了一周：**反复回来练习相同题目** 

刷题第五遍： 面试前一周恢复性训练



# 第一周 

## 第3课 数组、链表、跳表的基本实现和特性

数组、链表、跳表的原理和实现

三者的时间复杂度、空间复杂度

工程运用

跳表：升维思想+空间换时间

跳表的特点
注意：只能用于元素有序的情况。
所以，跳表（skip list）对标的是平衡树（AVL Tree）和二分查找，
是一种 插入/删除/搜索 都是 O(log n) 的数据结构。1989 年出现。
它最大的优势是原理简单、容易实现、方便扩展、效率更高。因此
在一些热门的项目里用来替代平衡树，如 Redis、LevelDB 等

如何给有序的链表加速
添加第一级索引
添加第二级索引
添加多级索引

跳表查询的时间复杂度分析
n/2、n/4、n/8、第 k 级索引结点的个数就是 n/(2^k)
假设索引有 h 级，最高级的索引有 2 个结点。n/(2^h) = 2，从而求得 h = log2(n)-1
在跳表中查询任意数据的时间复杂度就是 O(logn)

工程中的应用
LRU Cache - Linked list
https://www.jianshu.com/p/b1ab4a170c3c
https://leetcode-cn.com/problems/lru-cache
Redis - Skip List
https://redisbook.readthedocs.io/en/latest/internaldatastruct/skiplist.html
https://www.zhihu.com/question/

### 实战题目

#### Array

- ✅1. https://leetcode-cn.com/problems/container-with-most-water/
- ✅2. https://leetcode-cn.com/problems/move-zeroes/  
- ✅3. https://leetcode-cn.com/problems/climbing-stairs/
- ✅4. https://leetcode-cn.com/problems/3sum/  

#### Linked List

- 🔲1. https://leetcode-cn.com/problems/reverse-linked-list/

- 🔲2. https://leetcode-cn.com/problems/swap-nodes-in-pairs

- 🔲3. https://leetcode-cn.com/problems/linked-list-cycle

- 🔲4. https://leetcode-cn.com/problems/linked-list-cycle-ii

- 🔲5. https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

  #### Homework

  ✅1. https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

  ✅2. https://leetcode-cn.com/problems/rotate-array/

  🔲3. https://leetcode-cn.com/problems/merge-two-sorted-lists/

  🔲4. https://leetcode-cn.com/problems/merge-sorted-array/

  🔲5. https://leetcode-cn.com/problems/two-sum/

  🔲6. https://leetcode-cn.com/problems/move-zeroes/

  🔲7. https://leetcode-cn.com/problems/plus-one/

## 第4课 | 栈、队列、优先队列、双端队列

1. Stack、Queue、Deque 的原理和操作复杂度

2. PriorityQueue 的特点和操作复杂度

3. 查询 Stack、Queue、Deque、PriorityQueue 的系统接口的方法

Stack & Queue 关键点
• Stack：先入后出；添加、删除皆为 O(1)

• Queue：先入先出；添加、删除皆为 O(1)

Deque
1. 简单理解：两端可以进出的 Queue 
Deque - double ended queue

2.插入和删除都是 O(1) 操作

Priority Queue
1. 插入操作：O(1)

2.取出操作：O(logN) - 按照元素的优先级取出

3.底层具体实现的数据结构较为多样和复杂：heap、bst、treap

Java 的 PriorityQueue 
https://docs.oracle.com/javase/10/docs/api/java/util/
PriorityQueue.html

Stack 和 Queue 的实现
Java 源码分析:

Stack: http://developer.classpath.org/doc/java/util/Stacksource.html
Queue: http://fuseyism.com/classpath/doc/java/util/Queuesource.html 

Priority Queue: 学员自己分析source code！

### 实战题目

✅1https://leetcode-cn.com/problems/largest-rectangle-in-histogram 

2. https://leetcode-cn.com/problems/sliding-window-maximum

#### Homework

1. https://leetcode.com/problems/design-circular-deque 

2. https://leetcode.com/problems/trapping-rain-water/