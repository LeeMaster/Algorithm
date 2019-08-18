#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

/**
 * 首先考虑问题，将一个数组划分为K个子集且这些集合的和是相同的，那么问题转换
 * 1. 每个子集合的和应该为 accumulate(nums) / K 如果去模失败那么自然没有解
 * 2. K 为 1  直接返回 true 序列自己也是自己的子集
 * 3. 对于剩下的问题，则转换为DFS 通过搜索来检查集合个数
 * 
 * 需要注意的是，集合中的每个元素只能使用一次 
 */
class Solution {
  public:
  vector<int> used;
  int target ;
  int currentSum;
  bool canPartitionKSubsets(vector<int> & nums,int k){
    if(k == 1)return true;
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum % k != 0) return false;
    target = sum / k;

    int size = nums.size();
    currentSum = 0;
    // use this vector for record num used  
    used = vector<int>(size,0);

    return dfs(nums,used,0,k,target);
  }

  bool dfs(vector<int>& nums,vector<int> & used,int start,int K,int target){
    // 当前的寻找结果是错误的 也就是这次搜索失败了，需要回溯
    if (this -> currentSum > target)return false;
    // 找到了结果
    if(K == 0 && start == nums.size())return true;

    if(currentSum == target){
      // 开启新的一轮搜索，这次搜索成功了，寻找下一个集合
      return dfs(nums,used,0,K-1,target);
    }
    for(int i = start;i < nums.size();i++){
      if (used[i] == 0) {
        // 搜索到当前这个数字的时候，发现首先标记这个数字是可用的，如果不可用那么修改为未用
        used[i] == 1;
        currentSum += nums[i];
        if(dfs(nums,used,start + 1,K-1,target))return true;
        used[i] = 0;
      }
    }
    // 所有的条件都没有命中，所以这次搜索失败了
    return false;
  }

};