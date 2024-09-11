class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        for(auto flower: flowers){
            mp[flower[0]]++;
            mp[flower[1]+1]--;
        }
        int cumulativeShift = 0;
        for(auto& it: mp){
            it.second += cumulativeShift;
            cumulativeShift = it.second;
        }

        vector<int> ans;
        for(int i: people){
            int cnt = 0;
            auto it = mp.lower_bound(i);
            int f = 0;
            if(it==mp.end() || it->first!=i){
                f = (it==mp.begin());
                it--;
            }
            int sum = 0;
            if(f) sum = 0;
            else  sum = it->second;
            ans.push_back(sum);
        }
        return ans;
    }
};