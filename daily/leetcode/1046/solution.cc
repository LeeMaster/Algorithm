/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 *
 * https://leetcode-cn.com/problems/last-stone-weight/description/
 *
 * algorithms
 * Easy (56.95%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 14K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * 有一堆石头，每块石头的重量都是正整数。
 * 
 * 每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
 * 
 * 
 * 如果 x == y，那么两块石头都会被完全粉碎；
 * 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
 * 
 * 
 * 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 * 
 * 
 */
#include <vector>
#include <queue>

using namespace std;
// @lc code=start


// 利用最大堆，的性质，保证最后一定会剩下一块石头，每一次抽取最大的两块石头碰撞。
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        
        for(auto stone : stones)heap.push(stone);

        while(heap.size() > 1){
            auto max1 = heap.top();
            heap.pop();
            auto max2 = heap.top();
            heap.pop();
            if(max1 != max2) heap.push(max1 - max2);
        }

        if(heap.empty())return 0;
        else return heap.top();
    }
};
// @lc code=end

