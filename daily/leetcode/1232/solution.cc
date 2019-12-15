/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 *
 * https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (48.34%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 7.1K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * 在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y]
 * 表示横坐标为 x、纵坐标为 y 的点。
 * 
 * 请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates 中不含重复的点
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;
// 求斜率 但是要转换 一下 转换为乘法 
class Solution {
public:
    bool checkStraightLine(vector<vector<int> >& coordinates) {
        if (coordinates.size() <= 2) return true;
        for (int i = 2; i < coordinates.size(); ++i) {
            int a1 = coordinates[i - 2][0];
            int b1 = coordinates[i - 2][1];
            int a2 = coordinates[i - 1][0];
            int b2 = coordinates[i - 1][1];
            int a3 = coordinates[i][0];
            int b3 = coordinates[i][1];

            // toleft test
            if (a1 * b2 - a2 * b1 + a2 * b3 - a3 * b2 + a3 * b1 - a1 * b3 != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

