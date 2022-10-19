class Solution {
public:
     static bool cmp(vector<int> &a,vector<int> &b) {
	    return a[1]<b[1];
    }

int findLongestChain(vector<vector<int>> &p) {int n = p.size();
    sort(p.begin(),p.end(), cmp);
    auto curr = p[0][1];
    int count = 1;
    for(int i = 1 ; i < n ; i++){
        if(curr < p[i][0]){
            curr = p[i][1], count++;
        }
    }
    return count;
}
};