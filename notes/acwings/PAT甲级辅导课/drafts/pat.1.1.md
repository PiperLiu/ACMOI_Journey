
<!-- @import "[TOC]" {cmd="toc" depthFrom=3 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [A + B 格式](#a-b-格式)
- [拼写正确](#拼写正确)
- [签到与签出](#签到与签出)
- [密码](#密码)
- [男孩 vs 女孩](#男孩-vs-女孩)
- [字符串减法](#字符串减法)
- [说话方式](#说话方式)

<!-- /code_chunk_output -->

### A + B 格式

计算 $a + b$ 并以标准格式输出总和----也就是说，从最低位开始每隔三位数加进一个逗号（千位分隔符），如果结果少于四位则不需添加。

<h4>输入格式</h4>

共一行，包含两个整数 $a$ 和 $b$。

<h4>输出格式</h4>

共一行，以标准格式输出 $a+b$ 的和。

<h4>数据范围</h4>

$-10^6 \le a,b \le 10^6$

<h4>输入样例：</h4>

<pre><code>
-1000000 9
</code></pre>

<h4>输出样例：</h4>

<pre><code>
-999,991
</code></pre>

#### 1001 A+B Format (20 point(s))

Calculate $a+b$ and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

#### Input Specification:

Each input file contains one test case. Each case contains a pair of integers $a$ and $b$ where $−10^6 ≤a,b≤ 10^6$ . The numbers are separated by a space.

#### Output Specification:

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
```
-1000000 9
结尾无空行
```

Sample Output:
```
-999,991
结尾无空行
```

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a = a + b;
    string s = to_string(a);
    string res;
    
    for (int i = s.size() - 1, j = 0; i >= 0; -- i)
    {
        res = s[i] + res;
        j ++ ;
        if (j % 3 == 0 && i && s[i - 1] != '-') res = ',' + res;
    }
    
    cout << res << endl;
}
```

### 拼写正确

给定一个非负整数 $N$，你的任务是计算 $N$ 的所有数字的总和，并以英语输出总和的每个数字。

<h4>输入格式</h4>

共一行，包含一个整数 $N$。

<h4>输出格式</h4>

<p>共一行，用英语输出总和的每个数字，单词之间用空格隔开。</p>

<h4>数据范围</h4>

$0 \le N \le 10^{100}$

<h4>输入样例：</h4>

<pre><code>
12345
</code></pre>

<h4>输出样例：</h4>

<pre><code>
one five
</code></pre>

#### 1005 Spell It Right (20 point(s))
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

#### Input Specification:
Each input file contains one test case. Each case occupies one line which contains an $N (≤10^{100})$.

#### Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int num = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++ i)
    {
        num += s[i] - '0';
    }
    string str = to_string(num);
    
    string res;
    char word[10][10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine",
    };
    
    // 先输出第 0 个数字，这样保证最后不多空格
    cout << word[str[0] - '0'];
    for (int i = 1; i < str.size(); ++ i)
    {
        cout << " " << word[str[i] - '0'];
    }
}
```

**经验：**
- PAT 要求同一行输出最后不能多空格，因此这里先输出第 0 个元素，之后输出 `" " << 第 i 个元素`

### 签到与签出

<p>每天第一个到机房的人负责开门，最后一个从机房离开的人负责锁门。</p>

<p>现在，给定每个人的签到与签出记录，请你找出当天开门的人以及锁门的人分别是谁。</p>

<h4>输入格式</h4>

第一行包含整数 $M$，表示共有 $M$ 个人的签到签出记录。

接下来 $M$ 行，每行的形式如下：

<pre><code>
ID_number Sign_in_time Sign_out_time
</code></pre>

时间以 <code>HH:MM:SS</code> 形式给出，<code>ID_number</code> 是一个长度不超过 $15$ 的字符串。

<h4>输出格式</h4>

共一行，输出开门人和锁门人的<code>ID_number</code>，用一个空格隔开。

<h4>数据范围</h4>
- $1 \le M \le 10$
- 数据保证每个人的签到时间早于签出时间，并且不会出现两个人同时签到或同时签出的情况。

<h4>输入样例：</h4>

<pre><code>
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
</code></pre>

<h4>输出样例：</h4>

<pre><code>
SC3021234 CS301133
</code></pre>

#### 1006 Sign In and Sign Out (25 point(s))
At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

#### Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

```
ID_number Sign_in_time Sign_out_time
```

where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

#### Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int m;
    cin >> m;
    
    string open_id, open_time;
    string close_id, close_time;
    
    for (int i = 0; i < m; ++ i)
    {
        string id, in_time, leave_time;
        cin >> id >> in_time >> leave_time;
        
        if (!i || in_time < open_time)
        {
            open_time = in_time;
            open_id = id;
        }
        
        if (!i || leave_time > close_time)
        {
            close_time = leave_time;
            close_id = id;
        }
    }
    
    cout << open_id << " " << close_id;
}
```

**经验：**
- 用 `if (!i || ...)` 将第 0 个元素赋给用于记录比较的值
- `HH:MM:SS` 字典序可以用 `string` 自带的运算符 `<` 等排序

### 密码

<p>为了准备 PAT，系统不得不为用户生成随机密码。</p>

但是有时一些数字和字母之间总是难以区分，比如 <code>1</code>（数字一）和 <code>l</code>（$L$ 的小写），<code>0</code>（数字零）和 <code>O</code>（$o$ 的大写）。

一种解决办法是将 <code>1</code>（数字一）替换为 <code>@</code>，将 <code>0</code>（数字零）替换为 <code>%</code>，将 <code>l</code>（$L$ 的小写）替换为 <code>L</code>，将 <code>O</code>（$o$ 的大写）替换为 <code>o</code>。

<p>现在，你的任务就是帮助系统检查这些用户的密码，并对难以区分的部分加以修改。</p>

<h4>输入格式</h4>

第一行包含一个整数 $N$，表示用户数量。

接下来 $N$ 行，每行包含一个用户名和一个密码，都是长度不超过 $10$ 且不含空格的字符串。

<h4>输出格式</h4>

首先输出一个整数 $M$，表示已修改的用户密码数量。

接下来 $M$ 行，每行输出一个用户名称和其修改后的密码。

<p>用户的输出顺序和读入顺序必须相同。</p>

如果没有用户的密码被修改，则输出 <code>There are N accounts and no account is modified</code>，其中 $N$ 是用户总数。

如果 $N = 1$，则应该输出 <code>There is 1 account and no account is modified</code>。

<h4>数据范围</h4>

$1 \le N \le 1000$

<h4>输入样例1：</h4>

<pre><code>
3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
2
Team000002 RLsp%dfa
Team000001 R@spodfa
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
1
team110 abcdefg332
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
There is 1 account and no account is modified
</code></pre>

<h4>输入样例3：</h4>

<pre><code>
2
team110 abcdefg222
team220 abcdefg333
</code></pre>

<h4>输出样例3：</h4>

<pre><code>
There are 2 accounts and no account is modified
</code></pre>

#### 1035 Password (20 point(s))
To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.

#### Input Specification:
Each input file contains one test case. Each case contains a positive integer N (≤1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

#### Output Specification:
For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line There are N accounts and no account is modified where N is the total number of accounts. However, if N is one, you must print There is 1 account and no account is modified instead.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
string name[N], pwd[N];

string change(string s)
{
    string res;
    
    for (auto t: s)
    {
        if (t == '1') res += '@';
        else if (t == '0') res += '%';
        else if (t == 'l') res += 'L';
        else if (t == 'O') res += 'o';
        else res += t;
    }
    
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    int m = 0;
    
    for (int i = 0; i < n; i ++ )
    {
        string cur_name, cur_pwd;
        cin >> cur_name >> cur_pwd;
        
        string changed_pwd = change(cur_pwd);
        if (changed_pwd != cur_pwd)
        {
            name[m] = cur_name;
            pwd[m] = changed_pwd;
            m ++;
        }
    }
    
    if (m == 0)
    {
        if (n == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", n);
    }
    else
    {
        printf("%d\n", m);
        for (int i = 0; i < m; i ++ )
        {
            cout << name[i] << " " << pwd[i] << endl;
        }
    }
}
```

### 男孩 vs 女孩

给定 $N$ 个学生的成绩信息，请你求出女生第一名与男生倒数第一名的分数差距。

<h4>输入格式</h4>

第一行输入整数 $N$，表示学生数量。

接下来 $N$ 行，每行包含一个学生的姓名，性别，ID和成绩。其中姓名和ID是长度不超过 $10$ 且不包含空格的字符串。性别为 $F$（女）或 $M$（男）。成绩是一个范围在 $[0,100]$ 的整数。保证所有学生的成绩互不相同。

<h4>输出格式</h4>

<p>输出共三行。</p>

<p>第一行输出女生第一名的姓名和ID。</p>

<p>第二行输出男生倒数第一名的姓名和ID。</p>

<p>第三行输出女生第一名的成绩减去男生倒数第一名的成绩的差。</p>

<p>如果不存在某个性别的学生，则在对应行输出 <code>Absent</code>。</p>

<p>在第三行输出 <code>NA</code>。</p>

<h4>数据范围</h4>

$1 \le N \le 101$

<h4>输入样例1：</h4>

<pre><code>
3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
</code></pre>

<h4>输出样例1：</h4>

<pre><code>
Mary EE990830
Joe Math990112
6
</code></pre>

<h4>输入样例2：</h4>

<pre><code>
1
Jean M AA980920 60
</code></pre>

<h4>输出样例2：</h4>

<pre><code>
Absent
Jean AA980920
NA
</code></pre>

#### 1036 Boys vs Girls (25 point(s))

This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

#### Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

#### Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference $grade_F − grade_
M$ . If one such kind of student is missing, output Absent in the corresponding line, and output NA in the third line instead.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string highest_girl_name, highest_girl_id;
    int highest_girl_score;
    string lowest_boy_name, lowest_boy_id;
    int lowest_boy_score;
    for (int i = 0; i < n; ++ i)
    {
        string name, gender, id;
        int score;
        cin >> name >> gender >> id >> score;
        if (gender == "F")
        {
            if (highest_girl_name.empty() || score > highest_girl_score)
            {
                highest_girl_name = name;
                highest_girl_id = id;
                highest_girl_score = score;
            }
        }
        else
        {
            if (lowest_boy_name.empty() || score < lowest_boy_score)
            {
                lowest_boy_name = name;
                lowest_boy_id = id;
                lowest_boy_score = score;
            }
        }
    }
    
    if (highest_girl_name.empty())
        cout << "Absent" << endl;
    else cout << highest_girl_name << " " << highest_girl_id << endl;
    
    if (lowest_boy_name.empty())
        cout << "Absent" << endl;
    else cout << lowest_boy_name << " " << lowest_boy_id << endl;
    
    if (highest_girl_name.empty() || lowest_boy_name.empty())
        cout << "NA" << endl;
    else cout << highest_girl_score - lowest_boy_score << endl;
}
```

### 字符串减法

给定两个字符串 $S_1$ 和 $S_2$，$S = S_1-S_2$ 定义为将 $S_1$ 中包含的所有在 $S_2$ 中出现过的字符删除后得到的字符串。

你的任务就是计算 $S_1 - S_2$。

<h4>输入格式</h4>

共两行，第一行包含字符串 $S_1$，第二行包含字符串 $S_2$。

<h4>输出格式</h4>

输出共一行，表示 $S_1 - S_2$ 的结果。

<h4>数据范围</h4>

两个给定字符串的长度都不超过 $10^4$。

<h4>输入样例：</h4>

<pre><code>
They are students.
aeiou
</code></pre>

<h4>输出样例：</h4>

<pre><code>
Thy r stdnts.
</code></pre>

#### 1050 String Subtraction (20 point(s))
Given two strings $S_1$ and $S_2$, $S=S_1 − S_2$ is defined to be the remaining string after taking all the characters in $S_2$ from $S_1$. Your task is simply to calculate $S_1 − S_2$ for any given strings. However, it might not be that simple to do it fast.

#### Input Specification:
Each input file contains one test case. Each case consists of two lines which gives $S_1$ and $S_2$, respectively. The string lengths of both strings are no more than $10^4$. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

#### Output Specification:
For each test case, print $S_1 − S_2$ in one line.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    unordered_set<int> hash;
    for (auto c: s2)
    {
        hash.insert(c);
    }
    
    string res;
    for (auto c: s1)
    {
        if (!hash.count(c))
            res += c;
    }
    
    cout << res << endl;
}
```

**经验：**
- C++ 用 `getline(cin, string实例)` 来读一整行，包括空格

### 说话方式

<p>不同的人对描述同一种事物的同义词的偏爱程度可能不同。</p>

<p>例如，在说警察时，有人喜欢用 <code>the police</code>，有人喜欢用 <code>the cops</code>。</p>
<p>分析说话方式有助于确定说话者的身份，这在验证诸如和你线上聊天的是否是同一个人十分有用。</p>

<p>现在，给定一段从某人讲话中提取的文字，你能确定他的最常用词吗？</p>

<h4>输入格式</h4>

<p>输入共一行，包含一个字符串，以回车符 <code>\n</code> 终止。</p>

<h4>输出格式</h4>

<p>共一行，输出最常用词以及其出现次数。</p>

<p>如果常用词有多个，则输出字典序最小的那个单词。</p>

<p>注意，单词在输出时，必须全部小写。</p>

<p>单词是指由连续的字母和数字构成的，被非字母数字字符或行首/行尾分隔开的，连续序列。</p>

<p>单词不区分大小写。</p>

<h4>数据范围</h4>

输入字符串长度不超过 $1048576$，且至少包含一个大小写字母或数字。

<h4>输入样例：</h4>

<pre><code>
Can1: Can a can can a can?  It can!
</code></pre>

<h4>输出样例：</h4>

<pre><code>
can 5
</code></pre>

#### 1071 Speech Patterns (25 point(s))

People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

#### Input Specification:
Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return `\n`. The input contains at least one alphanumerical character, i.e., one character from the set `[0-9 A-Z a-z]`.

#### Output Specification:
For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool check(char x)
{
    if (x >= '0' && x <= '9') return true;
    else if (x >= 'a' && x <= 'z') return true;
    else if (x >= 'A' && x <= 'Z') return true;
    
    return false;
}

char to_lower(char x)
{
    if (x >= 'A' && x <= 'Z')
        return x + 'a' - 'A';
    return x;
}

int main()
{
    string str;
    getline(cin, str);
    
    unordered_map<string, int> hash;
    
    for (int i = 0; i < str.size(); ++ i)
    {
        if (check(str[i]))
        {
            string word;
            int j = i;
            while (j < str.size() && check(str[j])) word += to_lower(str[j ++]);
            i = j;
            hash[word] ++;
        }
    }
    
    string word;
    int cnt = -1;
    for (auto item: hash)
    {
        if (item.second > cnt || item.second == cnt && item.first < word)  // 相同的取字典序靠前的
        {
            word = item.first;
            cnt = item.second;
        }
    }
    
    cout << word << " " << cnt;
}
```
