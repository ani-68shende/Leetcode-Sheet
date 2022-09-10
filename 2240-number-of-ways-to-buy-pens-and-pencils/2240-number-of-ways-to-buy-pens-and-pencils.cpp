class Solution {
public:
    long long waysToBuyPensPencils(int total, int pen, int pencil) {
        long long count(0);
        int j = 0;
        while(pen*j <= total){
            count+= (1+((total-pen*j*1LL)/pencil));
            j++;
        }
        return count;
    }
};