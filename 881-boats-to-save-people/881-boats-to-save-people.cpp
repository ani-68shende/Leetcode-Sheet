class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end(),greater<int>());
        int j = 0, i = people.size()-1;
        int count = 0;
        while(j <= i){
            if(people[j]+people[i]<=limit){
                j++;
                i--;
                count++;
            }
            else{
                count++;
                j++;
            }
        }
        return count;
    }
};