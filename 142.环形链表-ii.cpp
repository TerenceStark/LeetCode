/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (true)
                {
                    if (head == slow)
                    {
                        return head;
                    }
                    head = head->next;
                    slow = slow->next;
                }
            }
        }
        return nullptr;
    }
};

/* 垃圾的哈希表
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> marked;
        while (head)
        {
            if (marked.count(head))
            {
                return head;
            }
            marked.insert(head);
            head = head->next;
        }
        return nullptr;
    }
}; 
*/

// @lc code=end
