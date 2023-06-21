class TopVotedCandidate {
public:
    vector<int>t, p;
    int n;
    int maxu = 0; int ID = 0;
    map<int, int>mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        n = times.size();
        for(int i = 0 ; i < n ; i++){
            t.push_back(times[i]);
            mp[persons[i]]++;
            if(maxu <= mp[persons[i]]){
                ID = persons[i];
                maxu = mp[persons[i]];
            }
            p.push_back(ID);
        }
    }
    
    int q(int t1) {
        auto itr = upper_bound(t.begin(), t.end(), t1);
        return p[itr-t.begin()-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */