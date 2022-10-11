class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>t1,t2;
        vector<int>ans;
        for(vector<int>::iterator i = nums1.begin() ; i != nums1.end() ; i++){
            t1.insert(*i);
        }
        for(vector<int>::iterator i = nums2.begin() ; i != nums2.end(); i++){
            t2.insert(*i);
        }
        for(auto x : t1)if(t2.count(x))ans.push_back(x);
        return ans;
    }
};