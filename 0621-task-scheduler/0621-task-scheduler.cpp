class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<int,int> mp;
        int cnt = 0;
        for(char ch: tasks){
            mp[ch]++;
            cnt = max(cnt,mp[ch]);
        }
        int ans = (cnt-1)*(n+1);
        for(auto it: mp){
            if(it.second == cnt) ans++; 
        }
        return max((int)tasks.size(),ans);
    }
};