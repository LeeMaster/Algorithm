/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (58.81%)
 * Likes:    563
 * Dislikes: 0
 * Total Accepted:    86.2K
 * Total Submissions: 146.5K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */
#include<string>
#include<unordered_map>

using namespace std;

/*
* TODO: 这个解决方案抄了一波，应该可以利用Compiler 相关理论来解决的 同时需要学习一下计数相关理论
* 
* M -> 1000 
* DCCC -> 800 
* DCC -> 700 
* DC -> 600 
* D -> 500 
* CD -> 400 
* CCC -> 300 
* CC -> 200 
* C -> 100 
* 其他的同理，这样的话 可以从头开始遍历，向后看一个字符就可以确定是否是一个组合数   IV IX XL XC CD 
*/
class Solution {
public:

    int romanToInt(string s) {
        int a[]={1000,500,100,50,10,5,1};
        char b[]={'M','D','C','L','X','V','I'};
        unordered_map<char,int>m;
        for(int i = 0; i < 7; ++ i)
            m.insert(pair<char,int>(b[i],a[i]));
        int ans = 0;
        for(int i = 0; i < s.length(); ++ i){
          //如果当前的数字 小于 后面的一个数字 ，那么需要减去当前的数字，累加到结果中，
            if(i != s.length() - 1 && m[s[i]] < m[s[i+1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }
        return ans;
    }
};

