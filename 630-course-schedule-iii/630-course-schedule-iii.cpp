class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int>b){return a[1]<b[1];});
        int total = 0;
        priority_queue<int>pq;
        for(int i = 0 ; i < courses.size() ; i++){
            int dur = courses[i][0];
            int end = courses[i][1];
            if(total + dur <= end){
                pq.push(dur);
                total += dur;
            }
            else if(pq.size() && pq.top() > dur){
                total -= pq.top() -dur;
                pq.pop();
                pq.push(dur);
                
            }
        }
        return pq.size();
    }
};