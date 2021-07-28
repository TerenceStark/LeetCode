/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> inStack, outStack;

    void give()
    {
        while (!inStack.empty())
        {
            int temp = inStack.top();
            inStack.pop();
            outStack.push(temp);
        }
    }

    /** Initialize your data structure here. */
    MyQueue(){}

    /** Push element x to the back of queue. */
    void push(int x)
    {
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (outStack.empty())
        {
            give();
        }
        int temp = outStack.top();
        outStack.pop();
        return temp;
    }

    /** Get the front element. */
    int peek()
    {
        if (outStack.empty())
        {
            give();
        }
        return outStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return inStack.empty() &&outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
