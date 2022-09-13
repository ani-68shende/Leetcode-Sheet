class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        vector<int>vec;
        for(int i = 0 ; i < n ; i++){
            int maxu = 0;
            int d = 0;
            for(int j = 0 ; j < n-i ; j++){
                if(arr[j]>maxu){
                    maxu = arr[j];
                    d = j;
                }
            }
            reverse(arr.begin(), arr.begin()+d+1);
            vec.push_back(d+1);
            for(auto x: arr)cout << x << " ";
            cout << endl;
            reverse(arr.begin(), arr.begin()+n-i);
            vec.push_back(n-i);
        }
        return vec;
    }
};