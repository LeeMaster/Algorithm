/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 *
 * https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing/description/
 *
 * algorithms
 * Medium (34.07%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 4.9K
 * Testcase Example:  '[1,3,5,4]\n[1,2,3,7]'
 *
 * 我们有两个长度相等且不为空的整型数组 A 和 B 。
 * 
 * 我们可以交换 A[i] 和 B[i] 的元素。注意这两个元素在各自的序列中应该处于相同的位置。
 * 
 * 在交换过一些元素之后，数组 A 和 B 都应该是严格递增的（数组严格递增的条件仅为A[0] < A[1] < A[2] < ... <
 * A[A.length - 1]）。
 * 
 * 给定数组 A 和 B ，请返回使得两个数组均保持严格递增状态的最小交换次数。假设给定的输入总是有效的。
 * 
 * 
 * 示例:
 * 输入: A = [1,3,5,4], B = [1,2,3,7]
 * 输出: 1
 * 解释: 
 * 交换 A[3] 和 B[3] 后，两个数组如下:
 * A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
 * 两个数组均为严格递增的。
 * 
 * 注意:
 * 
 * 
 * A, B 两个数组的长度总是相等的，且长度的范围为 [1, 1000]。
 * A[i], B[i] 均为 [0, 2000]区间内的整数。
 * 
 * 
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        if (N < 2) return 0;     
        // 初始状态，   
        int res_keep = 0; // 保持该位置的数字不变
        int res_swap = 1; // 交换该位置的两个数字

        for (int i = 1; i < N; ++i) {
            bool b1 = (A[i] > A[i - 1] && B[i] > B[i - 1]);
            bool b2 = (A[i] > B[i - 1] && B[i] > A[i - 1]);
            
            if (b1 && b2) {
                res_keep = min(res_keep, res_swap);
                res_swap = 1 + res_keep;
            } else if (b1) {
                res_swap = res_swap + 1;
            } else if (b2) {
                int t = res_swap;
                res_swap = res_keep + 1;
                res_keep = t;
            }
        }
        return min(res_swap, res_keep);
    }
};
// @lc code=end

