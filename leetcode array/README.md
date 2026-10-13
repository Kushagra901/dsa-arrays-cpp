# 🧠 LeetCode Arrays Mastery (13 Advanced Problems)

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B)](https://en.cppreference.com/)
[![Topic](https://img.shields.io/badge/LeetCode-Arrays%20%26%20Dynamic%20Programming-orange?style=for-the-badge&logo=leetcode)](https://leetcode.com/)
[![Problems](https://img.shields.io/badge/Total%20Problems-13%20Curated-success?style=for-the-badge)](https://github.com/Kushagra901/dsa-arrays-cpp)
[![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)](LICENSE)

A curated, interview-ready collection of **13 high-frequency LeetCode Array & Matrix problems** implemented in modern C++. Every problem file is completely self-contained with multiple algorithmic approaches (Brute Force, Better, Optimal), mathematical complexity analysis, deep-dive interview follow-ups, and step-by-step code comments.

---

## 📑 Complete Problem Index (1 to 13)

| # | LeetCode # | Problem Name | Primary Algorithm / Technique | Time Complexity | Space Complexity | Source File |
|:---:|:---:|:---|:---|:---:|:---:|:---:|
| **01** | — | Min and Max in Array | Pairwise Comparison / Tournament | `O(N)` (1.5N comps) | `O(1)` | [`prob1.cpp`](prob1.cpp) |
| **02** | 1186 | Maximum Subarray Sum with One Deletion | State-Optimized DP (Kadane Extension) | `O(N)` | `O(1)` | [`prob2.cpp`](prob2.cpp) |
| **03** | 1749 | Maximum Absolute Sum of Any Subarray | Dual Kadane / Prefix Range | `O(N)` | `O(1)` | [`prob3.cpp`](prob3.cpp) |
| **04** | 523 | Continuous Subarray Sum | Prefix Sum Modulo + Hash Map | `O(N)` | `O(min(N, K))` | [`prob4.cpp`](prob4.cpp) |
| **05** | 1310 | XOR Queries of a Subarray | In-Place Prefix XOR Array | `O(N + Q)` | `O(1)` aux | [`prob5.cpp`](prob5.cpp) |
| **06** | 59 | Spiral Matrix II | 4 Boundary Pointers (Top, Bottom, Left, Right) | `O(N²)` | `O(1)` aux | [`prob6.cpp`](prob6.cpp) |
| **07** | 1886 | Determine Whether Matrix Can Be Obtained By Rotation | Transpose + Row Reversal (4 Rotations) | `O(N²)` | `O(1)` | [`prob7.cpp`](prob7.cpp) |
| **08** | 289 | Game of Life | 2-Bit State Encoding (Bit Manipulation) | `O(M × N)` | `O(1)` | [`prob8.cpp`](prob8.cpp) |
| **09** | 525 | Contiguous Array (Equal 0s and 1s) | Prefix Sum (0 as -1) + Hash Map | `O(N)` | `O(N)` | [`prob9.cpp`](prob9.cpp) |
| **10** | 674 | Longest Continuous Increasing Subsequence | Greedy Running Streak / Sliding Window | `O(N)` | `O(1)` | [`prob10.cpp`](prob10.cpp) |
| **11** | 1567 | Maximum Length of Subarray With Positive Product | DP State Tracking (`posCount`, `negCount`) | `O(N)` | `O(1)` | [`prob11.cpp`](prob11.cpp) |
| **12** | 713 | Subarray Product Less Than K | Monotonic Sliding Window / Two Pointers | `O(N)` | `O(1)` | [`prob12.cpp`](prob12.cpp) |
| **13** | 918 | Maximum Sum Circular Subarray | Dual Kadane (`maxSum` vs `total - minSum`) | `O(N)` | `O(1)` | [`prob13.cpp`](prob13.cpp) |

---

## 💡 Algorithmic Patterns Covered

```
LeetCode Array Mastery
├── Dynamic Programming & Kadane Extensions
│   ├── One Deletion Allowed (prob2: LC 1186)
│   ├── Absolute Sum Maximization (prob3: LC 1749)
│   ├── Sign-Dependent Length Tracking (prob11: LC 1567)
│   └── Circular Array Kadane (prob13: LC 918)
├── Prefix Metrics & Modular Hashing
│   ├── Modulo Remainders for Subarray Divisibility (prob4: LC 523)
│   ├── Fast Range Queries via Prefix XOR (prob5: LC 1310)
│   └── 0/1 Balance via Normalized Prefix Sum (prob9: LC 525)
├── In-Place Matrix Transformations
│   ├── Boundary Pointer Generation (prob6: LC 59)
│   ├── Transpose + Reverse Rotation (prob7: LC 1886)
│   └── 2-Bit In-Place State Encoding (prob8: LC 289)
└── Sliding Window & Linear Traversal
    ├── Optimal Pairwise Comparison (prob1)
    ├── Monotonic Window Expansion (prob12: LC 713)
    └── Greedy Strict Streak Scan (prob10: LC 674)
```

---

## 💻 How to Compile & Run

Compile any problem using standard `g++` (C++17 or higher):

```bash
# Compile
g++ -std=c++17 prob1.cpp -o prob1

# Execute on Windows
prob1.exe

# Execute on Linux / macOS
./prob1
```
