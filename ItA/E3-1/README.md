# E3-1 偏序关系
## 题目描述
对于二维平面上的任意两点$A(x_1,y_1),\,B(x_2,y_2)$，定义偏序关系$\leq$，表示$x_1\leq x_2$且$y_1\leq y_2$。

现给定平面上的若干点，求最大的点的子集$S$使得集合中的任意两点之间均满足偏序关系$\leq$，即对$\forall A,B \in S$，$A\leq B$或$B\leq A$成立。

只需要输出子集$S$的大小$|S|$。

## 输入格式

第一行一个整数$n$表示点的个数。

然后是$n$行输入，表示$n$个点的坐标，其中每行的格式为：

$x_i\quad  y_i$

点的横纵坐标均为整数，且输入数据不会出现重叠的点。

## 输出格式
输出一个整数表示最大可能的子集$|S|$的大小。

## 数据规模：

$0 < n \leq 10000$
$0 < x_i,\,y_i \leq 100000$

# 解题报告
## 初始思路
可以认为这是一道**最长“偏序$\leq$”子序列**的题目，类比最长不下降子序列，对于整点类型`Point`，重载操作符`<=`与`>`。
```c++
struct point
{
    int x;
    int y;
    bool operator<=(const point b) const
    {
        return (this->x <= b.x) && (this->y <= b.y);
    }
    bool operator<(const point b) const
    {
        return (this->x < b.x) && (this->y < b.y);
    }
    bool operator>=(const point b) const
    {
        return (this->x >= b.x) && (this->y >= b.y);
    }
    bool operator>(const point b) const
    {
        return (this->x > b.x) && (this->y > b.y);
    }
} Point[N + 1], F[N + 1];
```

记$F_i$表示偏序$\leq$子序列长度为$i$时的**序列尾端元素**，给出状态转移方程

$$
F_i = \max{ \{ Point_i | F_j < Point_i ,\quad j = 1 ,\, \cdots ,\, i - 1 \}}
$$

最终$F$的末尾元素对应下标即为最大子集大小。

## 提交与修改过程
首次提交[PA](https://202.38.86.171/status/8235b8a858f684be125ad49849f4ec28)，仅通过前4个测试点，其余测试点报Run Time Error错误。

随即助教修改了数据规模，把$N$设为10000后提交顺利[AC](https://202.38.86.171/status/c3f71d0a266e644b922a9b3327d33735)……

## 算法分析
### 时间复杂度
在算法中，当当前元素不满足偏序$\leq$$F$的末尾元素时，需要将其放置到向前检索到的合适位置，即首个满足偏序$\leq$其的右方，这本质上是一个二分查找，在实际实现中使用了`lower_bound()`函数，消耗$O(\lg{n})$的时间，因此总的时间复杂度为$O(n \lg{n})$。

### 空间复杂度
使用数组存放动态规划记录，因此消耗$O(n)$的空间。

## 总结
本题与最长不下降子序列并没有本质的区别，重载操作符后即可完成转化。可提升的部分是`Point[i]`数组不是必需的，用一个整点变量即可替代。