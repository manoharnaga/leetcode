class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int,int>> st;
        st.insert({0,k});
        vector<int> v(n+1,1e9);
        v[k] = 0;
        vector<vector<pair<int,int>>> time(n+1);
        for(auto it: times){
            time[it[0]].push_back({it[1],it[2]});
        }
        while(!st.empty()){
            auto it1= *(st.begin());
            int a = it1.first , b = it1.second;
            st.erase(it1);
            for(auto it:time[b]){
                int l = it.first, m = it.second;
                if( m + v[b] < v[l]){
                    if(v[l]!=1e9){
                        st.erase({v[l],l});
                    }
                    v[l] = m + v[b];
                    st.insert({v[l],l});
                }
            }
        }
        int ans = *max_element(v.begin()+1,v.end());
        return ans == 1e9 ?-1:ans;
    }
};