class Solution {
public:
    // see Rbar soln i discuss ... its op
    long long minimumPerimeter(long long neededApples) {
        long long salary = 0;
        int j = 0;
        while(neededApples > salary){
            salary += 1LL*12*pow(j, 2);
            j++;
        }
        return (j-1)*8;
    }
};