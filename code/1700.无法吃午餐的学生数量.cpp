/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int stuSum = accumulate(students.begin(), students.end(), 0);
        int sanSum = accumulate(sandwiches.begin(), sandwiches.end(), 0);
        
        int size = students.size();
        int n = stuSum - sanSum;

        if (n == 0)
        {
            return 0;
        }

        else if (n > 0)
        {
            for (int i = size - 1; i >= 0; i--)
            {
                if (sandwiches[i] == 0)
                {
                    n--;
                }
                if (n == 0)
                {
                    return size - i;
                }
            }
        }

        else
        {
            for (int i = size - 1; i >= 0; i--)
            {
                if (sandwiches[i] == 1)
                {
                    n++;
                }
                if (n == 0)
                {
                    return size - i;
                }
            }
        }
        return 0;
    }
};
// @lc code=end
