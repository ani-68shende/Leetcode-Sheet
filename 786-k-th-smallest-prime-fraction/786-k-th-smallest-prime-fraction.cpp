class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int, int>>>pq;
        int n = arr.size();
        for(auto i =0 ; i < n ; i++){
            int num1 = arr[i];
            for(int j = i+1 ; j < n ; j++){
                int num2 = arr[j];
                pq.push({(num1*1.00)/(num2*1.00),{num1, num2}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        auto top = pq.top();
        return {top.second.first, top.second.second};
    }
};