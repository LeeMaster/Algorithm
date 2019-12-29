/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (47.39%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    60.6K
 * Total Submissions: 126.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>
#include <queue>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// functor could be used in the container algorithm 
class ListNodeComparter{
    public:
        bool operator()(ListNode * node1, ListNode* node2){
            return node1 -> val > node2 -> val;
        }
};


// 非常朴素的方法 直接循环 K个表，然后将其从大到小都 装进 dummy 后面去
// 优先队列会好一点
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return nullptr;

        // 用来装当前最小的节点
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparter> queue;

        ListNode * dummy = new ListNode(0);
        auto head = dummy;

        for(auto i = 0; i < lists.size(); i++)
            if(nullptr != lists[i])queue.push(lists[i]);
        
        while(!queue.empty()){

            ListNode * node = queue.top();
            queue.pop(); 

            head -> next = node;
            head  = head -> next;

            // 处理完了一个节点，继续向下压缩
            auto next = node -> next;
            if(nullptr != next){
                queue.push(next);
            }
        }

        return dummy -> next;
    }
};
// @lc code=end

