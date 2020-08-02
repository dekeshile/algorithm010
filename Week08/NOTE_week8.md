**目录**
- [第16课 | 位运算](#第16课--位运算)
  - [实战题](#实战题)
- [第18课 | 排序算法](#第18课--排序算法)
  - [分类](#分类)
  - [初级排序 - O(n^2)](#初级排序---on2)
  - [高级排序 - O(N*LogN)](#高级排序---onlogn)
  - [特殊排序 - O(n)](#特殊排序---on)
  - [实战题目](#实战题目)


# 第16课 | 位运算

## 十进制转为二进制

余数短除法除以二

![img](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1595826772229-e030f929-fbc9-4dca-8aec-12ea39fdbd97.jpeg)



## 位运算符

| **含义**                 | **运算符** | **示例**                   |
| ------------------------ | ---------- | -------------------------- |
| 逻辑左移                 | <<         | 0011 => 0110               |
| 逻辑右移                 | >>         | 0110 => 0011               |
| 按位或                   | \|         | 0011   -------=> 10111011  |
| 按位与                   | &          | 0011   -------=> 00111011  |
| 按位取反                 | ~          | 0011 => 1100               |
| 按位异或(相同为0不同为1) | ^          | 0011    -------=> 10001011 |



## [逻辑左移、算术左移、逻辑右移、算术右移区别](https://www.cnblogs.com/codingbylch/p/5398342.html)

逻辑左移  = 算数左移，右边统一添 0 

逻辑右移，左边统一添0 

算数右移，左边添加的数**和符号有关** 

> e.g:1010101010，其中[ ]是添加的位
>
> 逻辑左移一位：010101010[0]
>
> 算数左移一位：010101010[0]
>
> 逻辑右移一位：**[0]**101010101
>
> 算数右移一位：**[1]**101010101



## XOR -异或

异或：相同为 0，不同为 1。也可用“**不进位加法**”来理解。

异或操作的一些特点：

| **异或操作的一些特点**                                       | **举例**                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| x ^ 0 = x                                                    | 1101^  0000——————   1101   =  x                              |
| x ^ 1s = ~x // 注意 1s = ~0                                  | 1101^   1111 —————   0010  =  ~x                             |
| x ^ (~x) = 1s                                                | 1101^   0010 —————   1111                                    |
| x ^ x = 0                                                    | 1101^   1101 —————    0000                                   |
| 交换两个数( 使用位运算中的异或，俩次异或不改变原值)a = a^bb = a^b = (a^b)^b = aa = a^b = (a^b)^a = b | 交换两个数的方法二a = a+b; 					b = a-b; 					a = a - b; |
| associativea ^ b ^ c = a ^ (b ^ c) = (a ^ b) ^ c             |                                                              |



## 指定位置的位运算

1.  将 x 最右边的 n 位清零：`x& (~0 << n)`
2.  获取 x 的第 n 位值（0 或者 1）：` (x >> n) & 1`
3. 获取 x 的第 n 位的幂值：`x& (1 <<n)`
4. 仅将第 n 位置为 1：`x | (1 << n)`
5. 仅将第 n 位置为 0：`x & (~ (1 << n))`
6. 将 x 最高位至第 n 位（含）清零：`x& ((1 << n) -1)`
7. 将第 n 位至第 0 位（含）清零：`x& (~ ((1 << (n + 1)) -1))`



## 实战位运算要点

- 判断奇偶：

> x % 2 == 1    **—>**     (x & 1) == 1
>
> x % 2 == 0    **—>**    (x & 1) == 0

- x >> 1        **—>**    x / 2.

> 即： x = x / 2;      **—>**        x = x >> 1;
>
> mid = (left + right) / 2;        **—>**          mid = (left + right) >> 1;

- X = X & (X-1)        **—>**      **清零**最低位的 1
- X & -X                   **—>**      **得到**最低位的 1
- X & ~X                  **—>**      0



## 实战题

### [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

> 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为[汉明重量](https://baike.baidu.com/item/汉明重量)）。
>
> **示例 1：**
>
> **输入:**00000000000000000000000000001011
>
> **输出:**3
>
> **解释:**输入的二进制串 `**00000000000000000000000000001011** 中，共有三位为 '1'。`
>
> 
>
> **示例 2：**
>
> **输入:**00000000000000000000000010000000
>
> **输出:**1
>
> **解释:**输入的二进制串 **00000000000000000000000010000000** 中，共有一位为 '1'。
>
> 
>
> **示例 3:**
>
> **输入:**11111111111111111111111111111101
>
> **输出:**31
>
> **解释:**输入的二进制串 **11111111111111111111111111111101** 中，共有 31 位为 '1'。
>
>  
>
> **提示:**
>
> - 请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
> - 在 Java 中，编译器使用[二进制补码](https://baike.baidu.com/item/二进制补码/5295284)记法来表示有符号整数。因此，在上面的 **示例 3** 中，输入表示有符号整数 `-3`。
>
> **进阶**:
>
> 如果多次调用这个函数，你将如何优化你的算法？

#### 解题思路

> 位运算

**方法一**

(n & n-1) 可以把n的最低位的1置为0

不断把n的最低为置为0，同时累加cnt，直到n=0时就知道n中没有1了

```c++
class Solution {
public:
//方法一：(n & n-1) 可以把n的最低位的1置为0
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0) {
            cnt++;
            n &= (n-1);
        }
        return cnt;
    }
};
```

**方法二**

使用位掩码来检查n中位数位1的个数

初始位掩码 m = 1,m的二进制就是 00000.....1,通过判断m&n是否位1可知n的最低为是否为1

然后m每次左移1位，再继续重复上述操作，直到超过31次移位

```c++
class Solution {
public:
 //方法二：使用位掩码来检查n中位数位1的个数
     int hammingWeight(uint32_t n) {
        int cnt = 0;
        uint32_t m = 1;//注意这里使用类型uint32_t，如果用int的化，后面移位到第32次会溢出
        for(int i = 0;i < 32;i++) {
            if(n & m) cnt++;
            m <<= 1;
        }
        return cnt;
    }
};
```

**方法三**

n & 1 判断最低为是否位 1，然后 n>>1 抹掉最低位

重复32次

```c++
class Solution {
public:
  //方法三：n & 1 判断最低为是否位 1，然后 n>>1 抹掉最低位
     int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(int i = 0;i < 32;i++) {
            if( n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};
```



### [231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)

> 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
>
> **示例 1:**
>
> **输入:** 1
>
> **输出:** true
>
> **解释:** 20 = 1
>
> **示例 2:**
>
> **输入:** 16
>
> **输出:** true
>
> **解释:** 24 = 16
>
> **示例 3:**
>
> **输入:** 218
>
> **输出:** false

#### 解题思路

> 位运算

是否是2的幂核心在于n的二进制表示中是否只有1个1bit

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (n & (n-1)) == 0;
    }
};
```



# 第18课 | 排序算法

## 分类

### 1. 比较类排序

通过比较来决定元素间的相对次序，由于其时间复杂度不能突破 O(nlogn)，因此也称为非线性时间比较类排序。 

### 2.非比较类排序

不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。

![1596377633(1).png](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1596377674212-f268c4a1-80a3-48a4-8872-f16b17fd6f03.png)



### 不同排序算法性能上的比较

![1596377707(1).png](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1596377852137-930a4bdb-a8da-4ed2-9b37-77744e368452.png)

## 初级排序 - O(n^2)

### 1. 选择排序（Selection Sort） 

每次找最小值，然后放到待排序数组的起始位置。 

```c++
void select(vector<int>& arr){
    int s = arr.size();
    for(int i=0;i<s;i++){
        int m = arr[i];
        int index = i;
        for(int j=i+1;j<s;j++){
            if(arr[j]<m){
                m = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}
```

### 2. 插入排序（Insertion Sort） 

从前到后逐步构建有序序列；对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。 

```c++
void insertion1(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        int temp=arr[i];
        int j=i-1;
        for(;j>=0 && temp<arr[j];j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}
```

### 3. 冒泡排序（Bubble Sort） 

嵌套循环，每次查看相邻的元素如果逆序，则交换。

```c++
void bubble1(vector<int>& arr){
    bool hasSorted = false;
    for(int i=0;i<arr.size()-1&&!hasSorted;i++){
        hasSorted=true;
        for(int j=0;j<arr.size()-1;j++){
            if(arr[j]>arr[j+1]){
                hasSorted = false;
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
```

## 高级排序 - O(N*LogN)

### 1.快速排序（Quick Sort） 

数组取标杆 pivot，将小元素放 pivot左边，大元素放右侧，然后依次对右边和右边的子数组继续快排；以达到整个序列有序。

```c++
int partition1(vector<int>& arr, int beg, int end){
    int pivot = arr[beg];
    int l=beg+1, r=end;
    while(l<=r){
        if(arr[l]<pivot) l++;
        else if(arr[r]>pivot) r--;
        else if(arr[l]>=pivot && arr[r]<=pivot){
            swap(arr[l++], arr[r--]);
        }
    }
    swap(arr[r], arr[beg]);
    return r;
}
 
int partition2(vector<int>& arr, int beg, int end){
    int pivot = arr[beg];
    int index = beg+1;
    for(int i=index;i<=end;i++){
        if(arr[i]<pivot){
            swap(arr[i], arr[index++]);
        }
    }
    swap(arr[beg],arr[index-1]);
    return index-1;
}
 
void quick(vector<int>& arr, int beg, int end){
    if(beg<end){
        int pivot = partition1(arr,beg,end);
        // int pivot = partition2(arr,beg,end);
        quick(arr, beg, pivot-1);
        quick(arr, pivot+1, end);
    }
 
}
```

### 2.归并排序（Merge Sort）— 分治  	 

1.  把长度为n的输入序列分成两个长度为n/2的子序列；  	 
2.  对这两个子序列分别采用归并排序；  	 
3. 将两个排序好的子序列合并成一个最终的排序序列。 

```c++
vector<int> merge(vector<int> a, vector<int> b){
    vector<int> res;
    int ba = 0;
    int bb = 0;
 
    while(ba<a.size() && bb<b.size()){
        if(a[ba]<=b[bb]){
            res.push_back(a[ba++]);
        }
        else{
            res.push_back(b[bb++]);
        }
    }
 
    if(ba==a.size()){
        while(bb<b.size()) res.push_back(b[bb++]);
    }else if(bb==b.size()){
        while(ba<a.size()) res.push_back(a[ba++]);
    }
 
    return res;
}
 
vector<int> mergeSort(vector<int> arr){
    int s = arr.size();
    if(s<2) return arr;
    int mid = s/2;
    vector<int> front(arr.begin(), arr.begin()+mid);
    vector<int> back(arr.begin()+mid, arr.end());
    return merge(mergeSort(front), mergeSort(back));
 
}
```

归并 和 快排 具有相似性，但步骤顺序相反 

归并：先排序左右子数组，然后合并两个有序子数组 

快排：先调配出左右子数组，然后对于左右子数组进行排序

### 3.堆排序（Heap Sort） — 堆插入 O(logN)，取最大/小值 O(1)  	 

1. 数组元素依次建立小顶堆 
2. 依次取堆顶元素，并删除

```c++
void heap_sort(int a[], int len) {
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 0; i < len; i++) {
        q.push(a[i]);
    }
    for(int i = 0; i < len; i++) {
        a[i] = q.pop();
    }
}

static void heapify(int[] array, int length, int i) {
    int left = 2 * i + 1, right = 2 * i + 2；
    int largest = i;
    if (left < length && array[left] > array[largest]) {
        largest = leftChild;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
        heapify(array, length, largest);
    }
}
public static void heapSort(int[] array) {
    if (array.length == 0) return;
    int length = array.length;
    for (int i = length / 2-1; i >= 0; i-) 
    heapify(array, length, i);
    for (int i = length - 1; i >= 0; i--) {
        int temp = array[0]; array[0] = array[i]; array[i] = temp;
        heapify(array, i, 0);
    }
}
```

## 特殊排序 - O(n)

### 1.计数排序（Counting Sort） 

计数排序要求输入的数据必须是有确定范围的整数。将输入的数据值转化为键存储在额外开辟的数组空间中；然后依次把计数大于 1 的填充回原数组 

```c++
void count(vector<int>& arr, int range){
    vector<int> temp(range+1, 0);
    for(int i=0;i<arr.size();i++){
        temp[arr[i]]++;
    }
 
    int c=0;
    for(int i=0;i<arr.size();i++){
        while(temp[c]==0) c++;
        arr[i] = c;
        temp[c]--;
    }
 
}
```

### 2.桶排序（Bucket Sort） 

桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。 

### 3.基数排序（Radix Sort） 

基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。

```c++
    // LSD Radix Sort
    var counter = [];
    function radixSort(arr, maxDigit) {
        var mod = 10;
        var dev = 1;
        for (var i = 0; i < maxDigit; i++, dev *= 10, mod *= 10) {
            for(var j = 0; j < arr.length; j++) {
                var bucket = parseInt((arr[j] % mod) / dev);
                if(counter[bucket]==null) {
                    counter[bucket] = [];
                }
                counter[bucket].push(arr[j]);
            }
            var pos = 0;
            for(var j = 0; j < counter.length; j++) {
                var value = null;
                if(counter[j]!=null) {
                    while ((value = counter[j].shift()) != null) {
                          arr[pos++] = value;
                    }
              }
            }
        }
        return arr;
    }
```

## 实战题目

### [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)

> 给出一个区间的集合，请合并所有重叠的区间。
>
> **示例 1:**
>
> **输入:** [[1,3],[2,6],[8,10],[15,18]]
>
> **输出:** [[1,6],[8,10],[15,18]]
>
> **解释:** 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
>
> **示例 2:**
>
> **输入:** [[1,4],[4,5]]
>
> **输出:** [[1,5]]
>
> **解释:** 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#### 解题思路

> 排序  双指针

排序 + 双指针

双指针 ![img](https://cdn.nlark.com/yuque/__latex/ee813f0ede8664a8049b1b6720f03b60.svg)

![img](https://cdn.nlark.com/yuque/__latex/865c0c0b4ab0e063e5caa3387c1a8741.svg) 表示当前区间的开始，![img](https://cdn.nlark.com/yuque/__latex/363b122c528f54df4a0446b6bab05515.svg)  表示下一个区间的开始，![img](https://cdn.nlark.com/yuque/__latex/e358efa489f58062f10dd7316b65649e.svg)  表示连续区间的最右端点

![1.jpg](https://cdn.jsdelivr.net/gh/dekeshile/mycloudimg@master/1596035906717-8d17229b-c1dd-4a48-b5a3-f4ce65650646.jpeg)

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        int len = intervals.size();
        for(int i = 0;i < len;) {
            int t = intervals[i][1];
            int j = i + 1;
            while(j < len && intervals[j][0] <= t) {//可以合并的区间
                t = max(t,intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0],t});
            i = j;
        }
        return res;
    }
};
```



### [1122. 数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)

> 给你两个数组，`arr1` 和 `arr2`，	
>
> - `arr2` 中的元素各不相同
> - `arr2` 中的每个元素都出现在 `arr1` 中
>
> 对 `arr1` 中的元素进行排序，使 `arr1` 中项的相对顺序和 `arr2` 中的相对顺序相同。未在 `arr2` 中出现过的元素需要按照升序放在 `arr1` 的末尾。
>
> **示例：**
>
> **输入：**arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
>
> **输出：**[2,2,2,1,4,3,3,9,6,7,19]
>
> **提示：**
>
> - `arr1.length, arr2.length <= 1000`
> - `0 <= arr1[i], arr2[i] <= 1000`
> - `arr2` 中的元素 `arr2[i]` 各不相同
> - `arr2` 中的每个元素 `arr2[i]` 都出现在 `arr1` 中

#### 解题思路

```c++
#define N 1010
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> hash(N,0);
        int len1 = arr1.size();
        int len2 = arr2.size();
        vector<int> res;
        for(int i=0;i < len1;i++) {
            hash[arr1[i]]++;
        }
        for(int i=0;i < len2;i++) {
            for(int j=0;j<hash[arr2[i]];j++)
                res.push_back(arr2[i]);
            hash[arr2[i]] = 0;
        }
        for(int i=0;i<N;i++) {
             for(int j=0;j<hash[i];j++)
                res.push_back(i);
        }
        return res;
    }
};
```



### [493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)

> 给定一个数组 `nums` ，如果 `i < j` 且 `nums[i] > 2*nums[j]` 我们就将 `(i, j)` 称作一个***重要翻转对\***。
>
> 你需要返回给定数组中的重要翻转对的数量。
>
> **示例 1:**
>
> **输入**: [1,3,2,3,1]
>
> **输出**: 2
>
> **示例 2:**
>
> **输入**: [2,4,3,5,1]
>
> **输出**: 3
>
> **注意:**
>
> 1. 给定数组的长度不会超过`50000`。
> 2. 输入数组中的所有数字都在32位整数的表示范围内。

#### 解题思路

> 归并排序

```c++
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeAndCnt(nums,0,nums.size() - 1);
    }

    int mergeAndCnt(vector<int>& nums,int left,int right) {
        if( left >= right) 
            return 0;

        int mid = left + ((right - left) >> 1);
        int cnt = mergeAndCnt(nums,left,mid) + mergeAndCnt(nums,mid+1,right);
        int j = mid + 1;
        for(int i=left;i <= mid;i++) {
            while( j <= right && nums[i] > nums[j]*2LL)
                j++;
            cnt += j - (mid + 1);
        }
        merge(nums,left,mid,right);
        return cnt;
    }

    void merge(vector<int>& nums,int left,int mid,int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int leftNums[n1],rightNums[n2];
        for(int i=0;i< n1;i++)
            leftNums[i] = nums[left + i];
        for(int i=0;i< n2;i++)
            rightNums[i] = nums[mid + 1 + i];
        int i = 0,j = 0;
        for(int k = left;k <= right;k++) {
            if(j >= n2 || (i < n1 && leftNums[i] <= rightNums[j]))
                nums[k] = leftNums[i++];
            else
                nums[k] = rightNums[j++];
        }
    }
};
```