// 没有两名实验室成员的资历相同
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
        for i := 0; i < n; i ++ {
            j := i + 1  // 寻找字典序之外的
            for j < n && name[j] > name[j - 1] { j ++ }
            for j < n {  // 可确定从 j 开始一定高于 i
                a := id[name[i]]
                b := id[name[j]]
                g[a][b] = 1  // a 比 b 高一定矛盾
                j ++
            }
        }
    }

    // 输出
    for i := 0; i < n; i ++ {
        for j := 0; j < n; j ++ {
            if i == j {
                Print("B")
            } else if g[i][j] == 0 && g[j][i] == 0 {
                Print("?")
            } else if g[i][j] == 0 {
                Print(1)
            } else {
                Print(0)
            }
        }
        Println()
    }
}
