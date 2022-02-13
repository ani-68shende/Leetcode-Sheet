class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int i = 0;
        int sum = capacity;
        int count = 0;
        while(i < n ){
            if(plants[i] > sum){
                sum = capacity;
                sum -= plants[i];
                count+=i*2+1;
            }else{
                sum -= plants[i];
                count++;
            }
            i++;
        }
        return count;
    }
};