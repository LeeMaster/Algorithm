/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (66.45%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 5.2K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
 * 
 * 示例 1:
 * 
 * 输入: S = "ababcbacadefegdehijhklij"
 * 输出: [9,7,8]
 * 解释:
 * 划分结果为 "ababcbaca", "defegde", "hijhklij"。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 * 
 * 
 * 注意:
 * 
 * 
 * S的长度在[1, 500]之间。
 * S只包含小写字母'a'到'z'。
 * 
 * 
 */
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

/**
 * 贪心，首先处理一下找到最后一个位置，最后再遍历字符串找到每一个序列
 * 这里的贪心第一就是尽可能多的 划分片段
 * 但是每一个字母的开始结束都可能组成一个片段，所以片段之间会有重叠，因此需要贪心扩展
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
    vector<int> result;
        unordered_map<char, int> map; 

        int start = 0, end = 0;
        for (int i = 0; i < S.size(); i ++) {
            map[S[i]] = i;
        }
        for (int i = 0; i < S.size(); i ++) {
            // 贪心处理在这里
            end = max(end, map[S[i]]);
            
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};

