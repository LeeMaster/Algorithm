/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (56.63%)
 * Likes:    752
 * Dislikes: 0
 * Total Accepted:    151.2K
 * Total Submissions: 257.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode * head = new ListNode(-1);
        ListNode * ptr = head;
        while (l1 != nullptr && l2 != nullptr){
            if(l1 -> val <= l2 -> val){
                ptr -> next = l1;
                l1 = l1  -> next;
            }else{
                ptr -> next = l2;
                l2 = l2 -> next;
            }
            ptr = ptr -> next;
        }
        ptr -> next = l1 != nullptr ? l1 : l2;
        return head -> next;
    }
};
// @lc code=end

