class Solution {
public:
    // pushing -1 is the key here,,, and as we need the length one more hint is to concentrate on index...
    //prajjwa reading this ik
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            if(stk.top()!=-1&&s[i]==')'&&s[stk.top()]=='(')
            {
                // chal hat aisa karke nikala isko
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
};