class Solution {
public:
    #define all(a) a.begin(), a.end()
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(all(v));
        priority_queue<int> pq;
        int j = 0;
        for(int i=0;i<k;i++){
            while(j<n && v[j].first<=w){
                int cap = v[j].first;
                int prof = v[j].second;
                pq.push(prof);
                j++;
            }
            
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
