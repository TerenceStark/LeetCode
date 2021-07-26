/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> hashmap;
        stack<int> stack;
        vector<int> ans;

        for (int i = 0; i < nums2.size(); i++)
        {
            while (!stack.empty() && stack.top() < nums2[i])
            {
                hashmap[stack.top()] = nums2[i];
                stack.pop();
            }
            stack.push(nums2[i]);
        }

        while (!stack.empty())
        {
            hashmap[stack.top()] = -1;
            stack.pop();
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(hashmap[nums1[i]]);
        }

        return ans;
    }
};
// @lc code=end
