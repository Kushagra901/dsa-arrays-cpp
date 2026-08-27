/**
 * ============================================================================
 * PROBLEM: Rearrange Array Elements by Sign
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    Variety 1: An array of size `n` contains an equal number of positive and negative 
 *    integers. Rearrange them alternatively such that positive numbers occupy even indices 
 *    (0, 2, 4...) and negative numbers occupy odd indices (1, 3, 5...), maintaining relative order.
 * 
 *    Variety 2: The count of positive and negative numbers is NOT necessarily equal. 
 *    Alternate as long as both exist, and append remaining elements at the end preserving relative order.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - Variety 1 (Equal Counts - Direct Placement):
 *        • Time Complexity:  O(N) - Single pass through array
 *        • Space Complexity: O(N) - Output array of size N
 *    - Variety 2 (Unequal Counts - Segregation + Alternation):
 *        • Time Complexity:  O(2N) = O(N) (Pass 1 segregate into pos/neg, Pass 2 alternate & append)
 *        • Space Complexity: O(N) - Two separate vectors for pos and neg
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. Can Variety 1 be solved in-place with O(1) auxiliary space while preserving relative order?
 *    - Preserving stability (relative order) in-place in O(N) time is an unsolved problem in computer science
 *      (similar to stable in-place partition). An O(N) auxiliary vector is the standard optimal approach.
 * 
 * 2. How does the pointer placement work for Variety 1?
 *    - Start `positiveIndex = 0` and `negativeIndex = 1`.
 *    - If `nums[i] > 0`: `ans[positiveIndex] = nums[i]; positiveIndex += 2;`
 *    - Else: `ans[negativeIndex] = nums[i]; negativeIndex += 2;`
 * 
 * 3. How do you handle Variety 2 when positive and negative counts differ?
 *    - Segregate elements into `pos` and `neg` lists.
 *    - Alternate up to `min(pos.size(), neg.size())`.
 *    - Append the remaining leftovers of the larger list to the end of the array.
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 2149: Rearrange Array Elements by Sign (Medium)
 * 2. GeeksforGeeks: Alternate positive and negative numbers (Easy)
 * 3. Coding Ninjas: Rearrange Array Elements by Sign (Medium)
 * 4. LeetCode 905: Sort Array By Parity (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// ============================================================================
// VARIETY 1: Equal Number of Positives and Negatives (Optimal O(N) Single-Pass)
// Time Complexity: O(N) | Space Complexity: O(N)
// ============================================================================

vector<int> rearrangeArray(const vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int positiveIndex = 0; // Even indices: 0, 2, 4...
    int negativeIndex = 1; // Odd indices: 1, 3, 5...

    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            ans[negativeIndex] = nums[i];
            negativeIndex += 2;
        } else {
            ans[positiveIndex] = nums[i];
            positiveIndex += 2;
        }
    }
    return ans;
}

// ============================================================================
// VARIETY 2: Unequal Number of Positives and Negatives
// Time Complexity: O(2N) = O(N) | Space Complexity: O(N)
// ============================================================================

vector<int> RearrangebySign(vector<int> A, int n) {
    // Segregate elements into two separate vectors
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++) {
        if (A[i] > 0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }

    // Case A: Positives are fewer than Negatives
    if (pos.size() < neg.size()) {
        // Alternate up to pos.size()
        for (int i = 0; i < (int)pos.size(); i++) {
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        // Fill remaining negatives at the end
        int index = pos.size() * 2;
        for (int i = pos.size(); i < (int)neg.size(); i++) {
            A[index] = neg[i];
            index++;
        }
    }
    // Case B: Negatives are fewer than or equal to Positives
    else {
        // Alternate up to neg.size()
        for (int i = 0; i < (int)neg.size(); i++) {
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        // Fill remaining positives at the end
        int index = neg.size() * 2;
        for (int i = neg.size(); i < (int)pos.size(); i++) {
            A[index] = pos[i];
            index++;
        }
    }

    return A;
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    // Variety 1 Demonstration (Equal counts)
    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    cout << "Variety 1 Original: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    vector<int> result1 = rearrangeArray(nums1);
    cout << "Variety 1 Result:   ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    // Variety 2 Demonstration (Unequal counts)
    vector<int> nums2 = {1, 2, -4, -5, 3, 4};
    cout << "\nVariety 2 Original: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    vector<int> result2 = RearrangebySign(nums2, nums2.size());
    cout << "Variety 2 Result:   ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}