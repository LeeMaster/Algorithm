/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 *
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (39.01%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 9.8K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
 * 
 * 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
 * 
 * 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输出坐标的顺序不重要
 * m 和 n 都小于150
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 
 * 给定下面的 5x5 矩阵:
 * 
 * ⁠ 太平洋 ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * 大西洋
 * 
 * 返回:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
 * 
 * 
 * 
 * 
 */

// 平面的搜索，小技巧：按照题目中的合法方向定义好向下移动的方向

#include <vector>

using namespace std;

// @lc code=start
class Solution {

private:
    // 四个方向 
    int dis[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m, n;
public:
    vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) {
        if(matrix.empty() || matrix[0].size() == 0)return {};
        vector<vector<int> > res;
	    
        m = matrix.size(), n = matrix[0].size();

        // 在两个标记数组中都能访问到那就可以同时的
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // 处理上和下边
		for (int i = 0; i < m; ++i) {
			dfs(matrix, pacific, INT_MIN, i, 0);
			dfs(matrix, atlantic, INT_MIN, i, n - 1);
		}

    // 处理左和右边
		for (int i = 0; i < n; ++i) {
			dfs(matrix, pacific, INT_MIN, 0, i);
			dfs(matrix, atlantic, INT_MIN, m - 1, i);
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (pacific[i][j] && atlantic[i][j]) {
					res.push_back({i, j});
				}
			}
		}
		return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int i, int j) {
        // 水从高到低，或者同高流动
		if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) return;
		
        visited[i][j] = true;
		for (int k = 0; k < 4; k++) {
			int newx = i + dis[k][0];
			int newy = j + dis[k][1];
			dfs(matrix, visited, matrix[i][j], newx, newy);
		}
	}

};
// @lc code=end

