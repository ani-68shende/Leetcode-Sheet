class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0)return 0;
        long long ret = 0;
        istringstream iss(str);
        iss >> ret;
        if(ret< INT_MAX && ret > INT_MIN)return ret;
        if(ret>=INT_MAX)return INT_MAX;
        return INT_MIN;
    }
};