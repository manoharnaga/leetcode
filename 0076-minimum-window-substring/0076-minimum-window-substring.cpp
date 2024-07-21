class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mp(128,0);
        for(char ch: t) mp[ch]++;
        int begin = 0,end = 0,d = INT_MAX, cnt = t.size(),head = 0;
        while(end<s.size()){
            if(mp[s[end++]]-->0) cnt--;
            while(cnt==0){
                if((end-begin)<d){
                    head = begin;
                    d=(end-begin);
                };
                if(mp[s[begin++]]++==0) cnt++;
            }
        }
        return d==INT_MAX?"":s.substr(head,d);
    }
};