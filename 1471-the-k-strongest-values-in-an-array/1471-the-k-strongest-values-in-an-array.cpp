class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mid = n/2;
        if(n%2==0)mid--;
        int i = 0;
        int j = n-1;
        vector<pair<int, int>>tot;
        while(i <= j){
            if(abs(arr[i]-arr[mid]) > abs(arr[j]-arr[mid])){
                tot.push_back({abs(arr[i]-arr[mid]), arr[i]});
                i++;
            }else{
                tot.push_back({abs(arr[j]-arr[mid]),arr[j]});
                j--;
            }
        }
        sort(tot.begin(), tot.end(), greater<pair<int, int>>());
        // for(auto x : tot)cout << x << " ";
        // cout << "\n";
        vector<int>ans;
        for(int i = 0 ; i < k ; i++)ans.push_back(tot[i].second);
        return ans;
    }
};