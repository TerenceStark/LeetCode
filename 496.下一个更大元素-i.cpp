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
        vector<int> result;
        stack<int> temp;
        int larger_number = -1;

        for (int i = nums2.size(); i > 0; i--)
        {
            temp.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            while (nums1[i] != temp.top() && !temp.empty())
            {
                if (temp.top() > nums2[i])
                {
                    larger_number = temp.top();
                }
                temp.pop();
            }
            result[i]=(larger_number);
            larger_number=-1;
        }

        return result;
    }
};
// @lc code=end
