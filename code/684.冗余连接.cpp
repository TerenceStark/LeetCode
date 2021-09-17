/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int nodeCount = edges.size();
        vector<int> parent(nodeCount + 1);

        for (int i = i; i <= nodeCount; i++)
        {
            parent[i] = i;
        }

        for (auto &edge : edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2))
            {
                Union(parent, node1, node2);
            }
            else
            {
                return edge;
            }
        }
        return vector<int>{};
    }

    int Find(vector<int> &parent, int index)
    {
        if (parent[index] != index)
        {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int> &parent, int index1, int index2)
    {
        parent[Find(parent,index1)]=Find(parent,index2);
    }
};
// @lc code=end
