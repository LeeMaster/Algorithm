/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 *
 * https://leetcode-cn.com/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (62.15%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 8.5K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L)
 * 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 0   2
 * 
 * ⁠ L = 1
 * ⁠ R = 2
 * 
 * 输出: 
 * ⁠   1
 * ⁠     \
 * ⁠      2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   3
 * ⁠  / \
 * ⁠ 0   4
 * ⁠  \
 * ⁠   2
 * ⁠  /
 * ⁠ 1
 * 
 * ⁠ L = 1
 * ⁠ R = 3
 * 
 * 输出: 
 * ⁠     3
 * ⁠    / 
 * ⁠  2   
 * ⁠ /
 * ⁠1
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 对每一个节点进行处理，每个节点有三个情况
 * 1. val < L 整个节点就没用了   递归分析其右子树
 * 2. val > R 整个节点同样没用  递归分析其左子树
 * 3. L <= val <= R 节点是合法的直接返回
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return dfs(root,L,R);
    }

    TreeNode* dfs(TreeNode* root, int L, int R){
        if(root == NULL) return root;
        if(root -> val < L)return dfs(root -> right,L,R);
        if(root -> val > R)return dfs(root -> left,L,R);
        root -> left = dfs(root -> left,L,R);
        root -> right = dfs(root -> right,L,R);
        return root;
    }
};

