
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=4 orderedList=false} -->

<!-- code_chunk_output -->

- [高精度](#高精度)
  - [高精度加法与模板](#高精度加法与模板)

<!-- /code_chunk_output -->

### 高精度
适用于 C++ ，因为 java 或者 python 这种语言里都用数据结构对类型进行了封装。

对于数字 `123456789` ，应该放在数组中存储，注意是反过来的： `a[9] = {9,8,7,6,5,4,3,2,1}` 。

#### 高精度加法与模板
![](./images/20210510高精度加法.png)

如上，正常加法就行。

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    
    if (t) C.push_back(t); // 别忘了最高位可能进1
    
    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;
    
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    return 0;
}
```

经验：
- 用 `string` 接收，取出用 `.size()` 或者 `auto a: str`
- `a - '0'`是将数字字符串转为数值
- 定义 `vector<int> add(vector<int> &A, ...)`加上引用，是为了提高效率
