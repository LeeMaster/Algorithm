/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (57.48%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    36K
 * Total Submissions: 62.6K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
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


class Solution {
public:
    /**
     * 利用两个指针和sentry的理念，进行处理，最后的max可能不是链表的最后一个节点，所以需要将next
     * 设置为nullptr
     * 为什么要利用sentry 原因就在于，min 这个指针可能是空的，所以为了避免 NPE 就利用了 sentry
     */
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;

        auto minDummy = new ListNode(0);
        auto maxDummy = new ListNode(0);

        auto min = minDummy;
        auto max = maxDummy;

        for (auto pointer = head; pointer != nullptr; pointer = pointer -> next){
            if(pointer -> val < x){
                min -> next = pointer;
                min = min -> next;
            }else{
                max -> next = pointer;
                max = max -> next;
            }
        }

        max -> next = nullptr;
        min -> next = maxDummy -> next;

        return minDummy -> next;
    }
};
// @lc code=end

