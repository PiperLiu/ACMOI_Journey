# ACM/OI Journey
力扣、ACM、OI这些对我来说都很难，但是我觉得这些算法与逻辑很精妙。在此留下刷题痕迹与刷题心得。

```bash
# 更新 README.md
python refresh.py -r
```

不定期的方法论总结在这里[./notes/README.md](./notes/README.md)。

学习资料：
- OI Wiki: https://oi-wiki.org/
- 力扣中国: https://leetcode-cn.com/

## 归档
- [匹配](#匹配)
- [字符串](#字符串)
- [双指针法](#双指针法)
- [搜索](#搜索)
- [深度优先搜索](#深度优先搜索)
- [链表](#链表)
- [快慢指针](#快慢指针)
- [栈](#栈)
- [递归](#递归)
- [回溯](#回溯)
- [分治法](#分治法)
- [动态规划](#动态规划)
- [其他](#其他)
- [排序](#排序)
### 匹配
- 整数转罗马数字『生活中从大的位数开始描述数字，因此从大的数与字符开始匹配』 [cpp](./vsc_leetcode/12.整数转罗马数字.cpp) 2020.11.27
- 罗马数字转整数『总结其中规律：从左开始搜索，如果左边字符小于右，则减去左字符，否则加；对于最右侧字符，一定是用来加的』 [cpp](./vsc_leetcode/13.罗马数字转整数.cpp) 2020.11.28
- 最长公共前缀『是所有字符串前缀的交集，因此0与1取交集，其结果与2取交集...』 [cpp](./vsc_leetcode/14.最长公共前缀.cpp) 2020.11.29
- 有效的括号『先出现的左括号后匹配，因此，可以根据该特点使用栈，匹配了，就出栈，最后所有左括号成功出栈，则匹配成功』 [cpp](./vsc_leetcode/20.有效的括号.cpp) 2020.12.6
- 实现-str-str『返回首个合规子串索引：尝试了自己逐一搜索，有些乱，逻辑易出错；还可以尝试KMP与Rabin-Karp』 [遍历cpp](./vsc_leetcode/28.实现-str-str.cpp) [Rabin_Karp_cpp](./vsc_leetcode/28.实现-str-str_Rabin_Karp.cpp) [KMP_cpp](./vsc_leetcode/28.实现-str-str_kmp.cpp) 2020.12.20
- 串联所有单词的子串『注意到单词是定长的、子串中单词顺序不重要，使用滑窗，left和right有点类似双指针的感觉；滑窗每次滑动长度为word.size()，因此注意起点有word.size()这么多个』 [cpp](./vsc_leetcode/30.串联所有单词的子串.cpp) 2020.12.31
- 最长有效括号『三种做法：经典的动态规划（更新公式需要稍微推导一下）；栈与匹配（妙用栈顶、开始时压入-1）；考察思维严谨性的正逆向结合。具体解析都写在代码里了』 [动态规划cpp](./vsc_leetcode/32.最长有效括号_dp.cpp) [栈cpp](./vsc_leetcode/32.最长有效括号_stk.cpp) [正逆向结合cpp](./vsc_leetcode/32.最长有效括号.cpp) 2021.1.5

### 字符串
- 整数转罗马数字『生活中从大的位数开始描述数字，因此从大的数与字符开始匹配』 [cpp](./vsc_leetcode/12.整数转罗马数字.cpp) 2020.11.27
- 罗马数字转整数『总结其中规律：从左开始搜索，如果左边字符小于右，则减去左字符，否则加；对于最右侧字符，一定是用来加的』 [cpp](./vsc_leetcode/13.罗马数字转整数.cpp) 2020.11.28
- 最长公共前缀『是所有字符串前缀的交集，因此0与1取交集，其结果与2取交集...』 [cpp](./vsc_leetcode/14.最长公共前缀.cpp) 2020.11.29
- 电话号码的字母组合『使用很简单的、直观的递归实现深度优先搜索多层次的遍历，每搜索到最后一层，将该字符串推入结果数组』 [cpp](./vsc_leetcode/17.电话号码的字母组合.cpp) 2020.12.3
- 有效的括号『先出现的左括号后匹配，因此，可以根据该特点使用栈，匹配了，就出栈，最后所有左括号成功出栈，则匹配成功』 [cpp](./vsc_leetcode/20.有效的括号.cpp) 2020.12.6
- 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 [cpp](./vsc_leetcode/22.括号生成.cpp) 2020.12.8
- 实现-str-str『返回首个合规子串索引：尝试了自己逐一搜索，有些乱，逻辑易出错；还可以尝试KMP与Rabin-Karp』 [遍历cpp](./vsc_leetcode/28.实现-str-str.cpp) [Rabin_Karp_cpp](./vsc_leetcode/28.实现-str-str_Rabin_Karp.cpp) [KMP_cpp](./vsc_leetcode/28.实现-str-str_kmp.cpp) 2020.12.20
- 外观数列『①很典型的递归题目，注意cpp里字符串最后一位是转义0，引出可以妙用溢出②需要单独总结一下string库里的方法，如to_string等等』 [cpp](./vsc_leetcode/38.外观数列.cpp) [递归cpp](./vsc_leetcode/38.外观数列_recursion.cpp) 2020.12.23
- 最后一个单词的长度『很基础的字符串搜索，要注意边界条件while中大于等于0』 [cpp](./vsc_leetcode/58.最后一个单词的长度.cpp) 2020.12.26
- 串联所有单词的子串『注意到单词是定长的、子串中单词顺序不重要，使用滑窗，left和right有点类似双指针的感觉；滑窗每次滑动长度为word.size()，因此注意起点有word.size()这么多个』 [cpp](./vsc_leetcode/30.串联所有单词的子串.cpp) 2020.12.31

### 双指针法
- 盛最多水的容器『因为两个边共同决定了上限，因此将较短边向内移动，抛弃搜索次优解』 [py](./vsc_leetcode/11.盛最多水的容器.py) [cpp](./vsc_leetcode/11.盛最多水的容器.cpp) 2020.11.26
- 三数之和『典型双指针：排序后，求和大于目标，后指针前移，小于则前指针后移；利用题目不重复特性，跳过重复元素；利用题目目标值固定特性，只for前两个数，第三个根据状态自动前移』 [cpp](./vsc_leetcode/15.三数之和.cpp) 2020.11.29
- 最接近的三数之和『典型双指针：排序后，求和大于目标，后指针前移，小于则前指针后移；利用题目不重复特性，跳过重复元素；一个for套一个while，while内两个指针根据条件移动』 [cpp](./vsc_leetcode/16.最接近的三数之和.cpp) 2020.12.1
- 四数之和『典型双指针：排序后（别忘了sort），循环前两个数，双指针后两个数；别忘了让同一指针不连续指向数值相同的数』 [cpp](./vsc_leetcode/18.四数之和.cpp) 2020.12.4
- 接雨水『方法①两个数组：左侧最大值，右侧最大值，ans累加每个x对应能盛多少水；方法②利用栈：从左至右按照条件积累雨水，对于3-2-1-2-3这种形式，过程中会先把2-1-2盛满1的水，再把3-2-2-2-3盛满3的水，利用了栈；方法③双指针：方法①的改进，利用容器特点，左右两个指针向中间逼近，同时，移动一次，判断一次是否在本x添水；并且总是移动短边，防止一遍侧漏，接不住，乱添水』 [容器特点cpp](./vsc_leetcode/42.接雨水.cpp) [栈cpp](./vsc_leetcode/42.接雨水_栈.cpp) [双指针cpp](./vsc_leetcode/42.接雨水_双指针.cpp) 2020.12.10
- 删除排序数组中的重复项『一个指针用于计数，另一个去遍历』 [cpp](./vsc_leetcode/26.删除排序数组中的重复项.cpp) 2020.12.18
- 移除元素『一个指针在前，保存不重复元素，另一个指针去向后遍历；移除并不是指用容器pop，而是改变之前数组，并返回长度』 [cpp](./vsc_leetcode/27.移除元素.cpp) 2020.12.19

### 搜索
- 盛最多水的容器『因为两个边共同决定了上限，因此将较短边向内移动，抛弃搜索次优解』 [py](./vsc_leetcode/11.盛最多水的容器.py) [cpp](./vsc_leetcode/11.盛最多水的容器.cpp) 2020.11.26
- 搜索插入位置『遍历比较大小，当然，也可以二分法（首先应该想到二分法）』 [cpp](./vsc_leetcode/35.搜索插入位置.cpp) [二分法cpp](./vsc_leetcode/35.搜索插入位置_binarySearch.cpp) 2020.12.22
- 最后一个单词的长度『很基础的字符串搜索，要注意边界条件while中大于等于0』 [cpp](./vsc_leetcode/58.最后一个单词的长度.cpp) 2020.12.26

### 深度优先搜索
- 电话号码的字母组合『使用很简单的、直观的递归实现深度优先搜索多层次的遍历，每搜索到最后一层，将该字符串推入结果数组』 [cpp](./vsc_leetcode/17.电话号码的字母组合.cpp) 2020.12.3

### 链表
- 删除链表的倒数第n个节点『包含很多链表常用技巧：设置哑节点（不用单独处理头节点了），用while和指针判断是否到达链表末尾，常用的变量名如prev等；本题的特征是，倒数第n个节点，因此，用栈push再pop出n个，或者用快慢指针间隔n个然后走到末尾』 [基于栈cpp](./vsc_leetcode/19.删除链表的倒数第n个节点.cpp) [基于快慢指针cpp](./vsc_leetcode/19.删除链表的倒数第n个节点_.cpp) 2020.12.5
- 合并两个有序链表『很典型的适于递归的题目，递归函数返回下一状态的结果指针』 [cpp](./vsc_leetcode/21.合并两个有序链表.cpp) 2020.12.7
- 合并k个升序链表『总体上，对链表们分治合并，见函数merge，使用递归实现，包括l、r、情况处理（递归的出口）、mid由位运算求、尾递归调用等经典操作，值得记忆』 [cpp](./vsc_leetcode/23.合并k个升序链表.cpp) 2020.12.9
- 两两交换链表中的节点『很简单的一道递归题目，两两交换时，定义一个临时指针newHead』 [cpp](./vsc_leetcode/24.两两交换链表中的节点.cpp) 2020.12.11
- 反转链表『链表反转最基本的题目』 [cpp](./vsc_leetcode/206.反转链表.cpp) 2020.12.15
- k-个一组翻转链表『把逻辑拆开，用于翻转的链表头尾分别为head与tail，head前的是pre、tail后是nex，此外，保存一个hair，hair是哑节点，最后返回时返回hair的next』 [cpp](./vsc_leetcode/25.k-个一组翻转链表.cpp) 2020.12.17

### 快慢指针
- 删除链表的倒数第n个节点『包含很多链表常用技巧：设置哑节点（不用单独处理头节点了），用while和指针判断是否到达链表末尾，常用的变量名如prev等；本题的特征是，倒数第n个节点，因此，用栈push再pop出n个，或者用快慢指针间隔n个然后走到末尾』 [基于栈cpp](./vsc_leetcode/19.删除链表的倒数第n个节点.cpp) [基于快慢指针cpp](./vsc_leetcode/19.删除链表的倒数第n个节点_.cpp) 2020.12.5

### 栈
- 有效的括号『先出现的左括号后匹配，因此，可以根据该特点使用栈，匹配了，就出栈，最后所有左括号成功出栈，则匹配成功』 [cpp](./vsc_leetcode/20.有效的括号.cpp) 2020.12.6
- 接雨水『方法①两个数组：左侧最大值，右侧最大值，ans累加每个x对应能盛多少水；方法②利用栈：从左至右按照条件积累雨水，对于3-2-1-2-3这种形式，过程中会先把2-1-2盛满1的水，再把3-2-2-2-3盛满3的水，利用了栈；方法③双指针：方法①的改进，利用容器特点，左右两个指针向中间逼近，同时，移动一次，判断一次是否在本x添水；并且总是移动短边，防止一遍侧漏，接不住，乱添水』 [容器特点cpp](./vsc_leetcode/42.接雨水.cpp) [栈cpp](./vsc_leetcode/42.接雨水_栈.cpp) [双指针cpp](./vsc_leetcode/42.接雨水_双指针.cpp) 2020.12.10
- 最长有效括号『三种做法：经典的动态规划（更新公式需要稍微推导一下）；栈与匹配（妙用栈顶、开始时压入-1）；考察思维严谨性的正逆向结合。具体解析都写在代码里了』 [动态规划cpp](./vsc_leetcode/32.最长有效括号_dp.cpp) [栈cpp](./vsc_leetcode/32.最长有效括号_stk.cpp) [正逆向结合cpp](./vsc_leetcode/32.最长有效括号.cpp) 2021.1.5

### 递归
- 合并两个有序链表『很典型的适于递归的题目，递归函数返回下一状态的结果指针』 [cpp](./vsc_leetcode/21.合并两个有序链表.cpp) 2020.12.7
- 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 [cpp](./vsc_leetcode/22.括号生成.cpp) 2020.12.8
- 合并k个升序链表『总体上，对链表们分治合并，见函数merge，使用递归实现，包括l、r、情况处理（递归的出口）、mid由位运算求、尾递归调用等经典操作，值得记忆』 [cpp](./vsc_leetcode/23.合并k个升序链表.cpp) 2020.12.9
- 两两交换链表中的节点『很简单的一道递归题目，两两交换时，定义一个临时指针newHead』 [cpp](./vsc_leetcode/24.两两交换链表中的节点.cpp) 2020.12.11
- 外观数列『①很典型的递归题目，注意cpp里字符串最后一位是转义0，引出可以妙用溢出②需要单独总结一下string库里的方法，如to_string等等』 [cpp](./vsc_leetcode/38.外观数列.cpp) [递归cpp](./vsc_leetcode/38.外观数列_recursion.cpp) 2020.12.23

### 回溯
- 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 [cpp](./vsc_leetcode/22.括号生成.cpp) 2020.12.8

### 分治法
- 合并k个升序链表『总体上，对链表们分治合并，见函数merge，使用递归实现，包括l、r、情况处理（递归的出口）、mid由位运算求、尾递归调用等经典操作，值得记忆』 [cpp](./vsc_leetcode/23.合并k个升序链表.cpp) 2020.12.9
- 二分查找『对于已经排好序的数组，使用经典的二分查找，需要注意：为了防止溢出pivot=left+（right-left）/2、left=pivot+1等技巧』 [cpp](./vsc_leetcode/704.二分查找.cpp) 2020.12.10
- 搜索插入位置『遍历比较大小，当然，也可以二分法（首先应该想到二分法）』 [cpp](./vsc_leetcode/35.搜索插入位置.cpp) [二分法cpp](./vsc_leetcode/35.搜索插入位置_binarySearch.cpp) 2020.12.22
- 最大子序和『很经典的动态规划思想，前i个元素构成的数组，与当前x比较，pre+x小于x，则x自己另起炉灶，作为首个元素；此外还有结合线段树的分治法求解』 [cpp](./vsc_leetcode/53.最大子序和.cpp) [分治法cpp](./vsc_leetcode/53.最大子序和_DandC.cpp) 2020.12.25
- 搜索旋转排序数组『见到有序数组，想到二分法；本题特征：一个有序数组切分成了2个，因此数组1最小值大于数组2最大值，比较指针l与r的值，即可判断当前区间上下界』 [cpp](./vsc_leetcode/33.搜索旋转排序数组.cpp) 2021.1.3
- 在排序数组中查找元素的第一个和最后一个位置『〇、见有序想起二分法；一、二分法细节决定成败，具体看代码文件cpp，关于ans赋值问题；二、将问题转换：要找的就是数组中「第一个等于target的位置」和「第一个大于target的位置减一」三、提升代码可复用性，这个lower布尔值参数用的很妙』 [cpp](./vsc_leetcode/34.在排序数组中查找元素的第一个和最后一个位置.cpp) 2021.1.4

### 动态规划
- 最大子序和『很经典的动态规划思想，前i个元素构成的数组，与当前x比较，pre+x小于x，则x自己另起炉灶，作为首个元素；此外还有结合线段树的分治法求解』 [cpp](./vsc_leetcode/53.最大子序和.cpp) [分治法cpp](./vsc_leetcode/53.最大子序和_DandC.cpp) 2020.12.25
- 最长有效括号『三种做法：经典的动态规划（更新公式需要稍微推导一下）；栈与匹配（妙用栈顶、开始时压入-1）；考察思维严谨性的正逆向结合。具体解析都写在代码里了』 [动态规划cpp](./vsc_leetcode/32.最长有效括号_dp.cpp) [栈cpp](./vsc_leetcode/32.最长有效括号_stk.cpp) [正逆向结合cpp](./vsc_leetcode/32.最长有效括号.cpp) 2021.1.5

### 其他
- 加一『考察思维严谨性，加一后，可能进位，并且可能造成连续的进位（如以99结尾）』 [cpp](./vsc_leetcode/66.加一.cpp) 2020.12.27
- 两数相除『考察思维严谨性，注意：①int类型的负数下届比正数更大，因此可以统一为负数然后计算；②a+a>b与a-b+a>0数学意义相同，程序意义不同，前者更容易溢出』 [cpp](./vsc_leetcode/29.两数相除.cpp) 2020.12.29
- 二进制求和『简单题目，可以分情况思考，然后用%等运算提取共性进行判断，精彩的三元表达式应用』 [cpp](./vsc_leetcode/67.二进制求和.cpp) 2020.12.30
- 有效的数独『一次遍历，利用数学关系访问行、列、九宫格』 [cpp](./vsc_leetcode/36.有效的数独.cpp) 2021.1.8

### 排序
- 下一个排列『在stl中有内置的next_permutation，这道题要求求出“紧邻”着的下一个排列，因此从后搜索，将尽可能小的大数与前面的小数交换，心中浮现柱状图可视化大小关系是个不错的选择；此外，为了相通方案的合理性，从最小的排列思考如何到下一个排列是一个不错的选择，或者，可以思考反例：如果不这样做某步...就会导致不对』 [cpp](./vsc_leetcode/31.下一个排列.cpp) 2021.1.3
- 搜索旋转排序数组『见到有序数组，想到二分法；本题特征：一个有序数组切分成了2个，因此数组1最小值大于数组2最大值，比较指针l与r的值，即可判断当前区间上下界』 [cpp](./vsc_leetcode/33.搜索旋转排序数组.cpp) 2021.1.3

## 日期归档
- 2020.11.26 盛最多水的容器『因为两个边共同决定了上限，因此将较短边向内移动，抛弃搜索次优解』 双指针法 搜索 [py](./vsc_leetcode/11.盛最多水的容器.py) [cpp](./vsc_leetcode/11.盛最多水的容器.cpp)
- 2020.11.27 整数转罗马数字『生活中从大的位数开始描述数字，因此从大的数与字符开始匹配』 匹配 字符串 [cpp](./vsc_leetcode/12.整数转罗马数字.cpp)
- 2020.11.28 罗马数字转整数『总结其中规律：从左开始搜索，如果左边字符小于右，则减去左字符，否则加；对于最右侧字符，一定是用来加的』 匹配 字符串 [cpp](./vsc_leetcode/13.罗马数字转整数.cpp)
- 2020.11.29 最长公共前缀『是所有字符串前缀的交集，因此0与1取交集，其结果与2取交集...』 匹配 字符串 [cpp](./vsc_leetcode/14.最长公共前缀.cpp)
- 2020.11.29 三数之和『典型双指针：排序后，求和大于目标，后指针前移，小于则前指针后移；利用题目不重复特性，跳过重复元素；利用题目目标值固定特性，只for前两个数，第三个根据状态自动前移』 双指针法 [cpp](./vsc_leetcode/15.三数之和.cpp)
- 2020.12.1 最接近的三数之和『典型双指针：排序后，求和大于目标，后指针前移，小于则前指针后移；利用题目不重复特性，跳过重复元素；一个for套一个while，while内两个指针根据条件移动』 双指针法 [cpp](./vsc_leetcode/16.最接近的三数之和.cpp)
- 2020.12.3 电话号码的字母组合『使用很简单的、直观的递归实现深度优先搜索多层次的遍历，每搜索到最后一层，将该字符串推入结果数组』 字符串 深度优先搜索 [cpp](./vsc_leetcode/17.电话号码的字母组合.cpp)
- 2020.12.4 四数之和『典型双指针：排序后（别忘了sort），循环前两个数，双指针后两个数；别忘了让同一指针不连续指向数值相同的数』 双指针法 [cpp](./vsc_leetcode/18.四数之和.cpp)
- 2020.12.5 删除链表的倒数第n个节点『包含很多链表常用技巧：设置哑节点（不用单独处理头节点了），用while和指针判断是否到达链表末尾，常用的变量名如prev等；本题的特征是，倒数第n个节点，因此，用栈push再pop出n个，或者用快慢指针间隔n个然后走到末尾』 链表 快慢指针 [基于栈cpp](./vsc_leetcode/19.删除链表的倒数第n个节点.cpp) [基于快慢指针cpp](./vsc_leetcode/19.删除链表的倒数第n个节点_.cpp)
- 2020.12.6 有效的括号『先出现的左括号后匹配，因此，可以根据该特点使用栈，匹配了，就出栈，最后所有左括号成功出栈，则匹配成功』 匹配 字符串 栈 [cpp](./vsc_leetcode/20.有效的括号.cpp)
- 2020.12.7 合并两个有序链表『很典型的适于递归的题目，递归函数返回下一状态的结果指针』 递归 链表 [cpp](./vsc_leetcode/21.合并两个有序链表.cpp)
- 2020.12.8 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 递归 回溯 字符串 [cpp](./vsc_leetcode/22.括号生成.cpp)
- 2020.12.9 合并k个升序链表『总体上，对链表们分治合并，见函数merge，使用递归实现，包括l、r、情况处理（递归的出口）、mid由位运算求、尾递归调用等经典操作，值得记忆』 递归 链表 分治法 [cpp](./vsc_leetcode/23.合并k个升序链表.cpp)
- 2020.12.10 二分查找『对于已经排好序的数组，使用经典的二分查找，需要注意：为了防止溢出pivot=left+（right-left）/2、left=pivot+1等技巧』 分治法 [cpp](./vsc_leetcode/704.二分查找.cpp)
- 2020.12.10 接雨水『方法①两个数组：左侧最大值，右侧最大值，ans累加每个x对应能盛多少水；方法②利用栈：从左至右按照条件积累雨水，对于3-2-1-2-3这种形式，过程中会先把2-1-2盛满1的水，再把3-2-2-2-3盛满3的水，利用了栈；方法③双指针：方法①的改进，利用容器特点，左右两个指针向中间逼近，同时，移动一次，判断一次是否在本x添水；并且总是移动短边，防止一遍侧漏，接不住，乱添水』 栈 双指针法 [容器特点cpp](./vsc_leetcode/42.接雨水.cpp) [栈cpp](./vsc_leetcode/42.接雨水_栈.cpp) [双指针cpp](./vsc_leetcode/42.接雨水_双指针.cpp)
- 2020.12.11 两两交换链表中的节点『很简单的一道递归题目，两两交换时，定义一个临时指针newHead』 链表 递归 [cpp](./vsc_leetcode/24.两两交换链表中的节点.cpp)
- 2020.12.15 反转链表『链表反转最基本的题目』 链表 [cpp](./vsc_leetcode/206.反转链表.cpp)
- 2020.12.17 k-个一组翻转链表『把逻辑拆开，用于翻转的链表头尾分别为head与tail，head前的是pre、tail后是nex，此外，保存一个hair，hair是哑节点，最后返回时返回hair的next』 链表 [cpp](./vsc_leetcode/25.k-个一组翻转链表.cpp)
- 2020.12.18 删除排序数组中的重复项『一个指针用于计数，另一个去遍历』 双指针法 [cpp](./vsc_leetcode/26.删除排序数组中的重复项.cpp)
- 2020.12.19 移除元素『一个指针在前，保存不重复元素，另一个指针去向后遍历；移除并不是指用容器pop，而是改变之前数组，并返回长度』 双指针法 [cpp](./vsc_leetcode/27.移除元素.cpp)
- 2020.12.20 实现-str-str『返回首个合规子串索引：尝试了自己逐一搜索，有些乱，逻辑易出错；还可以尝试KMP与Rabin-Karp』 字符串 匹配 [遍历cpp](./vsc_leetcode/28.实现-str-str.cpp) [Rabin_Karp_cpp](./vsc_leetcode/28.实现-str-str_Rabin_Karp.cpp) [KMP_cpp](./vsc_leetcode/28.实现-str-str_kmp.cpp)
- 2020.12.22 搜索插入位置『遍历比较大小，当然，也可以二分法（首先应该想到二分法）』 搜索 分治法 [cpp](./vsc_leetcode/35.搜索插入位置.cpp) [二分法cpp](./vsc_leetcode/35.搜索插入位置_binarySearch.cpp)
- 2020.12.23 外观数列『①很典型的递归题目，注意cpp里字符串最后一位是转义0，引出可以妙用溢出②需要单独总结一下string库里的方法，如to_string等等』 字符串 递归 [cpp](./vsc_leetcode/38.外观数列.cpp) [递归cpp](./vsc_leetcode/38.外观数列_recursion.cpp)
- 2020.12.25 最大子序和『很经典的动态规划思想，前i个元素构成的数组，与当前x比较，pre+x小于x，则x自己另起炉灶，作为首个元素；此外还有结合线段树的分治法求解』 动态规划 分治法 [cpp](./vsc_leetcode/53.最大子序和.cpp) [分治法cpp](./vsc_leetcode/53.最大子序和_DandC.cpp)
- 2020.12.26 最后一个单词的长度『很基础的字符串搜索，要注意边界条件while中大于等于0』 搜索 字符串 [cpp](./vsc_leetcode/58.最后一个单词的长度.cpp)
- 2020.12.27 加一『考察思维严谨性，加一后，可能进位，并且可能造成连续的进位（如以99结尾）』 其他 [cpp](./vsc_leetcode/66.加一.cpp)
- 2020.12.29 两数相除『考察思维严谨性，注意：①int类型的负数下届比正数更大，因此可以统一为负数然后计算；②a+a>b与a-b+a>0数学意义相同，程序意义不同，前者更容易溢出』 其他 [cpp](./vsc_leetcode/29.两数相除.cpp)
- 2020.12.30 二进制求和『简单题目，可以分情况思考，然后用%等运算提取共性进行判断，精彩的三元表达式应用』 其他 [cpp](./vsc_leetcode/67.二进制求和.cpp)
- 2020.12.31 串联所有单词的子串『注意到单词是定长的、子串中单词顺序不重要，使用滑窗，left和right有点类似双指针的感觉；滑窗每次滑动长度为word.size()，因此注意起点有word.size()这么多个』 匹配 字符串 [cpp](./vsc_leetcode/30.串联所有单词的子串.cpp)
- 2021.1.3 下一个排列『在stl中有内置的next_permutation，这道题要求求出“紧邻”着的下一个排列，因此从后搜索，将尽可能小的大数与前面的小数交换，心中浮现柱状图可视化大小关系是个不错的选择；此外，为了相通方案的合理性，从最小的排列思考如何到下一个排列是一个不错的选择，或者，可以思考反例：如果不这样做某步...就会导致不对』 排序 [cpp](./vsc_leetcode/31.下一个排列.cpp)
- 2021.1.3 搜索旋转排序数组『见到有序数组，想到二分法；本题特征：一个有序数组切分成了2个，因此数组1最小值大于数组2最大值，比较指针l与r的值，即可判断当前区间上下界』 分治法 排序 [cpp](./vsc_leetcode/33.搜索旋转排序数组.cpp)
- 2021.1.4 在排序数组中查找元素的第一个和最后一个位置『〇、见有序想起二分法；一、二分法细节决定成败，具体看代码文件cpp，关于ans赋值问题；二、将问题转换：要找的就是数组中「第一个等于target的位置」和「第一个大于target的位置减一」三、提升代码可复用性，这个lower布尔值参数用的很妙』 分治法 [cpp](./vsc_leetcode/34.在排序数组中查找元素的第一个和最后一个位置.cpp)
- 2021.1.5 最长有效括号『三种做法：经典的动态规划（更新公式需要稍微推导一下）；栈与匹配（妙用栈顶、开始时压入-1）；考察思维严谨性的正逆向结合。具体解析都写在代码里了』 动态规划 匹配 栈 [动态规划cpp](./vsc_leetcode/32.最长有效括号_dp.cpp) [栈cpp](./vsc_leetcode/32.最长有效括号_stk.cpp) [正逆向结合cpp](./vsc_leetcode/32.最长有效括号.cpp)
- 2021.1.8 有效的数独『一次遍历，利用数学关系访问行、列、九宫格』 其他 [cpp](./vsc_leetcode/36.有效的数独.cpp)
