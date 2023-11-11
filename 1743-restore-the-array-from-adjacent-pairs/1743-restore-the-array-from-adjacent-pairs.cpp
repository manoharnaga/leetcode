class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        map<int,int> mp;
        map<int,vector<int>> v;
        
        for(auto it: a){
            mp[it[0]]++;
            mp[it[1]]++;
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        int start;
        for(auto it: mp){
            if(it.second == 1){
                start = it.first;
                break;
            }
        }
        set<int> st;
        vector<int> ans;
        while(ans.size()<a.size()){
            st.insert(start);
            ans.push_back(start);
            int next = v[start][0];
            if(st.find(next)!=st.end()){
                next = v[start][1];
            }
            start = next;
        }
        ans.push_back(start);
        return ans;
    }
};