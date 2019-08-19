
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 寻找两个有序数组的中位数
 * 
 * 中位数的性质，比其小的数在其左侧，比齐大的数在其右侧
 * 推理一下 需要满足的条件为
 * 1. len(left_part) == len(right_part)
 * 2. max(left_part) <= min(right_part)
 * 对于单一数组，这个问题很简单，因为已经排序了，所以只需要找到中间位置就可以了
 * 而对于两个已经排序的数组
 * 只需要保证 i 和 j 两个指针
 * 1. i + j == m - i + n - j 保证确实是中位
 * 2. nums2[j-1] <= nums1[i] && nums1[i-1] <= nums2[j] 双重保证，左侧的最大的小于右侧最小的。
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
          nums1.swap(nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        int imin = 0;
        int imax = m;
        int ihalf = (m + n + 1) / 2;
        double max_of_left, min_of_right;

        while(imin <= imax) {
          int i = (imin + imax) / 2;
          int j = ihalf - i;

          // 二分查找过程
          if(i < m && nums2[j-1] > nums1[i])
            imin = i + 1;
          else if(i > 0 && nums1[i-1] > nums2[j])
            imax = i - 1;
          else {
            if(i == 0)
              max_of_left = nums2[j-1];
            else if(j ==0)
              max_of_left = nums1[i-1];
            else
              max_of_left  = max(nums1[i-1], nums2[j-1]);

            if ((m + n) % 2 == 1)
              return max_of_left;
            
            if (i == m)
              min_of_right = nums2[j];
            else if(j == n)
              min_of_right = nums1[i];
            else
              min_of_right = min(nums1[i], nums2[j]);
            
            return (max_of_left + min_of_right) / 2.0;
          }
        }
        return 0.0;
    }
};

