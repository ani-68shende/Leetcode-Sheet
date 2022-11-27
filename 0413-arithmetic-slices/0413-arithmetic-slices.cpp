class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int lengtho = 0;
        for(int i = 0 ; i <= n-3 ; i++){
            int first = nums[i];
            int diff = nums[i+1]-nums[i];
            int counto = 1;
            int mul = 1;
            for(int j = i ; j <= n-2 ; j++){
                if(nums[j+1]-nums[j]==diff){
                    counto++;
                }else{
                    break;
                }
            }
            if(counto >= 3){
                lengtho += counto-2;
            }
        }
        return lengtho;
    }
};