class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i] = i+1;
        sort(v.begin(),v.end(),[](const auto& x,const auto& y){
            string a = to_string(x);
            string b = to_string(y);
            return a<b;
        });
        return v;
    }
};