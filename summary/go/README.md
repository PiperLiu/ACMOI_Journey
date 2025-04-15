
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [IO](#io)
- [杂记](#杂记)
  - [嵌套的 map](#嵌套的-map)
  - [对于字符串别用 range](#对于字符串别用-range)
- [容器](#容器)
  - [Slice](#slice)

<!-- /code_chunk_output -->

### IO

你可以直接 Scanf ，但是会比较慢。

```go
package main

import ."fmt"

const N int = 110
var (
	n, m int
	g [N][N]int
	id = make(map[string]int)  // 不能只声明 map ，否则是 nil 指针
)

func main() {
	Scanf("%d %d", &m, &n)
	for i := 0; i < n; i ++ {
		var name string
		Scanf("%s", &name)
		id[name] = i
	}

	var name [N]string
	for m > 0 {
		m --
		for i := 0; i < n; i ++ {
			Scanf("%s", &name[i])
		}
	}
}
```

你可以用 bufio 加速。

```go
package main
// 从标准输入中读取
import ( "bufio"; ."fmt", "os"; )
func main() {
	in := bufio.NewReader(os.Stdin)
	res := 0
	for Fscan(in, &n); n > 0; n -- {
		var x, y int
		Fscan(in, &x, &y)
	}
}
```

对于 getline 可以如下。

如下来自灵佬 https://github.com/EndlessCheng/codeforces-go/blob/master/copypasta/io.go 。

```go
// 如果输入按照行来读入更方便的话……
// 数据个数未知 https://www.luogu.com.cn/problem/P2762
// 仅加速用 https://codeforces.com/problemset/problem/375/B
// 注意由于 buffer 的缘故，bufio.Scanner 不要和 bufio.Reader 混用
func lineIO(_r io.Reader, _w io.Writer) {
	in := bufio.NewScanner(_r)
	in.Buffer(nil, 1e9) // 若单个 token 大小超过 65536 则加上这行
	out := bufio.NewWriter(_w)
	defer out.Flush()

	for in.Scan() {
		line := in.Bytes()
		sp := bytes.Split(line, []byte{' '})
		// ...

		_ = sp
	}
}
```

输出小数：

```go
var value float64
fmt.Fprintf("%.6f\n", value)
```

### 杂记

#### 嵌套的 map

```go
var m = map[string]map[string]string{
	"a": map[string]string{
		"b": "c",
	},
}
```

#### 对于字符串别用 range

```go
for _, v := range s {
	fmt.Println(v)  // v 是 rune 而非 byte
	// 用 v := s[i] 来避免这个问题
}
```

### 容器

#### Slice

https://go.dev/wiki/SliceTricks
