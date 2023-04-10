class Solution {
public:
    bool isValid(string s1) {
        stack<char>s;
        for(int i = 0 ; i < s1.size() ; i++)
        {
            if(s1[i] == '(' || s1[i] == '[' || s1[i] == '{')
                s.push(s1[i]);
            else
            {
                char ch;
                if(s1[i] == ')')
                    ch = '(';
                else if(s1[i] == ']')
                    ch = '[';
                else if(s1[i] == '}')
                    ch = '{';
                if(s.empty() || s.top()!=ch)
                    return false;
                else if(s.top() == ch)
                    s.pop();
                    

            }
        }
        if(s.empty())
            return true;
        return false;
    }
};