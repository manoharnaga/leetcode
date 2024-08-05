class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mp,v;
        for(string s: arr) mp[s]++;
        for(auto it: mp){
            if(it.second==1){
                v[it.first]=1;
            }
        }
        int i=0;
        for(string s: arr){
            if(v[s]){
                i++;
                if(i==k) return s;
            }
        }
        return "";
    }
};