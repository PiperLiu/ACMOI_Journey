package main
import ( "bufio"; ."fmt"; "os" )

const N int = 1010
var (
    n int
    dx = []int{-1, 0, 1, 0}
    dy = []int{0, 1, 0, -1}
    g [N][N]bool
)

func get(x, y int) (res int) {
    for i := 0; i < 4; i ++ {
        a, b := x + dx[i], y + dy[i]
        if g[a][b] {
            res ++
        }
    }
    return 
}

func main() {
    in := bufio.NewReader(os.Stdin)
    res := 0
    for Fscan(in, &n); n > 0; n -- {
        var x, y int
        Fscan(in, &x, &y)
        x ++
        y ++
        g[x][y] = true
        if get(x, y) == 3 {
            res ++
        }
        for i := 0; i < 4; i ++ {
            a, b := x + dx[i], y + dy[i]
            if g[a][b] {
                t := get(a, b)
                if t == 3 {
                    res ++
                } else if t == 4 {
                    res --
                }
            }
        }
        Println(res)
    }
}
