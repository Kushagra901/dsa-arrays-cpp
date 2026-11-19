# 🚀 Ultimate C++ Arrays Mastery (Core DSA + LeetCode Problems)

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B)](https://en.cppreference.com/)
[![Python](https://img.shields.io/badge/Language-Python%203-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![Topic](https://img.shields.io/badge/Data%20Structures-Arrays%20%26%20Matrices-orange?style=for-the-badge)](https://leetcode.com/)
[![Problems](https://img.shields.io/badge/Total%20Problems-55%20Curated-success?style=for-the-badge)](https://github.com/Kushagra901/dsa-arrays-cpp)
[![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)](LICENSE)

A production-grade, highly curated collection of **fundamental to advanced Array, Matrix & LeetCode problems** implemented in modern C++. Every problem file is completely self-contained and engineered to serve as a comprehensive revision guide for technical interviews at top-tier tech companies (FAANG, Tier-1 Product Firms).

---

## 🌟 Repository Highlights

Each C++ file in this repository is built as a self-contained learning module containing:
- 💡 **Multiple Algorithmic Approaches**: Brute Force, Better, and Optimal solutions.
- ⏱️ **Rigorous Complexity Analysis**: Time and Space Complexities mathematically analyzed.
- 🐍 **Full Python Companion Suite**: Fully typed, verified Python implementations ([`prob1.py`](prob1.py) ... [`prob42.py`](prob42.py)) alongside a comprehensive [C++ to Python Translation Guide](PYTHON_SOLUTIONS_GUIDE.md).
- 🎯 **Top Technical Interview Questions**: Deep-dive questions covering tricky edge cases, follow-ups, and architectural trade-offs.
- 🔗 **Curated Similar Problems**: Direct references to LeetCode, GeeksforGeeks, and Coding Ninjas problem numbers and difficulty ratings.
- 🛠️ **Step-by-Step Code Comments**: In-depth explanations for every logical block without unnecessary abstraction.

---

## 📁 Repository Structure

```
dsa-arrays-cpp/
├── prob1.cpp ... prob42.cpp      # 42 Core Fundamental DSA Array Problems (C++)
├── prob1.py ... prob42.py        # 42 Matching Python Solutions
├── PYTHON_SOLUTIONS_GUIDE.md     # Comprehensive C++ to Python Translation Guide
├── leetcode array/               # 13 High-Frequency Curated LeetCode Array Problems
│   ├── prob1.cpp ... prob13.cpp
│   └── README.md
└── README.md
```

---

## 📑 Core Problem Index (1 to 42)

| # | Problem Name | Primary Algorithm / Technique | Time Complexity | Space Complexity | Source Files (C++ / Python) |
|:---:|:---|:---|:---:|:---:|:---:|
| **01** | Largest & Smallest Element | Linear Scan, Sorting | `O(N)` | `O(1)` | [`prob1.cpp`](prob1.cpp) \| [`prob1.py`](prob1.py) |
| **02** | Second Largest & Second Smallest | Single-Pass Traversal | `O(N)` | `O(1)` | [`prob2.cpp`](prob2.cpp) \| [`prob2.py`](prob2.py) |
| **03** | Check if Array is Sorted | Adjacent Element Comparison | `O(N)` | `O(1)` | [`prob3.cpp`](prob3.cpp) \| [`prob3.py`](prob3.py) |
| **04** | Remove Duplicates from Sorted Array | In-Place Two Pointers | `O(N)` | `O(1)` | [`prob4.cpp`](prob4.cpp) \| [`prob4.py`](prob4.py) |
| **05** | Left Rotate Array by 1 Place | In-Place Shift | `O(N)` | `O(1)` | [`prob5.cpp`](prob5.cpp) \| [`prob5.py`](prob5.py) |
| **06** | Rotate Array by K Places (Brute) | Auxiliary Temp Buffer | `O(N)` | `O(K)` | [`prob6.cpp`](prob6.cpp) \| [`prob6.py`](prob6.py) |
| **07** | Rotate Array by K Places (Optimal) | 3-Step Reversal Algorithm | `O(N)` | `O(1)` | [`prob7.cpp`](prob7.cpp) \| [`prob7.py`](prob7.py) |
| **08** | Move Zeroes to End (Brute) | Temp Vector Filtering | `O(N)` | `O(N)` | [`prob8.cpp`](prob8.cpp) \| [`prob8.py`](prob8.py) |
| **09** | Move Zeroes to End (Optimal) | In-Place Two Pointers Swapping | `O(N)` | `O(1)` | [`prob9.cpp`](prob9.cpp) \| [`prob9.py`](prob9.py) |
| **10** | Linear Search in Array | Sequential Scan | `O(N)` | `O(1)` | [`prob10.cpp`](prob10.cpp) \| [`prob10.py`](prob10.py) |
| **11** | Union of Two Sorted Arrays | Two Pointers Merge & Set | `O(N + M)` | `O(N + M)` | [`prob11.cpp`](prob11.cpp) \| [`prob11.py`](prob11.py) |
| **12** | Intersection of Two Sorted Arrays | Two Pointers | `O(N + M)` | `O(1)` | [`prob12.cpp`](prob12.cpp) \| [`prob12.py`](prob12.py) |
| **13** | Find Missing Number | Bitwise XOR & Gauss Formula | `O(N)` | `O(1)` | [`prob13.cpp`](prob13.cpp) \| [`prob13.py`](prob13.py) |
| **14** | Maximum Consecutive Ones | Running Streak Counter | `O(N)` | `O(1)` | [`prob14.cpp`](prob14.cpp) \| [`prob14.py`](prob14.py) |
| **15** | Single Number (Appears Once, Others Twice) | Bitwise XOR Cancellation | `O(N)` | `O(1)` | [`prob15.cpp`](prob15.cpp) \| [`prob15.py`](prob15.py) |
| **16** | Longest Subarray with Sum K | Prefix Sum + Hash Map / 2-Pointers | `O(N)` | `O(N)` | [`prob16.cpp`](prob16.cpp) \| [`prob16.py`](prob16.py) |
| **17** | Two Sum (Check Pair Sum) | Sorting + Two Pointers / Hash Map | `O(N log N)` / `O(N)` | `O(1)` / `O(N)` | [`prob17.cpp`](prob17.cpp) \| [`prob17.py`](prob17.py) |
| **18** | Sort Array of 0s, 1s, and 2s | Dutch National Flag (3-Way Partition) | `O(N)` | `O(1)` | [`prob18.cpp`](prob18.cpp) \| [`prob18.py`](prob18.py) |
| **19** | Majority Element (> N/2 Times) | Boyer-Moore Voting Algorithm | `O(N)` | `O(1)` | [`prob19.cpp`](prob19.cpp) \| [`prob19.py`](prob19.py) |
| **20** | Maximum Subarray Sum | Kadane's Algorithm | `O(N)` | `O(1)` | [`prob20.cpp`](prob20.cpp) \| [`prob20.py`](prob20.py) |
| **21** | Best Time to Buy and Sell Stock | Greedy Min-Price Tracking | `O(N)` | `O(1)` | [`prob21.cpp`](prob21.cpp) \| [`prob21.py`](prob21.py) |
| **22** | Rearrange Array Elements by Sign | Two Pointers (Equal & Unequal Varieties) | `O(N)` | `O(N)` | [`prob22.cpp`](prob22.cpp) \| [`prob22.py`](prob22.py) |
| **23** | Next Permutation | 3-Step Lexicographical Scan & Reverse | `O(N)` | `O(1)` | [`prob23.cpp`](prob23.cpp) \| [`prob23.py`](prob23.py) |
| **24** | Leaders in an Array | Right-to-Left Running Maximum | `O(N)` | `O(1)` | [`prob24.cpp`](prob24.cpp) \| [`prob24.py`](prob24.py) |
| **25** | Longest Consecutive Sequence | Hash Set Streak Counting | `O(N)` | `O(N)` | [`prob25.cpp`](prob25.cpp) \| [`prob25.py`](prob25.py) |
| **26** | Set Matrix Zeroes | In-Place 1st Row & Col Markers | `O(N × M)` | `O(1)` | [`prob26.cpp`](prob26.cpp) \| [`prob26.py`](prob26.py) |
| **27** | Rotate Matrix by 90° Clockwise | Transpose + Row Reversal | `O(N²)` | `O(1)` | [`prob27.cpp`](prob27.cpp) \| [`prob27.py`](prob27.py) |
| **28** | Spiral Matrix Traversal | 4 Boundary Pointers (Top, Bottom, Left, Right) | `O(N × M)` | `O(1)` | [`prob28.cpp`](prob28.cpp) \| [`prob28.py`](prob28.py) |
| **29** | Count Subarrays with Sum K | Prefix Sum Frequency Map | `O(N)` | `O(N)` | [`prob29.cpp`](prob29.cpp) \| [`prob29.py`](prob29.py) |
| **30** | Pascal's Triangle (3 Variations) | Combinatorics `nCr` & Iterative Row Building | `O(N²)` | `O(N²)` | [`prob30.cpp`](prob30.cpp) \| [`prob30.py`](prob30.py) |
| **31** | Majority Element II (> N/3 Times) | Extended Boyer-Moore Voting (2 Candidates) | `O(N)` | `O(1)` | [`prob31.cpp`](prob31.cpp) \| [`prob31.py`](prob31.py) |
| **32** | Maximum Product Subarray | Prefix & Suffix Running Product | `O(N)` | `O(1)` | [`prob32.cpp`](prob32.cpp) \| [`prob32.py`](prob32.py) |
| **33** | Count Inversions in Array | Modified Merge Sort | `O(N log N)` | `O(N)` | [`prob33.cpp`](prob33.cpp) \| [`prob33.py`](prob33.py) |
| **34** | Reverse Pairs (`arr[i] > 2 * arr[j]`) | Modified Merge Sort with 2-Pointer Scan | `O(N log N)` | `O(N)` | [`prob34.cpp`](prob34.cpp) \| [`prob34.py`](prob34.py) |
| **35** | 3Sum (Zero Sum Unique Triplets) | Sorting + Two Pointers | `O(N²)` | `O(1)` | [`prob35.cpp`](prob35.cpp) \| [`prob35.py`](prob35.py) |
| **36** | 4Sum (Target Sum Quadruplets) | Sorting + 2 Outer Loops + Two Pointers | `O(N³)` | `O(1)` | [`prob36.cpp`](prob36.cpp) \| [`prob36.py`](prob36.py) |
| **37** | Merge Overlapping Subintervals | Sort by Start Time + Greedy Merge | `O(N log N)` | `O(N)` | [`prob37.cpp`](prob37.cpp) \| [`prob37.py`](prob37.py) |
| **38** | Largest Subarray with 0 Sum | Prefix Sum First Occurrence Map | `O(N)` | `O(N)` | [`prob38.cpp`](prob38.cpp) \| [`prob38.py`](prob38.py) |
| **39** | Merge Two Sorted Arrays in O(1) Space | Gap Method (Shell Sort Traversal) | `O((N+M) log(N+M))` | `O(1)` | [`prob39.cpp`](prob39.cpp) \| [`prob39.py`](prob39.py) |
| **40** | Count Subarrays with Given XOR K | Prefix XOR Frequency Map | `O(N)` | `O(N)` | [`prob40.cpp`](prob40.cpp) \| [`prob40.py`](prob40.py) |
| **41** | Repeating and Missing Number | Mathematical Equations (`S`, `S²`) & XOR | `O(N)` | `O(1)` | [`prob41.cpp`](prob41.cpp) \| [`prob41.py`](prob41.py) |
| **42** | Subarrays with Given XOR K (Alternative) | 3-Tier Multi-Approach & Frequency Hash Map | `O(N)` | `O(N)` | [`prob42.cpp`](prob42.cpp) \| [`prob42.py`](prob42.py) |

---

## 🚀 LeetCode Curated Problems (`leetcode array/`)

| # | LeetCode # | Problem Name | Primary Algorithm / Technique | Time Complexity | Space Complexity | Source File |
|:---:|:---:|:---|:---|:---:|:---:|:---:|
| **01** | — | Min and Max in Array | Pairwise Comparison / Tournament | `O(N)` (1.5N comps) | `O(1)` | [`leetcode array/prob1.cpp`](leetcode%20array/prob1.cpp) |
| **02** | 1186 | Maximum Subarray Sum with One Deletion | State-Optimized DP (Kadane Extension) | `O(N)` | `O(1)` | [`leetcode array/prob2.cpp`](leetcode%20array/prob2.cpp) |
| **03** | 1749 | Maximum Absolute Sum of Any Subarray | Dual Kadane / Prefix Range | `O(N)` | `O(1)` | [`leetcode array/prob3.cpp`](leetcode%20array/prob3.cpp) |
| **04** | 523 | Continuous Subarray Sum | Prefix Sum Modulo + Hash Map | `O(N)` | `O(min(N, K))` | [`leetcode array/prob4.cpp`](leetcode%20array/prob4.cpp) |
| **05** | 1310 | XOR Queries of a Subarray | In-Place Prefix XOR Array | `O(N + Q)` | `O(1)` aux | [`leetcode array/prob5.cpp`](leetcode%20array/prob5.cpp) |
| **06** | 59 | Spiral Matrix II | 4 Boundary Pointers (Top, Bottom, Left, Right) | `O(N²)` | `O(1)` aux | [`leetcode array/prob6.cpp`](leetcode%20array/prob6.cpp) |
| **07** | 1886 | Determine Whether Matrix Can Be Obtained By Rotation | Transpose + Row Reversal (4 Rotations) | `O(N²)` | `O(1)` | [`leetcode array/prob7.cpp`](leetcode%20array/prob7.cpp) |
| **08** | 289 | Game of Life | 2-Bit State Encoding (Bit Manipulation) | `O(M × N)` | `O(1)` | [`leetcode array/prob8.cpp`](leetcode%20array/prob8.cpp) |
| **09** | 525 | Contiguous Array (Equal 0s and 1s) | Prefix Sum (0 as -1) + Hash Map | `O(N)` | `O(N)` | [`leetcode array/prob9.cpp`](leetcode%20array/prob9.cpp) |
| **10** | 674 | Longest Continuous Increasing Subsequence | Greedy Running Streak / Sliding Window | `O(N)` | `O(1)` | [`leetcode array/prob10.cpp`](leetcode%20array/prob10.cpp) |
| **11** | 1567 | Maximum Length of Subarray With Positive Product | DP State Tracking (`posCount`, `negCount`) | `O(N)` | `O(1)` | [`leetcode array/prob11.cpp`](leetcode%20array/prob11.cpp) |
| **12** | 713 | Subarray Product Less Than K | Monotonic Sliding Window / Two Pointers | `O(N)` | `O(1)` | [`leetcode array/prob12.cpp`](leetcode%20array/prob12.cpp) |
| **13** | 918 | Maximum Sum Circular Subarray | Dual Kadane (`maxSum` vs `total - minSum`) | `O(N)` | `O(1)` | [`leetcode array/prob13.cpp`](leetcode%20array/prob13.cpp) |

---

## 🧠 Pattern Taxonomy

```
Arrays & Matrix Patterns
├── Two Pointers & In-Place Swaps
│   ├── Fast & Slow Pointers (prob4, prob9)
│   ├── Left & Right Pointers (prob17, prob35, prob36)
│   └── 3-Way Partitioning / DNF (prob18)
├── Prefix Metrics & Frequency Hashing
│   ├── Prefix Sums for Subarray Search (prob16, prob29, prob38)
│   ├── Prefix XOR Properties (prob40, prob42, LC 1310)
│   └── Remainder Congruence Hashing (LC 523, LC 525)
├── Voting & Greedy Strategies
│   ├── Boyer-Moore Majority Voting (prob19, prob31)
│   └── Greedy Running Min/Max (prob21, prob24)
├── Matrix Geometric Manipulations
│   ├── Transpose & Reverse (prob27, LC 1886)
│   ├── Boundary Traversal (prob28, LC 59)
│   ├── In-Place Coordinate Markers (prob26)
│   └── 2-Bit State Encoding (LC 289)
├── Dynamic Programming & Kadane Extensions
│   ├── Linear Maximum Subarray (prob20)
│   ├── Maximum with One Deletion (LC 1186)
│   ├── Maximum Absolute Sum (LC 1749)
│   └── Circular Maximum Subarray (LC 918)
├── Divide & Conquer / Sorting Enhancements
│   ├── Modified Merge Sort for Inversions (prob33)
│   ├── Modified Merge Sort for Reverse Pairs (prob34)
│   └── Gap Method for In-Place Merging (prob39)
└── Bit Manipulation & Math
    ├── XOR Pair Cancellation (prob13, prob15, prob41)
    └── Combinatorics & Polynomial Equations (prob30, prob41)
```

---

## 💻 How to Compile & Run

You can compile any problem using standard `g++` (C++17 or higher):

```bash
# Compile core problem
g++ -std=c++17 prob1.cpp -o prob1

# Compile LeetCode problem
g++ -std=c++17 "leetcode array/prob1.cpp" -o leetcode_prob1

# Execute on Windows
prob1.exe

# Execute on Linux / macOS
./prob1
```

---

## 🎯 Contributing & Feedback
Contributions, additional problem variations, or optimizations are welcome! Feel free to submit an issue or pull request.

---

<div align="center">
  <b>Developed with ❤️ for DSA Mastery & Competitive Programming</b>
</div>
