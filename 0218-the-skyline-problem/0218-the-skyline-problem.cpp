class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> v,ans;
        for(auto it: buildings){
            v.push_back({it[0],-it[2]});
            v.push_back({it[1],it[2]});
        }
        sort(v.begin(),v.end());
        int h = 0;
        int n = v.size();
        multiset<int> pq{0};
        for(int i=0;i<n;i++){
            int curH = v[i][1];
            int idx = v[i][0];
            if(curH<0){
                pq.insert(-curH);
            }
            else{
                pq.erase(pq.find(curH));
            }
            auto it = *pq.rbegin();
            if(it!=h){
                h = it;
                ans.push_back({idx,h});
            }
        }
        return ans;
    }
};