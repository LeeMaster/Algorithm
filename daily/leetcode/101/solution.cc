/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.11%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    79.5K
 * Total Submissions: 161.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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

#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return _isSymmertic(root -> left, root -> right);
    }

    bool _isSymmertic(TreeNode* left, TreeNode* right){
        if(!left && !right) return true; //nullptr == nullptr
        if( (left && !right) || (!left && right) || (left -> val != right -> val))return false;

        // 每一个树的左子树一定是和右子树相等的，所以递归下去就好了

        return _isSymmertic(left -> left, right -> right) && _isSymmertic(left -> right, right -> left);
    }

    // 迭代 ， 分别为左右子树建立一个 Queue 来进行BFS 比对的思路和上面递归的思路是一样的
    bool _isSymmertic(TreeNode * root){
      if (!root)return false;
      queue<TreeNode*> leftQ, rightQ;
      leftQ.push(root -> left);
      rightQ.push(root -> right);

      while(!leftQ.empty() && !rightQ.empty()){
        TreeNode * leftNode = leftQ.front();
        TreeNode * rightNode = rightQ.front;
        leftQ.pop();
        rightQ.pop();
        if ( (leftNode && !rightNode) || (!leftNode && rightNode) )return false;

        if(leftNode){
          if(leftNode -> val != rightNode -> val)return false;
          leftQ.push(leftNode -> left);
          leftQ.push(leftNode -> right);
          rightQ.push(rightNode -> right);
          rightQ.push(rightNode -> left);
        }

        return true;
      }
    }
};
// @lc code=end

