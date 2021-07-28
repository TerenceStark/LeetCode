/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMax(n);
        for (int i = 0; i < n; ++i) {
            if (i % k == 0) {
                prefixMax[i] = nums[i];
            }
            else {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || (i + 1) % k == 0) {
                suffixMax[i] = nums[i];
            }
            else {
                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
            }
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; ++i) {
            ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
        }
        return ans;
    }
};

/* class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        int max = 0;
        int size = nums.size();
        if (k == 1)
        {
            return nums;
        }

        for (int i = 0; i < size - k + 1; i++)
        {
            max = nums[i];
            for (int j = i + 1; j < k + i; j++)
            {
                if (max < nums[j])
                {
                    max = nums[j];
                }
            }
            ans.push_back(max);
        }
        return ans;
    }
}; */
// @lc code=end
