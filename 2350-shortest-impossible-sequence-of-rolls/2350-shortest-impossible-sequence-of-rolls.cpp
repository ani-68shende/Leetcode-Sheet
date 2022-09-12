class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>s;int count = 0;
        for(auto x : rolls){
            s.insert(x);
            if(s.size() == k){
                count++,s.clear();
            }
        }
        return count+1;
    }
};