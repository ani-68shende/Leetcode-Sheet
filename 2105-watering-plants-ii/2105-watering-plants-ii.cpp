class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left = 0;
        int l = capacityA, r = capacityB;
        int right = plants.size()-1;
        int count = 0;
        while(left <= right){
            if(left == right){
                if(max(l, r)-plants[left] < 0){
                    count++;
                }
                left++;right--;
            }else{
                if(l - plants[left] >= 0){
                    l -= plants[left];
                }else{
                    count++;
                    l = capacityA;
                    l -= plants[left];
                }
                if(r - plants[right] >= 0){
                    r -= plants[right];
                }else{
                    count++;
                    r = capacityB;
                    r -= plants[right];
                }
                left++;right--;
            }
        }
        return count;
    }
};