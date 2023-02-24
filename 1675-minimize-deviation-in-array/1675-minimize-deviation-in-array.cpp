// nice discuss soln
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // create a set to store unique values after processing
        set<int> st;
        // iterate over each element in the input vector
        for(int i=0;i<nums.size();i++){
            // if the element is odd, multiply by 2 and add to set
            if(nums[i] % 2 != 0)
                nums[i] *= 2;
            st.insert(nums[i]);
        }
        // initialize minimum deviation as the difference between max and min values in set
        int mnDev = *st.rbegin() - *st.begin();
        // while the maximum value in the set is even
        while(*st.rbegin() % 2 == 0){
            // remove the maximum value from the set
            int temp = *st.rbegin();
            st.erase(temp);
            // divide by 2 and add back to the set
            temp /= 2;
            st.insert(temp);
            // update minimum deviation with new value
            mnDev = min(mnDev, *st.rbegin() - *st.begin());
        }   
        // return the minimum deviation
        return mnDev;
    }
};