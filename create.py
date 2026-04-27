#!/usr/bin/env python3
"""
create.py - 算法题解文件夹初始化脚本

用法:
    python create.py <平台名> <题目名> [选项]
    
示例:
    # CodeForces 基础用法
    python create.py cf A_perfectRoot
    python create.py cf B_prefixMax --round round1074_Div4
    
    # LeetCode 基础用法
    python create.py lc 1_twoSum
    python create.py lc 15_threeSum
    
    # Luogu 基础用法
    python create.py lg p1102_ABpairs
    python create.py lg B3647_floyd
    
    # SZU 基础用法
    python create.py szu A_oiiaioiiai
    python create.py szu B_ --contest szucpc2025
    
    # 使用 contests 子目录
    python create.py lc B_ --contest 325
    python create.py lg A_numberGameI --contest beginnerContest_43_Div4
"""

import argparse
import sys
from pathlib import Path


PLATFORMS = {
    'cf': {
        'name': 'codeForces',
        'dir': 'platform/codeForces',
        'has_round': True,
        'has_contest': False,
    },
    'lc': {
        'name': 'leetcode',
        'dir': 'platform/leetcode',
        'has_round': False,
        'has_contest': True,
    },
    'lg': {
        'name': 'luogu',
        'dir': 'platform/luogu',
        'has_round': False,
        'has_contest': True,
    },
    'szu': {
        'name': 'szu',
        'dir': 'platform/szu',
        'has_round': False,
        'has_contest': True,
    },
}

CPP_TEMPLATES = {
    'cf': (
        "#include <bits/stdc++.h>\n"
        "using namespace std;\n"
        "\n"
        "void solve() {\n"
        "    \n"
        "}\n"
        "\n"
        "int main() {\n"
        "    ios::sync_with_stdio(false);\n"
        "    cin.tie(nullptr);\n"
        "    \n"
        "    int t = 1;\n"
        "    cin >> t;\n"
        "    while (t--) solve();\n"
        "    \n"
        "    return 0;\n"
        "}\n"
    ),
    'lc': (
        "#include <bits/stdc++.h>\n"
        "using namespace std;\n"
        "\n"
        "class Solution {\n"
        "public:\n"
        "    \n"
        "};\n"
    ),
    'default': (
        "#include <bits/stdc++.h>\n"
        "using namespace std;\n"
        "\n"
        "int main() {\n"
        "    ios::sync_with_stdio(false);\n"
        "    cin.tie(nullptr);\n"
        "    \n"
        "    \n"
        "    \n"
        "    return 0;\n"
        "}\n"
    ),
}

MD_TEMPLATE = (
    "# {name}\n"
    "\n"
    "## 题目描述\n"
    "\n"
    "\n"
    "## 输入格式\n"
    "\n"
    "\n"
    "## 输出格式\n"
    "\n"
    "\n"
    "## 样例\n"
    "\n"
    "### 样例输入\n"
    "```\n"
    "\n"
    "```\n"
    "\n"
    "### 样例输出\n"
    "```\n"
    "\n"
    "```\n"
    "\n"
    "## 数据范围\n"
    "\n"
    "\n"
    "## 解题思路\n"
    "\n"
    "\n"
    "## 代码\n"
    "\n"
    "见 `solution.cpp`\n"
    "\n"
    "## 复杂度分析\n"
    "\n"
    "- 时间复杂度：O()\n"
    "- 空间复杂度：O()\n"
)


def create_solution(platform_key: str, problem_name: str, round_name: str = None, contest_name: str = None):
    """
    创建题解文件夹，包含 solution.cpp 和 problem.md

    Args:
        platform_key: 平台标识（cf/lc/lg/szu）
        problem_name: 题目名，用作文件夹名
        round_name:   CodeForces round 名称（可选）
        contest_name: contest 名称（可选）
    """
    if platform_key not in PLATFORMS:
        supported = ', '.join(PLATFORMS.keys())
        raise ValueError(
            f"Unsupported platform: '{platform_key}'. "
            f"Supported: {supported}"
        )

    platform_info = PLATFORMS[platform_key]
    base_dir = Path(platform_info['dir'])

    if round_name and platform_info['has_round']:
        problem_dir = base_dir / round_name / problem_name
    elif contest_name and platform_info['has_contest']:
        problem_dir = base_dir / 'contests' / contest_name / problem_name
    else:
        problem_dir = base_dir / problem_name

    if problem_dir.exists():
        raise FileExistsError(f"Directory already exists: {problem_dir}")

    problem_dir.mkdir(parents=True)

    cpp_content = CPP_TEMPLATES.get(platform_key, CPP_TEMPLATES['default'])
    cpp_path = problem_dir / 'solution.cpp'
    cpp_path.write_text(cpp_content)

    md_content = MD_TEMPLATE.format(name=problem_name)
    md_path = problem_dir / 'problem.md'
    md_path.write_text(md_content)

    print(f"Created: {problem_dir}/")
    print(f"  - {cpp_path.name}")
    print(f"  - {md_path.name}")


def list_platforms():
    """列出所有支持的平台"""
    print("Supported platforms:")
    for key, info in PLATFORMS.items():
        features = []
        if info['has_round']:
            features.append('round')
        if info['has_contest']:
            features.append('contest')
        feature_str = f" (supports: {', '.join(features)})" if features else ""
        print(f"  {key}: {info['name']}{feature_str}")


def list_existing_rounds():
    """列出现有的 CodeForces rounds"""
    cf_dir = Path(PLATFORMS['cf']['dir'])
    if cf_dir.exists():
        rounds = [d.name for d in cf_dir.iterdir() if d.is_dir() and d.name.startswith('round')]
        if rounds:
            print("Existing CodeForces rounds:")
            for r in sorted(rounds):
                print(f"  {r}")
        else:
            print("No existing CodeForces rounds found.")


def list_existing_contests(platform_key: str):
    """列出现有的 contests"""
    if platform_key not in PLATFORMS:
        return
    
    platform_dir = Path(PLATFORMS[platform_key]['dir']) / 'contests'
    if platform_dir.exists():
        contests = [d.name for d in platform_dir.iterdir() if d.is_dir()]
        if contests:
            print(f"Existing {PLATFORMS[platform_key]['name']} contests:")
            for c in sorted(contests):
                print(f"  {c}")


def main():
    parser = argparse.ArgumentParser(
        description='算法题解文件夹初始化脚本',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
示例:
  %(prog)s cf A_perfectRoot --round round1074_Div4
  %(prog)s lc 1_twoSum
  %(prog)s lg p1102_ABpairs
  %(prog)s szu A_ --contest szucpc2025
  %(prog)s --list-rounds
  %(prog)s --list-contests lc
        """
    )
    
    parser.add_argument('platform', nargs='?', help='平台标识 (cf/lc/lg/szu)')
    parser.add_argument('problem', nargs='?', help='题目名称')
    parser.add_argument('--round', '-r', dest='round_name', help='CodeForces round 名称')
    parser.add_argument('--contest', '-c', dest='contest_name', help='contest 名称')
    parser.add_argument('--list-platforms', '-l', action='store_true', help='列出所有支持的平台')
    parser.add_argument('--list-rounds', action='store_true', help='列出现有的 CodeForces rounds')
    parser.add_argument('--list-contests', dest='list_contests_platform', help='列出指定平台的 contests')

    args = parser.parse_args()

    if args.list_platforms:
        list_platforms()
        return

    if args.list_rounds:
        list_existing_rounds()
        return

    if args.list_contests_platform:
        list_existing_contests(args.list_contests_platform)
        return

    if not args.platform or not args.problem:
        parser.print_help()
        sys.exit(1)

    try:
        create_solution(
            platform_key=args.platform,
            problem_name=args.problem,
            round_name=args.round_name,
            contest_name=args.contest_name
        )
    except (ValueError, FileExistsError) as e:
        print(f"Error: {e}")
        sys.exit(1)


if __name__ == '__main__':
    main()
