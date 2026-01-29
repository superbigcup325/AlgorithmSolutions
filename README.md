# AlgorithmSolutions

算法题解集合，涵盖多个在线判题平台的解决方案。

## 项目结构

```
AlgorithmSolutions/
├── platform/              # 按平台分类
│   ├── leetcode/          # LeetCode 题解
│   ├── luogu/             # 洛谷题解
│   ├── uqo/               # 其他OJ平台
│   └── szuvj/             # 校内OJ
├── byAlgorithms/          # 按算法分类（软链接）
│   ├── BFS/
│   ├── binarySearch/
│   ├── dijkstra/
│   └── ...
└── scripts/               # 工具脚本
├── create_symlinks.py     # 软链接管理脚本
└── run_as_admin.bat       # Windows管理员运行脚本
```

## 内容概览

- **LeetCode题解**：经典算法问题实现，包含多种解法对比
- **洛谷题解**：中文OJ题目解决方案
- **其他平台题解**：涵盖多种算法竞赛题目
- **算法分类索引**：通过软链接系统实现多维度查找

## 技术特点

- **多解法对比**：关键问题提供不同时间/空间复杂度的实现
- **规范代码风格**：一致的命名约定和注释规范
- **完整项目结构**：清晰的目录组织和文件管理
- **自动化工具**：软链接脚本支持按算法类型分类浏览

## 使用方法

### 获取代码
```bash
git clone https://github.com/superbigcup325/AlgorithmSolutions.git
cd AlgorithmSolutions
```

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
```

```bash
# 示例
python scripts/create_symlinks.py \
  --source "platform/leetcode/1_twoSum/solution_hashTable.cpp" \
  --target-dir "byAlgorithms/hashTable" \
  --name "twoSum_hashTable.cpp"
```

## 开发说明

### 代码规范
- 文件名格式：`solution_算法名称.cpp`
- 函数命名：使用小写字母和下划线
- 复杂度标注：在文件头部注释时间与空间复杂度

### 目录结构约定
```
platform/平台名称/题目ID_题目名称/solution_算法变体.cpp
```

## 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件。
