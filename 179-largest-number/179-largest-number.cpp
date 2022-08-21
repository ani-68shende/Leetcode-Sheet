class Solution {
public:
    static bool cmp(string & ff, string & xx){
        return ff+xx > xx+ff;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>vv;
        for(auto x : nums){
            vv.push_back(to_string(x));
        }
        sort(vv.begin(), vv.end(), cmp);
        string gg;
        for(auto x : vv)gg+= x;
        reverse(gg.begin(), gg.end());
        while(gg.size() && gg.back() == '0'){
            gg.pop_back();
        }
        if(gg.size() == 0)gg.push_back('0');
        reverse(gg.begin(), gg.end());
        return gg;
    }
};