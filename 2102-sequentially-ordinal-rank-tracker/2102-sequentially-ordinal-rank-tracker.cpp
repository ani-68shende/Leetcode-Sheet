#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define gg tree<pair<int,string>, null_type,less<pair<int,string>>, rb_tree_tag,tree_order_statistics_node_update>
  
class SORTracker {
public:
    gg pq;
    int count = -1;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        pq.insert({-score, name});
    }
    
    string get() {
        count++;
        auto itr = *(pq.find_by_order(count));
        return itr.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */