class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        int count(0), i(0);
        int n = jobs.size();
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        while(i < n){
            count=max(((jobs[i]%workers[i]) == 0 ? jobs[i]/workers[i] : (jobs[i]/workers[i])+1), count);
            i++;
        }
        return count;
    }
};