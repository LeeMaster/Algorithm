/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (57.18%)
 * Likes:    840
 * Dislikes: 0
 * Total Accepted:    88.1K
 * Total Submissions: 151.1K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */

// @lc code=start

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0)return 0;
        int tail = height.size() -1;
        int head = 0;
        int bigger = 0,smaller;
        for(;head < tail;){
            if(height[head] >= height[tail]){
                smaller = height[tail];
                int res = smaller * (tail - head); // 最开始搞成尼玛平方了，还是太菜了
                bigger = max(res,bigger);
                tail --;
            }else{
                smaller = height[head];
                int res = smaller * (tail - head);
                bigger = max(res,bigger);
                head++;
            }

        }
        return bigger;
    }
};
// @lc code=end

