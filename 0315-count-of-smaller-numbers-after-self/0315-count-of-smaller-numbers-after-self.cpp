#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define pajaz tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        pajaz op;
        vector<int>ans(nums.size(), 0);
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            ans[i] = op.order_of_key(nums[i]);
            op.insert(nums[i]);
        }
        return ans;
    }
};