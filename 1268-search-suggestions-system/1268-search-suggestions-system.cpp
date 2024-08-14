class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& a, string target) {
        vector<vector<string>> ans;
        int n = a.size();
        sort(a.begin(),a.end());
        string x = "";
        for(char ch: target){
            x+=ch;
            vector<string> temp;
            int idx = lower_bound(a.begin(),a.end(),x)-a.begin();
            for(int i=0;i<3 && i+idx<n;i++){
                string s = a[i+idx];
                if(s.find(x)) break;
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};