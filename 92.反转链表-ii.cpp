/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;

        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }

        ListNode *leftNode = pre->next;
        ListNode *rightNode =leftNode;
        for (int i = 0; i < right - left; i++)
        {
            rightNode = rightNode->next;
        }
        ListNode *suc = rightNode->next;
        pre->next = nullptr;
        rightNode->next = nullptr;

        reverseList(leftNode);
        pre->next = rightNode;
        leftNode->next = suc;
        return dummy->next;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end
