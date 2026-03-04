# C. 特殊字符串

每组测试时间限制：2秒  
内存限制：256兆字节

AksLoI Coding 在一个长度为 $n$ 的字符串 $s$ 上玩游戏。初始时，$s$ 仅包含小写拉丁字母。

每轮游戏中，AksLoI Coding 可以选择任意一对整数 $(i, j)$，满足：

- $1 \leq i < j \leq n$；
- $s_i = s_j \neq *$；且
- 对于所有 $i < k < j$，有 $s_k = *$。

如果不存在这样的 $i, j$，则游戏结束。否则，AksLoI Coding 将 $s_i := *$ 和 $s_j := *$。  
游戏结束后，当且仅当 $s$ 中所有字符都等于 $*$ 时，AksLoI Coding 获胜。判断 AksLoI Coding 是否可能获胜。

**注意：** $*$ 表示 ASCII 字符 42。

## 输入
第一行包含一个整数 $t$ ($1 \leq t \leq 100$)，表示测试用例的数量。

每个测试用例的第一行包含一个整数 $n$ ($1 \leq n \leq 5000$)，表示字符串的长度。

每个测试用例的第二行包含一个由小写拉丁字母组成的字符串 $s$。

所有测试用例的 $n$ 之和不超过 $5000$。

## 输出
对于每个测试用例，输出一行答案。如果 AksLoI Coding 可以获胜，则输出 "YES"（不带引号）。否则，输出 "NO"（不带引号）。

答案不区分大小写。例如，字符串 "yEs"、"yeS"、"YeS" 和 "YES" 都将被识别为肯定回答。

### 示例

#### 输入
```
6
1
a
6
l1m1lm
6
uuuuuu
6
byebye
6
ooooo
12
siixxsevvenn
```

#### 输出
```
NO
YES
NO
YES
```

---

## 注释
在第一个测试用例中，可以证明 AksLoI Coding 不可能获胜。

在第二个测试用例中，AksLoI Coding 可以通过以下操作获胜：  
$l1m1lm \rightarrow l1m*m \rightarrow *m*m*m \rightarrow ****$

在第三个测试用例中，AksLoI Coding 可以通过以下操作获胜：  
$uuwwuu \rightarrow uw**** \rightarrow u*****$