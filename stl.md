## C++ STL 特性概括表格

| 组件 | 核心特性 | 底层实现 | 适用场景 |
|------|----------|----------|----------|
| **容器** |
| `vector` | 动态数组，随机访问，尾部高效增删 | 连续内存 | 频繁随机访问，尾部操作 |
| `deque` | 双端队列，两端高效增删 | 分段连续内存 | 头尾操作频繁 |
| `list` | 双向链表，任意位置高效增删 | 节点+指针 | 频繁中间插入/删除 |
| `forward_list` | 单向链表，节省内存 | 节点+单指针 | 正向遍历，内存敏感 |
| `array` | 静态数组，栈上分配 | 原生数组 | 固定大小，性能要求高 |
| `set` | 有序唯一键，自动排序 | 红黑树 | 需要有序唯一集合 |
| `multiset` | 有序非唯一键 | 红黑树 | 允许重复的有序集合 |
| `map` | 键值对，有序唯一键 | 红黑树 | 字典，键值映射 |
| `multimap` | 键值对，有序非唯一键 | 红黑树 | 一键对多值 |
| `unordered_set` | 无序唯一键，O(1)查找 | 哈希表 | 只需快速查找 |
| `unordered_multiset` | 无序非唯一键 | 哈希表 | 快速查找，允许重复 |
| `unordered_map` | 无序键值对，O(1)查找 | 哈希表 | 高速键值存取 |
| `unordered_multimap` | 无序键值对，非唯一 | 哈希表 | 一键对多值高速存取 |
| `stack` | LIFO，适配器 | deque默认 | 深度优先，递归模拟 |
| `queue` | FIFO，适配器 | deque默认 | 广度优先，缓冲 |
| `priority_queue` | 优先级队列，堆结构 | vector+堆算法 | 任务调度，Top K问题 |
| **算法** |
| 排序 | `sort`、`stable_sort`等 | 快排/归并/内省 | 元素排序 |
| 查找 | `find`、`binary_search`等 | 线性/二分 | 元素查找 |
| 数值 | `accumulate`、`partial_sum`等 | - | 数值计算 |
| 修改 | `copy`、`replace`、`remove`等 | - | 元素操作 |
| 集合 | `set_union`、`set_intersection`等 | - | 集合运算 |
| 堆操作 | `push_heap`、`pop_heap`等 | 堆算法 | 优先队列实现 |
| **迭代器** |
| 输入 | 只读，单向 | - | istream_iterator |
| 输出 | 只写，单向 | - | ostream_iterator |
| 前向 | 读写，单向 | - | forward_list迭代器 |
| 双向 | 读写，双向 | - | list/set/map迭代器 |
| 随机访问 | 全功能，支持随机偏移 | - | vector/deque/array迭代器 |
| **函数对象** |
| 算术 | `plus`、`minus`、`negate`等 | - | 数值运算 |
| 比较 | `equal_to`、`greater`、`less`等 | - | 排序规则 |
| 逻辑 | `logical_and`、`logical_or`等 | - | 逻辑判断 |
| 位运算 | `bit_and`、`bit_or`、`bit_xor` | - | 位操作 |
| **适配器** |
| 容器适配器 | `stack`、`queue`、`priority_queue` | 封装容器 | 特定接口需求 |
| 迭代器适配器 | `reverse_iterator`、`back_inserter`等 | 包装迭代器 | 特殊迭代行为 |
| 函数适配器 | `bind`、`not_fn`等 | 函数组合 | 参数绑定/取反 |

**选择指南：**
- **默认选择**：`vector`、`unordered_map`、`sort`
- **有序需求**：`map`、`set`
- **频繁中间插入**：`list`
- **双端操作**：`deque`
- **内存优先**：`forward_list`、`array`
- **线程安全**：STL容器**非线程安全**，需外部同步