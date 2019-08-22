/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.08%)
 * Likes:    301
 * Dislikes: 0
 * Total Accepted:    65.4K
 * Total Submissions: 148.2K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */
#include<vector>

using namespace std;
/**
 * 这个题目就是简单的 二分查找，
 * 找到的位置就是 head的位置，也就是需要插入的位置，因为head之前的元素
 * 都是小于Target 的 head 之后的元素应该是大于等于 target的
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int head = 0;
        int tail = nums.size() - 1;
        while(head <= tail){
            int mid = (head + tail) / 2;
            if(nums[mid] < target){
                head = mid + 1;
            }else if(nums[mid] > target){
                tail = mid - 1;
            }else{
                return mid;
            }
        }
        return head;
    }
};

