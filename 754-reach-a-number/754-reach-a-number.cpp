class Solution {
public:
    // yt dinesh kumar
    int reachNumber(int target) {
        if(target<0)target*=(-1);
        int sum=0;
        int steps = 0;
        while(true){
            steps++;
            sum +=steps;
            if((sum-target)>=0 && !((sum-target)&1))return steps;
        }
        return stoi("icpc bois");
    }
};