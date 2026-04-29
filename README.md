# AlgorithmSolutions

算法题解集合，涵盖多个在线判题平台的解决方案。

## 项目结构

```
AlgorithmSolutions/
├── platform/              # 按平台分类
│   ├── codeForces/        # CodeForces 题解
│   ├── leetcode/          # LeetCode 题解
│   ├── luogu/             # 洛谷题解
│   └── szu/               # 校内OJ
├── byAlgorithms/          # 按算法分类（软链接）
│   ├── BFS/
│   ├── binarySearch/
│   ├── dijkstra/
│   └── ...
├── scripts/               # 工具脚本
│   ├── create_symlinks.py # 软链接管理脚本
│   └── run_as_admin.bat   # Windows管理员运行脚本
├── create.py              # 题目创建脚本
├── template.cpp           # C++ 模板文件
└── .gitattributes         # Git 换行符配置
```

## 内容概览

- **CodeForces题解**：算法竞赛题目解决方案
- **LeetCode题解**：经典算法问题实现，包含多种解法对比
- **洛谷题解**：中文OJ题目解决方案
- **SZU OJ题解**：校内平台题目
- **算法分类索引**：通过软链接系统实现多维度查找

## 技术特点

- **多解法对比**：关键问题提供不同时间/空间复杂度的实现
- **规范代码风格**：一致的命名约定和注释规范
- **完整项目结构**：清晰的目录组织和文件管理
- **自动化工具**：题目创建脚本、软链接脚本支持按算法类型分类浏览

## 使用方法

### 获取代码
```bash
git clone https://github.com/superbigcup325/AlgorithmSolutions.git
cd AlgorithmSolutions
```

### 创建新题目

使用 `create.py` 脚本快速创建题目文件夹：

```bash
# 查看帮助
python create.py --help

# 列出支持的平台
python create.py --list-platforms

# CodeForces（支持 round 子目录）
python create.py cf A_perfectRoot --round round1074_Div4
python create.py cf B_prefixMax

# LeetCode
python create.py lc 1_twoSum
python create.py lc 15_threeSum

# Luogu（支持 contest 子目录）
python create.py lg p1102_ABpairs
python create.py lg B3647_floyd
python create.py lg A_numberGameI --contest beginnerContest_43_Div4

# SZU（支持 contest 子目录）
python create.py szu A_oiiaioiiai
python create.py szu B_ --contest szucpc2025
```

**平台标识**：
| 标识 | 平台 | 特性 |
|------|------|------|
| `cf` | CodeForces | 支持 `--round` |
| `lc` | LeetCode | 支持 `--contest` |
| `lg` | Luogu | 支持 `--contest` |
| `szu` | SZU OJ | 支持 `--contest` |

**模板说明**：
- CodeForces 使用内置的多测试用例模板
- 其他平台使用 `template.cpp` 作为模板

### 编译运行C++代码
```bash
# 示例：编译LeetCode第一题
g++ platform/leetcode/1_twoSum/solution_bruteForce.cpp -o solution
./solution
```

### 软链接系统
项目使用符号链接实现多维度分类，方便按算法类型查找

```bash
# 使用脚本创建软链接
python scripts/create_symlinks.py --source "源文件路径" --target-dir "目标目录"

# 示例
python scripts/create_symlinks.py \
  --source "platform/leetcode/1_twoSum/solution_hashTable.cpp" \
  --target-dir "byAlgorithms/hashTable" \
  --name "twoSum_hashTable.cpp"
```

## 开发说明

### 代码规范
- 文件名格式：`solution.cpp` 或 `solution_算法名称.cpp`
- 函数命名：使用小写字母和下划线
- 复杂度标注：在文件头部注释时间与空间复杂度

### 目录结构约定
```
platform/平台名称/[round或contest子目录/]题目ID_题目名称/
├── solution.cpp           # 主解法
├── problem.md             # 题目描述
└── solution_xxx.cpp       # 其他解法（可选）
```

### 题目描述模板
每个题目文件夹包含 `problem.md`，格式如下：
- 题目描述
- 输入格式
- 输出格式
- 样例
- 数据范围
- 解题思路
- 复杂度分析

## 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件。
