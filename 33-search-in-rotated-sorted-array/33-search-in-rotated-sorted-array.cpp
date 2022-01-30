class Solution {
public:
    int search1(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else if(nums[mid]<target)
            {
                left = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int if_not_gound = nums[0];
        int high = n-1;
        int middle=0;
        while(low <= high){
            if(nums[low] <= nums[high]){
                middle = low;break;
            }
            int mid = low +(high-low)/2;
            int pre = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(nums[mid] <= nums[pre] && nums[mid] <= nums[next]){
                middle = mid;
                break;
            }
            else if(nums[low] <= nums[mid]){
                low = mid+1;
            }else if(nums[mid] <= nums[high]){
                high = mid-1;
            }
        }
        cout << middle << endl;
        int y = -1;
        int x = -1;
        vector<int>y1(nums.begin(), nums.begin()+middle);
        vector<int>y2(nums.begin()+middle, nums.end());
        y = search1(y1, target);
        x = search1(y2, target);
        if(x == -1 && y == -1)return -1;
        else if(x==-1)return y;
        else return x+middle;;
    }
};