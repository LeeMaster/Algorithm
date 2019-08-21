/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.59%)
 * Likes:    1256
 * Dislikes: 0
 * Total Accepted:    82.8K
 * Total Submissions: 350.1K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include<vector>
#include<algorithm>

using namespace std;

/**
 * 将三个数的问题转换为两个数的问题
 * 基于一个事实， x = y + z y + z = -x 
 * 
 * Tips 这里需要注意一个问题，就是降纬的思想，将原有问题降低一个维度变成一个简单的问题来处理。
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;

        if(nums.size() < 3) return result;

        sort(nums.begin(),nums.end());

        for(auto i = 0; i < nums.size() -2 ;i++){
            //从样例看出，可能出现两个相同的元素，按照一个元素处理，其实这一步可以通过Set来解决
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int prev = i + 1;
            int tail = nums.size() - 1;
            //搜索剩下的元素来组成 三元组
            while(prev < tail){
                if(nums[prev] + nums[tail] + nums[i] > 0)tail--;
                else if(nums[prev] + nums[tail] + nums[i] < 0)prev++;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[prev]);
                    temp.push_back(nums[tail]);
                    result.push_back(temp);
                    //当前条件处理完成了，所以需要缩小窗口，在窗口内部寻找是否还存在两个数
                    prev++;tail--;
                    //处理相同的数字
                    while(prev < tail && nums[prev] == nums[prev-1])prev++;
                    while(prev < tail && nums[tail] == nums[tail+1])tail--;
                }
            }
        }
        return result;
    }
};

