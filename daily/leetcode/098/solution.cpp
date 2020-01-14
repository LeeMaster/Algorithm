/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (27.34%)
 * Likes:    370
 * Dislikes: 0
 * Total Accepted:    60.1K
 * Total Submissions: 212K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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

#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// 栈的应用
// 对二叉树直接遍历到最左，同时利用栈的能力，逆序掉最下层的节点
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode * > container;

        auto inorder = INT64_MIN;
        while(!container.empty() || root != nullptr){

            // 最左遍历 DFS 
            while(root != nullptr){
                container.push(root);
                root = root -> left;
            }

            root = container.top();
            container.pop();
            // 检查 Stack 上的值
            if(root -> val <= inorder) return false;
            inorder = root -> val;
            // 切换到右子树
            root = root -> right;
        }
        return true;
    }
};
// @lc code=end

