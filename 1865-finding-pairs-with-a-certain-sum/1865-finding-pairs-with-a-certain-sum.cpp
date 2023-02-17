class FindSumPairs {
public:
    int n;
    vector<int> n1, n2;
    unordered_map<int, int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto x : nums2)mp[x]++;
        n1 = nums1, n2 = nums2;
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index]+=val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int cou(0);
        for(auto x : n1){
            cou += mp[tot-x];
        }
        return cou;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */