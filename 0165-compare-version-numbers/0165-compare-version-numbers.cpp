class Solution {
public:
    int string_to_int(string s){
        string v = s;
        reverse(v.begin(),v.end());
        while(!v.empty() && v.back()=='0') v.pop_back();
        reverse(v.begin(),v.end());
        s = v;
        int val = 0;
        int mult = 1;
        for(int i=s.size()-1;i>=0;i--){
            val += (mult*(s[i]-'0'));
            if(i>0) mult*=10;
        }
        return val;
    }

    vector<int> version_int_format(string version,int n){
        vector<int> v;
        string x;
        for(int i=0;i<version.size();i++){
            char ch = version[i];
            if(ch=='.'){
                int val = string_to_int(x);
                v.push_back(val);
                x = "";
            }
            else x+=ch;
        }

        if(!x.empty()){
            int val = string_to_int(x);
            v.push_back(val);
        }
        while(v.size()<n){
            v.push_back(0);
        }
        return v;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        int n = max((int)version1.size(),(int)version2.size());
        v1 = version_int_format(version1,n);
        v2 = version_int_format(version2,n);
        
        // for(int val: v1) cout<<val<<" ";
        // cout<<"\n";
        // for(int val: v2) cout<<val<<" ";
        // cout<<"\n";
        for(int i=0;i<n;i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }
        return 0;
    }
};