/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (54.47%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 17.2K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x), left(nullptr),right(nullptr) {}
};

// BST 的性质 ，如果使用中序遍历，则得到的序列是一个全序的数组，即是一个排序后的数组
// 可以直接把值都拿出来，然后排序然后再塞回去

// 优化的解法，看起来使用morris算法进行 inorder 遍历
class Solution {
public:
    
    void inorderAppend(TreeNode * root, vector<int> & vec){
        if(root == nullptr) return ;
        inorderAppend(root -> left, vec);
        vec.push_back(root -> val);
        inorderAppend(root -> right, vec);
    }

    void inorderFill(TreeNode * root, vector<int> & vec, int& current){
        if(root == nullptr) return ;
        inorderFill(root -> left, vec, current);
        root -> val = vec[current];
        current ++;
        inorderFill(root -> right, vec, current);
    }

    void recoverTree(TreeNode* root) {
        vector<int> vec;
        inorderAppend(root, vec);
        sort(vec.begin(), vec.end());
        int current = 0;
        inorderFill(root, vec, current);
    }
};
// @lc code=end

