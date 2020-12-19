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
### 匹配
- 整数转罗马数字『生活中从大的位数开始描述数字，因此从大的数与字符开始匹配』 [cpp](./vsc_leetcode/12.整数转罗马数字.cpp) 2020.11.27
- 罗马数字转整数『总结其中规律：从左开始搜索，如果左边字符小于右，则减去左字符，否则加；对于最右侧字符，一定是用来加的』 [cpp](./vsc_leetcode/13.罗马数字转整数.cpp) 2020.11.28
- 最长公共前缀『是所有字符串前缀的交集，因此0与1取交集，其结果与2取交集...』 [cpp](./vsc_leetcode/14.最长公共前缀.cpp) 2020.11.29
- 有效的括号『先出现的左括号后匹配，因此，可以根据该特点使用栈，匹配了，就出栈，最后所有左括号成功出栈，则匹配成功』 [cpp](./vsc_leetcode/20.有效的括号.cpp) 2020.12.6

### 字符串
- 整数转罗马数字『生活中从大的位数开始描述数字，因此从大的数与字符开始匹配』 [cpp](./vsc_leetcode/12.整数转罗马数字.cpp) 2020.11.27
- 罗马数字转整数『总结其中规律：从左开始搜索，如果左边字符小于右，则减去左字符，否则加；对于最右侧字符，一定是用来加的』 [cpp](./vsc_leetcode/13.罗马数字转整数.cpp) 2020.11.28
- 最长公共前缀『是所有字符串前缀的交集，因此0与1取交集，其结果与2取交集...』 [cpp](./vsc_leetcode/14.最长公共前缀.cpp) 2020.11.29
- 电话号码的字母组合『使用很简单的、直观的递归实现深度优先搜索多层次的遍历，每搜索到最后一层，将该字符串推入结果数组』 [cpp](./vsc_leetcode/17.电话号码的字母组合.cpp) 2020.12.3
- 有效的括号『先出现的左括号后匹配，因此，可以根据该特点使用栈，匹配了，就出栈，最后所有左括号成功出栈，则匹配成功』 [cpp](./vsc_leetcode/20.有效的括号.cpp) 2020.12.6
- 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 [cpp](./vsc_leetcode/22.括号生成.cpp) 2020.12.8

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

### 递归
- 合并两个有序链表『很典型的适于递归的题目，递归函数返回下一状态的结果指针』 [cpp](./vsc_leetcode/21.合并两个有序链表.cpp) 2020.12.7
- 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 [cpp](./vsc_leetcode/22.括号生成.cpp) 2020.12.8
- 合并k个升序链表『总体上，对链表们分治合并，见函数merge，使用递归实现，包括l、r、情况处理（递归的出口）、mid由位运算求、尾递归调用等经典操作，值得记忆』 [cpp](./vsc_leetcode/23.合并k个升序链表.cpp) 2020.12.9
- 两两交换链表中的节点『很简单的一道递归题目，两两交换时，定义一个临时指针newHead』 [cpp](./vsc_leetcode/24.两两交换链表中的节点.cpp) 2020.12.11

### 回溯
- 括号生成『典型递归回溯，根据左右括号数量平衡这个特点进行剪枝，cpp中定义回溯函数为backtrack；此外，注意函数参数的定义如string&和全局的返回值设置方式』 [cpp](./vsc_leetcode/22.括号生成.cpp) 2020.12.8

### 分治法
- 合并k个升序链表『总体上，对链表们分治合并，见函数merge，使用递归实现，包括l、r、情况处理（递归的出口）、mid由位运算求、尾递归调用等经典操作，值得记忆』 [cpp](./vsc_leetcode/23.合并k个升序链表.cpp) 2020.12.9
- 二分查找『对于已经排好序的数组，使用经典的二分查找，需要注意：为了防止溢出pivot=left+（right-left）/2、left=pivot+1等技巧』 [cpp](./vsc_leetcode/704.二分查找.cpp) 2020.12.10

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
