# AlgorithmSolutions

一个算法题解集合，包含 LeetCode、Luogu 等多个在线判题平台的题目解决方案

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
    └── create_symlinks.py # 软链接管理脚本
```

## 使用方法

### 获取代码
```bash
git clone https://github.com/superbigcup325/AlgorithmSolutions.git
cd AlgorithmSolutions
```

### 编译运行
```bash
# 示例：编译LeetCode第一题
g++ platform/leetcode/1_twoSum/solution_bruteForce.cpp -o solution
./solution
```

### 软链接系统
项目使用软链接实现多维度分类，可按算法类型查找

软连接创建脚本
```bash
python scripts/create_symlinks.py --source "源文件" --target-dir "目标目录"  {--name "命名"}
```

## 贡献
欢迎提交新的题解或改进现有代码。请保持代码风格一致，并添加必要的注释

## 使用说明
本仓库代码仅供学习参考，可自由用于个人学习目的