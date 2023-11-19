class Solution {
public:
    string removeStars(string s) {
        stack<pair<int,char>> st1,st2;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st1.push({i,s[i]});
            }
            else{
                if(st1.empty()){
                    st2.push({i,s[i]});
                }
                else{
                    st1.pop();
                }
            }
        }
        vector<pair<int,char>> v;
        while(!st1.empty()){
            v.push_back({st1.top().first,st1.top().second});
            st1.pop();
        }
        while(!st2.empty()){
            v.push_back({st2.top().first,st2.top().second});
            st2.pop();
        }
        sort(v.begin(),v.end());
        string ans="";
        for(auto it: v){
            ans+=it.second;
        }
        return ans;
    }
};