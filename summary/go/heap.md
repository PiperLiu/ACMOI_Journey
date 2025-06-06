# 理解 Golang 中的最大/最小堆、`heap` 与优先队列

参考：
- https://pkg.go.dev/container/heap
- https://github.com/EndlessCheng/codeforces-go/blob/master/copypasta/heap.go 灵佬笔记，非常有用

在算法题目中，我们经常遇到需要动态维护一个集合的最值（最大或最小值）的场景，例如找出动态数据流中的第 K 大元素、Dijkstra 算法中的节点松弛操作等。这些场景的共同特点是，我们不仅需要找到当前的最值，还需要高效地添加新元素和删除最值。 **优先队列 (Priority Queue)** 是实现这种操作的理想抽象数据结构，而 **堆 (heap)** 则是实现优先队列最常用、最高效的具体数据结构。

Golang 的标准库 `container/heap` 提供了一套堆操作的算法。需要注意的是，它并没有提供一个可以直接使用的、开箱即用的堆类型，而是定义了一个需要用户自己实现的接口 `heap.Interface` 。用户需要提供一个满足该接口的数据类型（通常是一个切片），`container/heap` 包中的函数，如 `heap.Push` 和 `heap.Pop` ，会基于用户提供的类型来维护堆的性质。

这种设计体现了 Go 语言接口的哲学：定义行为，而不是具体实现。它给予了开发者极大的灵活性，让我们可以对任意类型的集合实现堆操作，无论是整数、字符串还是自定义的结构体。

---

## `heap.Interface` 与官方示例

要使用 `container/heap` 包，我们首先需要理解它所依赖的核心接口——`heap.Interface`。

```go
// A Interface is a type that can be used as a min-heap.
// Methods of this interface are documented in the heap package.
type Interface interface {
    sort.Interface // 内嵌了 sort.Interface
    Push(x any)    // add x as element Len()
    Pop() any      // remove and return element Len() - 1.
}
```

可以看到，`heap.Interface` 内嵌了 `sort.Interface`。这意味着任何想要实现堆操作的类型，都必须首先实现 `sort.Interface`，即以下三个方法：
- `Len() int`: 返回集合中元素的数量。
- `Less(i, j int) bool`: 比较索引 `i` 和 `j` 处的元素。如果 `h[i]` 应该排在 `h[j]` 前面，则返回 `true`。对于 **最小堆** ，这意味着 `h[i] < h[j]`；对于 **最大堆** ，则是 `h[i] > h[j]`。
- `Swap(i, j int)`: 交换索引 `i` 和 `j` 处的元素。

除此之外，还需要实现两个特定于堆的方法：
- `Push(x any)`: 在集合的“末尾”添加一个新元素 `x`。通常，这意味着将元素 `append` 到切片的末尾。
- `Pop() any`: 从集合的“末尾”移除并返回一个元素。通常，这意味着移除并返回切片的最后一个元素。

**一个常见的困惑** ：为什么 `Pop` 方法是移除 *最后一个* 元素，而不是堆顶元素（索引为 0 的元素）？这正是 `container/heap` 包算法设计的巧妙之处。当我们调用 `heap.Pop(h)` 时，该函数会：
1.  首先将堆顶元素（`h[0]`）与堆的最后一个元素（`h[len(h)-1]`）交换位置。
2.  此时，原本的最值（最小或最大元素）已经被移动到了切片的末尾。
3.  然后，`heap.Pop` 会调用我们自己实现的 `Pop()` 方法。我们的 `Pop()` 方法只需要简单地移除并返回切片的最后一个元素即可，这个元素正是我们所需要的原堆顶元素。
4.  最后，`heap.Pop` 内部会调整堆，使得除最后一个元素外，剩下的 `n-1` 个元素重新满足堆的性质。

接下来，我们通过官方文档的两个例子来具体理解这个过程。

### 示例一：整数最小堆

这个例子展示了如何基于 `[]int` 切片构建一个整数最小堆。

```go
// 该示例演示了如何使用 heap 接口构建一个整数最小堆。
package main

import (
    "container/heap"
    "fmt"
)

// IntHeap 是一个整数最小堆。它本质上是一个 int 类型的切片。
type IntHeap []int

// Len 返回切片的长度。
func (h IntHeap) Len() int { return len(h) }

// Less 用于定义元素间的大小关系。对于最小堆，如果 h[i] < h[j]，则返回 true。
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }

// Swap 交换切片中两个元素的位置。
func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

// Push 在切片末尾添加一个元素。
// 注意：Push 和 Pop 方法使用指针接收者 (*IntHeap)，因为它们需要修改切片的长度，而不仅仅是内容。
func (h *IntHeap) Push(x any) {
    *h = append(*h, x.(int))
}

// Pop 从切片末尾移除并返回元素。
func (h *IntHeap) Pop() any {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

// 这个例子向 IntHeap 中插入了几个整数，检查了最小值，并按优先级顺序将它们移除。
func main() {
    // 创建一个 IntHeap 实例，并初始化。
    h := &IntHeap{2, 1, 5}
    heap.Init(h) // 将无序的切片整理成一个最小堆。

    // 向堆中推入一个新元素。
    heap.Push(h, 3)

    // 堆顶元素 h[0] 即为最小值。
    fmt.Printf("minimum: %d\n", (*h)[0]) // 输出 "minimum: 1"

    // 持续从堆中弹出元素，直到堆为空。
    // 弹出的顺序将是从小到大。
    for h.Len() > 0 {
        fmt.Printf("%d ", heap.Pop(h)) // 输出 "1 2 3 5 "
    }
}
```

```txt
minimum: 1
1 2 3 5
```

### 示例二：使用堆实现优先队列

这个例子更进一步，展示了如何用堆实现一个管理复杂对象的优先队列，并且支持在队列中修改元素的优先级。

```go
// 该示例演示了如何使用 heap 接口构建一个优先队列。
package main

import (
    "container/heap"
    "fmt"
)

// Item 是我们在优先队列中管理的元素。
type Item struct {
    value    string // 元素的值，可以是任意类型。
    priority int    // 元素在队列中的优先级。
    // index 字段对于 update 方法至关重要。
    // 它由 heap.Interface 的方法（特别是 Swap）来维护。
    index int // 元素在堆中的索引。
}

// PriorityQueue 实现了 heap.Interface 接口，并持有 Item 类型的元素。
// 它是一个 Item 指针的切片。
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
    // 我们希望 Pop 返回的是最高优先级的元素，而不是最低的，
    // 所以这里我们使用 > （大于号）。
    return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
    // 交换元素
    pq[i], pq[j] = pq[j], pq[i]
    // **关键**：交换元素后，必须同时更新它们在堆中的 index。
    pq[i].index = i
    pq[j].index = j
}

func (pq *PriorityQueue) Push(x any) {
    n := len(*pq)
    item := x.(*Item)
    // 设置新元素的初始 index。
    item.index = n
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
    old := *pq
    n := len(old)
    item := old[n-1]
    old[n-1] = nil  // 避免内存泄漏
    item.index = -1 // for safety
    *pq = old[0 : n-1]
    return item
}

// update 方法修改队列中一个 Item 的优先级和值。
func (pq *PriorityQueue) update(item *Item, value string, priority int) {
    item.value = value
    item.priority = priority
    // 在修改了优先级后，元素在堆中的位置可能不再正确，
    // 因此需要调用 heap.Fix 来恢复堆的属性。
    heap.Fix(pq, item.index)
}

func main() {
    // 一些元素和它们的优先级。
    items := map[string]int{
        "banana": 3, "apple": 2, "pear": 4,
    }

    // 创建优先队列，将元素放入其中，并建立堆的不变性。
    pq := make(PriorityQueue, len(items))
    i := 0
    for value, priority := range items {
        pq[i] = &Item{
            value:    value,
            priority: priority,
            index:    i,
        }
        i++
    }
    heap.Init(&pq) // 初始化堆

    // 插入一个新元素，然后修改它的优先级。
    item := &Item{
        value:    "orange",
        priority: 1,
    }
    heap.Push(&pq, item)
    pq.update(item, item.value, 5) // 将 orange 的优先级从 1 更新到 5

    // 按优先级从高到低的顺序取出所有元素。
    for pq.Len() > 0 {
        item := heap.Pop(&pq).(*Item)
        fmt.Printf("%.2d:%s ", item.priority, item.value)
        // 输出: "05:orange 04:pear 03:banana 02:apple "
    }
}
```

```txt
05:orange 04:pear 03:banana 02:apple
```

### `container/heap` 核心 API

现在我们来详细解释一下 `heap` 包提供的几个核心函数：

-   `func Init(h Interface)` 此函数用于将一个无序的、满足 `Interface` 的数据集合整理成一个合法的堆。它的实现方式是从最后一个非叶子节点开始，自下而上、自右向左地对每个子树调用 `down`（一个内部函数）进行调整，使其满足堆的性质。时间复杂度为 O(n)，比逐个 `Push` 元素（O(n log n)）更高效。

-   `func Push(h Interface, x any)` 向堆 `h` 中添加一个新元素 `x`。它首先调用用户定义的 `Push(x)` 方法将元素添加到数据集合的末尾，然后调用 `up`（一个内部函数）将这个新元素“上浮”到它在堆中的正确位置。时间复杂度为 O(log n)。

-   `func Pop(h Interface) any` 从堆 `h` 中移除并返回堆顶元素（最小值或最大值）。如前所述，它通过将堆顶元素与最后一个元素交换，然后调用用户定义的 `Pop()` 方法来实现。之后，它会调用 `down` 将新的堆顶元素“下沉”到正确位置，以维持堆的性质。时间复杂度为 O(log n)。

-   `func Remove(h Interface, i int) any` 移除并返回堆中索引为 `i` 的元素。这是一个更通用的删除操作。它的实现方式是将索引 `i` 的元素与最后一个元素交换，然后移除最后一个元素（即我们想删除的元素），最后对交换到位置 `i` 的新元素进行调整（可能上浮也可能下沉）来恢复堆的性质。时间复杂度为 O(log n)。

-   `func Fix(h Interface, i int)` 当用户直接修改了堆中索引为 `i` 的元素的值（比如 `PriorityQueue` 例子中的 `update` 操作），这个元素的位置可能就不再满足堆的性质了。此时应调用 `Fix(h, i)`，该函数会自动地将该元素上浮或下沉到它新的正确位置，从而恢复整个堆的性质。`i` 就是被修改元素在底层切片中的索引。

## 堆的内存布局

我们有必要先理解堆在内存中是如何存储的。

从逻辑上讲，堆是一个 **完全二叉树 (Complete Binary Tree)** 。这意味着除了最底层外，其他层都是完全填满的，并且最底层的节点都尽可能地靠左排列。然而，在物理存储上，堆并不会像链表那样使用指针来连接父子节点。相反，它被巧妙地存储在一个连续的内存空间中，比如 Golang 中的 **切片 (slice)** 或数组。

这种设计带来了巨大的性能优势：它不需要额外的指针开销，并且由于数据是连续存储的，可以更好地利用 CPU 缓存，提高访问效率。

我们通过切片的索引 `i` 就可以计算出任意节点的父节点和子节点的索引：
-   假设一个节点的索引为 `i`（`i` 从 0 开始）：
-   它的左子节点的索引是 `2*i + 1`
-   它的右子节点的索引是 `2*i + 2`
-   它的父节点的索引是 `(i - 1) / 2` （整数除法，自动向下取整）

例如，对于一个最小堆，其切片为 `[3, 5, 8, 10, 7]`，它的逻辑树形结构如下：

```txt
    逻辑树形结构              物理切片存储

        3 (i=0)               Index: 0  1  2  3  4
       /   \                  Value: [3, 5, 8, 10, 7]
      /     \
    5 (i=1)  8 (i=2)
   /   \
  /     \
10(i=3) 7(i=4)
```

-   节点 `3` (i=0) 的左子节点是 `2*0 + 1 = 1`，即 `5`；右子节点是 `2*0 + 2 = 2`，即 `8`。
-   节点 `5` (i=1) 的父节点是 `(1 - 1) / 2 = 0`，即 `3`。

`container/heap` 包中的所有算法，如 `up` 和 `down`，都是基于这个索引计算规则来操作底层切片，从而高效地维护堆的逻辑结构和性质。

---

## 实用模板与技巧

在解决算法问题时，为了提高编码效率，我们可以定义一些可复用的堆模板。

### 模板一：利用内嵌 `sort.IntSlice`

`sort.IntSlice` 已经为 `[]int` 实现了 `Len`、`Less` 和 `Swap` 方法。通过在我们的堆类型中 **内嵌 (embedding)** `sort.IntSlice`，我们可以自动获得这些方法的实现，从而只需要编写 `Push` 和 `Pop` 即可。

**内嵌语法解释** ：在 `struct` 中写下一个没有字段名的类型（如 `type hp struct{ sort.IntSlice }`），就是内嵌。这使得 `hp` 的实例可以直接访问 `sort.IntSlice` 的方法和字段。在 `Push` 方法中，`h.IntSlice = append(h.IntSlice, v.(int))` 这行代码中，`h.IntSlice` 就是访问内嵌的 `sort.IntSlice` 字段，它本身就是一个 `[]int`。

```go
package main

import (
    "container/heap"
    "fmt"
    "sort"
)

// hp 是一个最小堆。
// 它内嵌了 sort.IntSlice，自动获得了 Len, Less, Swap 方法。
type hp struct{ sort.IntSlice }

// 如果需要最大堆，只需覆盖 Less 方法即可。
// func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }

func (h *hp) Push(v any) {
    h.IntSlice = append(h.IntSlice, v.(int))
}

func (h *hp) Pop() any {
    a := h.IntSlice
    v := a[len(a)-1]
    h.IntSlice = a[:len(a)-1]
    return v
}

// 为了方便使用，可以封装类型安全的 push 和 pop 方法。
func (h *hp) push(v int) {
    heap.Push(h, v)
}

func (h *hp) pop() int {
    return heap.Pop(h).(int)
}

// replace 弹出并返回堆顶，同时将新元素 v 入堆。
// 相比 pop + push，效率更高，因为它只需要一次堆调整。
// 要求 h 非空。
func (h *hp) replace(v int) int {
    top := h.IntSlice[0]
    h.IntSlice[0] = v
    heap.Fix(h, 0) // 调整堆顶元素
    return top
}

// pushPop 先将 v 入堆，然后弹出并返回堆顶。
func (h *hp) pushPop(v int) int {
    // 如果新元素 v 比堆顶还小（最小堆），
    // 那么 v 将成为新的堆顶并被立即弹出，堆本身不变。
    // 所以只有当 v > h.IntSlice[0] 时才需要操作。
    if h.Len() > 0 && v > h.IntSlice[0] { // 最大堆则为 v < h.IntSlice[0]
        v, h.IntSlice[0] = h.IntSlice[0], v // 交换新元素和堆顶
        heap.Fix(h, 0)                      // 调整新的堆顶
    }
    return v
}

func main() {
    // 这是一个可以直接运行的 hp 示例
    minHeap := &hp{}

    minHeap.push(4)
    minHeap.push(1)
    minHeap.push(7)

    fmt.Println("堆顶（最小值）:", (*minHeap).IntSlice[0]) // 输出 1

    popped := minHeap.pop()
    fmt.Println("弹出:", popped) // 输出 1

    fmt.Println("新的堆顶:", (*minHeap).IntSlice[0]) // 输出 4

    replacedVal := minHeap.replace(0)
    fmt.Println("被替换的堆顶:", replacedVal)      // 输出 4
    fmt.Println("替换后的堆顶:", (*minHeap).IntSlice[0]) // 输出 0
}
```

```txt
堆顶（最小值）: 1
弹出: 1
新的堆顶: 4
被替换的堆顶: 4
替换后的堆顶: 0
```

### 模板二：自定义类型堆

当我们需要处理 `int32`、`float64` 或其他非 `int` 类型时，只需定义一个新的类型并实现完整的 `heap.Interface`。

```go
package main

import (
    "container/heap"
    "fmt"
)

// 自定义 int32 类型的最小堆
type hp32 []int32

func (h hp32) Len() int           { return len(h) }
func (h hp32) Less(i, j int) bool { return h[i] < h[j] } // > 为最大堆
func (h hp32) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp32) Push(v any)        { *h = append(*h, v.(int32)) }
func (h *hp32) Pop() any {
    a := *h
    v := a[len(a)-1]
    *h = a[:len(a)-1]
    return v
}
func (h *hp32) push(v int32) { heap.Push(h, v) }
func (h *hp32) pop() int32   { return heap.Pop(h).(int32) }

func main() {
    // 这是一个可以直接运行的 hp32 示例
    h := &hp32{100, 50, 200}
    heap.Init(h)

    fmt.Println("初始化后的堆顶:", (*h)[0]) // 输出 50

    h.push(25)
    fmt.Println("Push 25 后的堆顶:", (*h)[0]) // 输出 25

    fmt.Println("按顺序弹出:")
    for h.Len() > 0 {
        fmt.Printf("%d ", h.pop()) // 输出 25 50 100 200
    }
    fmt.Println()
}
```

```txt
初始化后的堆顶: 50
Push 25 后的堆顶: 25
按顺序弹出:
25 50 100 200
```

### 模板三：支持修改与删除的堆

这个模板借鉴了官方 `PriorityQueue` 的思路，通过在堆中存储指针，并维护每个元素在堆中的索引，从而实现了对堆中任意元素的修改和删除。这在一些复杂的算法题中非常有用。

```go
package main

import (
    "container/heap"
    "fmt"
)

// viPair 包含一个值 v 和它在堆中的索引 hi。
type viPair struct {
    v  int
    hi int // *viPair 在 mh 中的下标，可随着 Push/Pop 等操作自动改变
}

// mh (modifiable heap) 是一个支持修改的最小堆。
type mh []*viPair

func (h mh) Len() int           { return len(h) }
func (h mh) Less(i, j int) bool { return h[i].v < h[j].v } // > 为最大堆
func (h mh) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
    // 关键：交换元素后，必须更新它们的索引 hi
    h[i].hi = i
    h[j].hi = j
    fmt.Println(h[i], h[j])
}
func (h *mh) Push(v any) { *h = append(*h, v.(*viPair)) }
func (h *mh) Pop() any {
    a := *h
    v := a[len(a)-1]
    *h = a[:len(a)-1]
    return v
}

// push 会返回一个指向新元素的指针，外部可以持有该指针。
func (h *mh) push(v int) *viPair {
    p := &viPair{v: v, hi: len(*h)}
    heap.Push(h, p)
    return p
}
func (h *mh) pop() *viPair       { return heap.Pop(h).(*viPair) }
func (h *mh) fix(i int)          { heap.Fix(h, i) }
func (h *mh) remove(i int) *viPair { return heap.Remove(h, i).(*viPair) }

func main() {
    // 这是一个可以直接运行的 mh 示例
    h := &mh{}

    // 推入元素并保存它们的指针（句柄）
    p1 := h.push(10)
    h.push(5)
    p3 := h.push(15)

    fmt.Printf("初始堆顶: %d (索引 %d)\n", (*h)[0].v, (*h)[0].hi) // 5 (索引 0)

    // 修改 p1 的值，它当前不在堆顶
    fmt.Printf("修改前 p1 的值: %d, 在堆中索引为: %d\n", p1.v, p1.hi)
    p1.v = 2 // 将 p1 的值从 10 改为 2
    h.fix(p1.hi) // 修复堆
    fmt.Printf("修改后 p1 的值: %d, 在堆中索引为: %d\n", p1.v, p1.hi)
    fmt.Printf("修改后的堆顶: %d (索引 %d)\n", (*h)[0].v, (*h)[0].hi) // 2 (索引 0)

    // 删除 p3
    fmt.Printf("删除前 p3 的值: %d, 在堆中索引为: %d\n", p3.v, p3.hi)
    removed := h.remove(p3.hi)
    fmt.Printf("被删除的元素值: %d\n", removed.v)

    fmt.Println("按顺序弹出剩余元素:")
    for h.Len() > 0 {
        p := h.pop()
        fmt.Printf("值: %d, 弹出前索引: %d\n", p.v, p.hi)
    }
}
```

```txt
初始堆顶: 5 (索引 0)
修改前 p1 的值: 10, 在堆中索引为: 1
修改后 p1 的值: 2, 在堆中索引为: 0
修改后的堆顶: 2 (索引 0)
删除前 p3 的值: 15, 在堆中索引为: 2
被删除的元素值: 15
按顺序弹出剩余元素:
值: 2, 弹出前索引: 1
值: 5, 弹出前索引: 0
```

为什么值为 `2` 的元素在作为堆顶被弹出时，其 `hi`（弹出前索引）字段显示为 `1` 而不是 `0`？

这个现象确实看起来有悖直觉，但它恰恰揭示了 `heap.Pop` 操作和我们自定义 `Swap` 方法联动的精确过程。让我们一步步拆解 `h.pop()` 调用时发生了什么：

当时堆的切片状态是：`[{v:2, hi:0}, {v:5, hi:1}]`。

1.  我们调用了 `h.pop()`，它内部调用了 `heap.Pop(h)`。
2.  `heap.Pop(h)` 的首要任务是把堆顶元素（我们想要的返回值）取出来。它的策略是：将堆顶元素 `h[0]` 与堆的最后一个元素 `h[len-1]`（在这里是 `h[1]`）进行交换。
3.  这个交换操作触发了我们定义的 `Swap(0, 1)` 方法。
4.  在 `Swap(0, 1)` 方法内部：
    -   `h[0]` 和 `h[1]` 的指针被交换。交换后，切片在内存中的状态变为：`[{v:5, hi:1}, {v:2, hi:0}]`。
    -   **关键来了** ：紧接着，`Swap` 方法更新了这两个被交换元素的 `hi` 字段以反映它们在切片中的 *新位置*。
        -   现在位于索引 `0` 的元素（值是 `5`）的 `hi` 被更新为 `0`。
        -   现在位于索引 `1` 的元素（值是 `2`）的 `hi` 被更新为 `1`。
5.  `Swap` 执行完毕。此时，我们即将弹出的、值为 `2` 的元素，它正位于切片的末尾（索引 `1`），并且它自身的 `hi` 字段刚刚被更新为了 `1`。
6.  `heap.Pop` 接着调用我们定义的 `Pop()` 方法，该方法从切片末尾移除并返回 `h[1]`，即 `{v:2, hi:1}` 这个 `viPair` 实例。
7.  因此，`fmt.Printf` 打印出的 `p.v` 是 `2`，`p.hi` 是 `1`。

**结论** ：这个输出是完全正确的。`hi` 字段忠实地记录了元素在被 `Pop` 方法从切片中正式移除前的最后一刻，它在切片中的索引位置。这个位置因为 `heap.Pop` 内部的交换操作而从 `0` 变成了 `1`。这也凸显了 `hi` 字段的动态性——它总是在 `Swap` 操作后被立即更新，以保证其值的实时准确性。
