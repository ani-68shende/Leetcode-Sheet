// problem in short : pre decide where to go otherwise you won't find a way out z
// (for design of the priority queue) hume pata hai increase nahi hua hai but usko thodi pata increase nah ihua
typedef pair<double,pair<int, int>> pi;
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pi> pq;
        for (auto x : classes)
        {
            int pass = x[0], total = x[1];
            double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
            pq.push({growth, {pass,total}});
        }
        while (extraStudents--)
        {
            pi top = pq.top();
            pq.pop();
            int pass = top.second.first, total = top.second.second;
            // cout << pass << " " << total << " " << top.first << endl;
            pass++, total++;
            double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
            pq.push({growth, {pass,total}});
        }
        double sum = 0;
        while (pq.size())
        {
            int pass = pq.top().second.first, total = pq.top().second.second;
            double x = (double)(pass)/(total);
            sum += x;
            pq.pop();
        }
        int n(classes.size());
        return (double)sum / n;
    }
};