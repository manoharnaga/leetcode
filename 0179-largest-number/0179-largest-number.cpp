class Solution {
public:
    string largestNumber(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            string p = to_string(x);
            string q = to_string(y);
            string l = p+q;
            string r = q+p;
            return l>r;
        });
        string ans;
        for(int val: a) ans+=to_string(val);
        map<int,int> mp;
        for(int val: a) mp[val]++;
        if(mp.size()==1 && mp[0]) return "0";
        return ans;
    }
};