/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (56.77%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 10.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * 示例：
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 输出: [1, 3, 9]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr) , right(nullptr){}
};

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> result;

    void dfs(TreeNode * root, int level){
        if(result.size() == level) result.push_back(INT_MIN);
        // 当结果的层次和递归到这个地方时候函数的层次就可以进行一次判断，首先将最小的结果放入其中
        // 然后再进行比对，从而得到结果
        result[level] = max(result[level], root -> val);
        // 继续 进行 DFS
         
        if(root -> left) dfs(root -> left, level + 1);
        if(root -> right) dfs(root -> right, level+1);
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return result;
        dfs(root, 0);
        return result;
    }


};
// @lc code=end

