/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 * 
 * 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N
 * 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
 * 
 * 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
 * 
 * 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为
 * 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
 * 
 * 为了尽快到达公主，骑士决定每次只向右或向下移动一步。
 * 
 * 
 * 
 * 编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
 * 骑士的健康点数没有上限。
 * 
 * 任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
 * 
 */
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;
/**
 * 从结果逆向推
 * 从左上角到有下角的话，这个问题就成了一个贪心的问题，每一次都是选择最小路径，每一次都是选择的当前最优
 * 那么换个想法，从右下角往上推
 * 那么这个问题就变成了，将每一个格子内的值转换为需要的初始生命，将路径上的 HP 都累加就得到了最后的结果
 * 
 * Tips 当正向DP 不能用的时候 可以考虑 逆向 DP 
 * 
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();

        vector<vector<int>> dp(row,vector<int>(col));
        // 如果最后的一个格子大于0，则这个格子并不需要初始HP 否则则为相反数 即到这个格子的时候需要有的HP
        if(dungeon[row-1][col-1] > 0)dp[row-1][col-1] = 0;
        else dp[row-1][col-1] = -dungeon[row-1][col-1];
        
        //为了DP能进行，先将右边和下边两条边处理一下
        //如果房间内的有血瓶那么进入这个房间的时候不需要消耗HP，否则则为上一个格子需要的，减去即可
        for(int i = row-2;i >= 0;i--){
            // 处理右边
            dp[i][col-1] = dp[i+1][col-1] <= dungeon[i][col-1] ? 0 : dp[i+1][col-1] - dungeon[i][col-1];
        }

        for(int i = col-2;i >= 0;i--){
            //处理下边
            dp[row-1][i] = dp[row-1][i+1] <= dungeon[row-1][i] ? 0 : dp[row-1][i+1] - dungeon[row-1][i];
        }

        // DP 
        for(int i = row-2;i >=0;i--)
            for(int j = col-2;j >=0;j--){
                dp[i][j] = min(
                    dungeon[i][j] >= dp[i+1][j] ? 0 : dp[i+1][j] - dungeon[i][j],
                    dungeon[i][j] >= dp[i][j+1] ? 0 : dp[i][j+1] - dungeon[i][j]
                );
            }

        return dp[0][0] + 1;
    }
};


