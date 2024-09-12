class Solution {
public:
    string frequencySort(string s) {
        vector<int> a(128);
        for(char ch: s) a[ch]++;
        
        auto cmpfunc = [&a](char x,char y){
            if(a[x]==a[y]) return x<y;
            return a[x]<a[y];
        };
        sort(s.begin(),s.end(),cmpfunc);
        reverse(s.begin(),s.end());
        return s;
    }
};