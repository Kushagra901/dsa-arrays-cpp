# 🚀 Ultimate C++ Arrays Mastery (41 Core DSA Problems)

[![Language](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B)](https://en.cppreference.com/)
[![Topic](https://img.shields.io/badge/Data%20Structures-Arrays%20%26%20Matrices-orange?style=for-the-badge)](https://leetcode.com/)
[![Problems](https://img.shields.io/badge/Total%20Problems-41%20Curated-success?style=for-the-badge)](https://github.com/Kushagra901/dsa-arrays-cpp)
[![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)](LICENSE)

A production-grade, highly curated collection of **41 fundamental to advanced Array & Matrix problems** implemented in modern C++. Every problem file is completely self-contained and engineered to serve as a comprehensive revision guide for technical interviews at top-tier tech companies (FAANG, Tier-1 Product Firms).

---

## 🌟 Repository Highlights

Each C++ file in this repository is built as a self-contained learning module containing:
- 💡 **Multiple Algorithmic Approaches**: Brute Force, Better, and Optimal solutions.
- ⏱️ **Rigorous Complexity Analysis**: Time and Space Complexities mathematically analyzed.
- 🎯 **Top Technical Interview Questions**: Deep-dive questions covering tricky edge cases, follow-ups, and architectural trade-offs.
- 🔗 **Curated Similar Problems**: Direct references to LeetCode, GeeksforGeeks, and Coding Ninjas problem numbers and difficulty ratings.
- 🛠️ **Step-by-Step Code Comments**: In-depth explanations for every logical block without unnecessary abstraction.

---

## 📑 Complete Problem Index (1 to 41)

| # | Problem Name | Primary Algorithm / Technique | Time Complexity | Space Complexity | Source File |
|:---:|:---|:---|:---:|:---:|:---:|
| **01** | Largest & Smallest Element | Linear Scan, Sorting | `O(N)` | `O(1)` | [`prob1.cpp`](prob1.cpp) |
| **02** | Second Largest & Second Smallest | Single-Pass Traversal | `O(N)` | `O(1)` | [`prob2.cpp`](prob2.cpp) |
| **03** | Check if Array is Sorted | Adjacent Element Comparison | `O(N)` | `O(1)` | [`prob3.cpp`](prob3.cpp) |
| **04** | Remove Duplicates from Sorted Array | In-Place Two Pointers | `O(N)` | `O(1)` | [`prob4.cpp`](prob4.cpp) |
| **05** | Left Rotate Array by 1 Place | In-Place Shift | `O(N)` | `O(1)` | [`prob5.cpp`](prob5.cpp) |
| **06** | Rotate Array by K Places (Brute) | Auxiliary Temp Buffer | `O(N)` | `O(K)` | [`prob6.cpp`](prob6.cpp) |
| **07** | Rotate Array by K Places (Optimal) | 3-Step Reversal Algorithm | `O(N)` | `O(1)` | [`prob7.cpp`](prob7.cpp) |
| **08** | Move Zeroes to End (Brute) | Temp Vector Filtering | `O(N)` | `O(N)` | [`prob8.cpp`](prob8.cpp) |
| **09** | Move Zeroes to End (Optimal) | In-Place Two Pointers Swapping | `O(N)` | `O(1)` | [`prob9.cpp`](prob9.cpp) |
| **10** | Linear Search in Array | Sequential Scan | `O(N)` | `O(1)` | [`prob10.cpp`](prob10.cpp) |
| **11** | Union of Two Sorted Arrays | Two Pointers Merge & Set | `O(N + M)` | `O(N + M)` | [`prob11.cpp`](prob11.cpp) |
| **12** | Intersection of Two Sorted Arrays | Two Pointers | `O(N + M)` | `O(1)` | [`prob12.cpp`](prob12.cpp) |
| **13** | Find Missing Number | Bitwise XOR & Gauss Formula | `O(N)` | `O(1)` | [`prob13.cpp`](prob13.cpp) |
| **14** | Maximum Consecutive Ones | Running Streak Counter | `O(N)` | `O(1)` | [`prob14.cpp`](prob14.cpp) |
| **15** | Single Number (Appears Once, Others Twice) | Bitwise XOR Cancellation | `O(N)` | `O(1)` | [`prob15.cpp`](prob15.cpp) |
| **16** | Longest Subarray with Sum K | Prefix Sum + Hash Map / 2-Pointers | `O(N)` | `O(N)` | [`prob16.cpp`](prob16.cpp) |
| **17** | Two Sum (Check Pair Sum) | Sorting + Two Pointers / Hash Map | `O(N log N)` / `O(N)` | `O(1)` / `O(N)` | [`prob17.cpp`](prob17.cpp) |
| **18** | Sort Array of 0s, 1s, and 2s | Dutch National Flag (3-Way Partition) | `O(N)` | `O(1)` | [`prob18.cpp`](prob18.cpp) |
| **19** | Majority Element (> N/2 Times) | Boyer-Moore Voting Algorithm | `O(N)` | `O(1)` | [`prob19.cpp`](prob19.cpp) |
| **20** | Maximum Subarray Sum | Kadane's Algorithm | `O(N)` | `O(1)` | [`prob20.cpp`](prob20.cpp) |
| **21** | Best Time to Buy and Sell Stock | Greedy Min-Price Tracking | `O(N)` | `O(1)` | [`prob21.cpp`](prob21.cpp) |
| **22** | Rearrange Array Elements by Sign | Two Pointers (Equal & Unequal Varieties) | `O(N)` | `O(N)` | [`prob22.cpp`](prob22.cpp) |
| **23** | Next Permutation | 3-Step Lexicographical Scan & Reverse | `O(N)` | `O(1)` | [`prob23.cpp`](prob23.cpp) |
| **24** | Leaders in an Array | Right-to-Left Running Maximum | `O(N)` | `O(1)` | [`prob24.cpp`](prob24.cpp) |
| **25** | Longest Consecutive Sequence | Hash Set Streak Counting | `O(N)` | `O(N)` | [`prob25.cpp`](prob25.cpp) |
| **26** | Set Matrix Zeroes | In-Place 1st Row & Col Markers | `O(N × M)` | `O(1)` | [`prob26.cpp`](prob26.cpp) |
| **27** | Rotate Matrix by 90° Clockwise | Transpose + Row Reversal | `O(N²)` | `O(1)` | [`prob27.cpp`](prob27.cpp) |
| **28** | Spiral Matrix Traversal | 4 Boundary Pointers (Top, Bottom, Left, Right) | `O(N × M)` | `O(1)` | [`prob28.cpp`](prob28.cpp) |
| **29** | Count Subarrays with Sum K | Prefix Sum Frequency Map | `O(N)` | `O(N)` | [`prob29.cpp`](prob29.cpp) |
| **30** | Pascal's Triangle (3 Variations) | Combinatorics `nCr` & Iterative Row Building | `O(N²)` | `O(N²)` | [`prob30.cpp`](prob30.cpp) |
| **31** | Majority Element II (> N/3 Times) | Extended Boyer-Moore Voting (2 Candidates) | `O(N)` | `O(1)` | [`prob31.cpp`](prob31.cpp) |
| **32** | Maximum Product Subarray | Prefix & Suffix Running Product | `O(N)` | `O(1)` | [`prob32.cpp`](prob32.cpp) |
| **33** | Count Inversions in Array | Modified Merge Sort | `O(N log N)` | `O(N)` | [`prob33.cpp`](prob33.cpp) |
| **34** | Reverse Pairs (`arr[i] > 2 * arr[j]`) | Modified Merge Sort with 2-Pointer Scan | `O(N log N)` | `O(N)` | [`prob34.cpp`](prob34.cpp) |
| **35** | 3Sum (Zero Sum Unique Triplets) | Sorting + Two Pointers | `O(N²)` | `O(1)` | [`prob35.cpp`](prob35.cpp) |
| **36** | 4Sum (Target Sum Quadruplets) | Sorting + 2 Outer Loops + Two Pointers | `O(N³)` | `O(1)` | [`prob36.cpp`](prob36.cpp) |
| **37** | Merge Overlapping Subintervals | Sort by Start Time + Greedy Merge | `O(N log N)` | `O(N)` | [`prob37.cpp`](prob37.cpp) |
| **38** | Largest Subarray with 0 Sum | Prefix Sum First Occurrence Map | `O(N)` | `O(N)` | [`prob38.cpp`](prob38.cpp) |
| **39** | Merge Two Sorted Arrays in O(1) Space | Gap Method (Shell Sort Traversal) | `O((N+M) log(N+M))` | `O(1)` | [`prob39.cpp`](prob39.cpp) |
| **40** | Count Subarrays with Given XOR K | Prefix XOR Frequency Map | `O(N)` | `O(N)` | [`prob40.cpp`](prob40.cpp) |
| **41** | Repeating and Missing Number | Mathematical Equations (`S`, `S²`) & XOR | `O(N)` | `O(1)` | [`prob41.cpp`](prob41.cpp) |

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
│   └── Prefix XOR Properties (prob40)
├── Voting & Greedy Strategies
│   ├── Boyer-Moore Majority Voting (prob19, prob31)
│   └── Greedy Running Min/Max (prob21, prob24)
├── Matrix Geometric Manipulations
│   ├── Transpose & Reverse (prob27)
│   ├── Boundary Traversal (prob28)
│   └── In-Place Coordinate Markers (prob26)
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
# Compile
g++ -std=c++17 prob1.cpp -o prob1

# Execute on Windows
prob1.exe

# Execute on Linux / macOS
./prob1
```

To run all files with syntax validation:
```bash
# Using g++ syntax check
g++ -fsyntax-only -std=c++17 prob*.cpp
```

---

## 🎯 Contributing & Feedback
Contributions, additional problem variations, or optimizations are welcome! Feel free to submit an issue or pull request.

---

<div align="center">
  <b>Developed with ❤️ for DSA Mastery & Competitive Programming</b>
</div>
