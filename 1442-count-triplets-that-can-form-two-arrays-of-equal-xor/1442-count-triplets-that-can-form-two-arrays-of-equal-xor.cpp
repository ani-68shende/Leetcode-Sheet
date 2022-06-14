class Solution {
public:
    // god or what method
    
    // a == b
    // a = b
    // a^b = b^b
    // a^b = 0
    //find all the substring length because the pivot can be any point in the substring so to count that we add the length of the substring each time we find the xor to be zero
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int kaju = arr[i];
            for(int j = i+1 ; j < n ; j++){
                kaju ^= arr[j];
                if(kaju == 0)count+= j-i;
            }
        }
        return count;
    }
};