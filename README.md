# XJTU Common-Course Algorithms (Class of 2020)

**Chinese title:** 西交公共课算法题（2020届）

Freshman-year (second semester) C/C++ drills from a **common / general-education style programming course** at Xi’an Jiaotong University. Each problem was originally a separate Visual Studio project (“one project per problem”). This repository archives those solutions with light packaging for a Western-style GitHub portfolio **without rewriting the coursework itself**.

| | |
|---|---|
| **Author** | Chiyu Wang |
| **Context** | XJTU · Class of 2020 · ~freshman spring |
| **Language** | C / C++ (`solution.c` / `solution.cpp`) |
| **Problems** | 27 numbered entries under `problems/` |

## What stays “as written”

- Solution source is **your original coursework logic** (including period-typical style and known mistakes where noted in per-problem notes).
- Chinese problem titles and the historical VS project mapping are kept.
- No `.sln` / `.vcxproj` / Debug-Release junk — sources and statements only.

Problem statements in each folder were **inferred from the source**, not copied from an official exam sheet.

## Western-facing interface (how to use this repo)

```text
problems/
  01-profit-tiers/
    README.md      # problem note (CN; inferred statement)
    solution.c     # original-style solution
  ...
```

**Build one problem (MSVC):** open the matching historical project on your machine, or compile the `solution.*` file in a C/C++ toolchain.

**Build one problem (gcc/clang example):**

```bash
cd problems/01-profit-tiers
gcc -std=c11 solution.c -o sol
# Note: some files use Microsoft `scanf_s`; under gcc you may need to
# adjust I/O or compile with an MSVC-compatible environment.
```

Run from the problem directory and follow that problem’s README for I/O expectations.

## Problem index

| VS project | # | Title (ZH) | Topics |
|------------|---|------------|--------|
| Project1 | 01 | 利润分段提成 | branching / piecewise |
| Project2 | 02 | 大写字母的左邻右舍 | chars / wrap-around |
| Project2 | 03 | 两数四则运算 | arithmetic / I/O |
| Project3 | 04 | 以0结尾数列的最大公约数 | enumeration / GCD |
| Project5 | 05 | 字符、ASCII与后继 | char vs int |
| Project6 | 06 | 能否构成三角形 | geometry predicates |
| Project7 | 07 | 区间自守数 | automorphic numbers |
| Project8 | 08 | 连续正整数之和分解 | consecutive sums |
| Project9 | 09 | 最大值及其出现次数 | arrays / counting |
| Project10 | 10 | 1000到n的回文数 | palindromes |
| Project11 | 11 | 选票统计1/2/3 | counting / sentinel |
| Project12 | 12 | 球第10次落地与反弹 | simulation |
| Project14 | 13 | 数组循环移位 | rotation |
| Project16 | 14 | 和差还原颠倒数字 | digit reverse |
| Project17 | 15 | 勒让德多项式求值 | recursion |
| Project18 | 16 | 去掉首尾星号 | strings |
| Project19 | 17 | 二进制串转点分IP | base conversion |
| Project20 | 18 | 最值与平均值 | functions / out-params |
| Project21 | 19 | 单词词频统计 | word frequency |
| Project22 | 20 | 删除全部星号 | string filter |
| Project23 | 21 | 新兵奇偶轮换淘汰 | Josephus-like |
| Project25 | 22 | 星号串状态处理 | string state machine |
| Project26 | 23 | 最早签到与最晚签退 | structs / string compare |
| Project29 | 24 | 龟兔赛跑小游戏 | interactive sim |
| Project30 | 25 | 点与圆位置 | geometry |
| Project31 | 26 | 最大公约数与最小公倍数 | GCD / LCM |
| Project32 | 27 | 学生成绩录入 | structs |

Empty / wizard / incomplete VS projects from the same era are listed only as notes below and are **not** given problem numbers.

## Not numbered (shells / fragments)

| VS project | Note |
|------------|------|
| Project15, 27, 28, 33, 34 | no useful source |
| Project24 | include-only stub |
| Project35 | unfinished skeleton |
| ConsoleApplication1 | Hello World wizard |

## Academic honesty

These are the author’s own course solutions, archived for learning history. Problem text is reconstructed from code intent. Prefer citing as coursework archive, not as contest-grade editorial solutions.

## License

No SPDX license file yet. Rights remain with the author unless a license is added later.
