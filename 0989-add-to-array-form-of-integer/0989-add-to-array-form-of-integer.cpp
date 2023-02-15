class Solution {
public:
    vector<int> addBinary(vector<int>a,vector<int>b) {
        vector<int> temp;
        int i=a.size()-1, j=b.size()-1,ca=0;
        int jj = 0;
        // for(auto x : a)cout << x << " ";
        // cout << "\n";
        // for(auto x : b)cout << x << " ";
        // cout << "\n";
        while(ca>0||i>=0||j>=0){
            int sum(0);
            if(i>=0){
                sum+=a[i];
                i--;
            }
            if(j>=0){
                sum+=b[j];
                j--;
            }
            sum += ca;
            int val = sum%10;
            ca = sum/10;
            temp.push_back(val);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>numa;
        while(k){
            int rem = k % 10;
            numa.push_back(rem);
            k = k / 10;
        }
        reverse(numa.begin(), numa.end());
        return addBinary(num, numa);
    }
};