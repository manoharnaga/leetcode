class Solution {
public:
    string rec(char s[],int start,int end){
        // if(start>end) return "";
        int i = start;
        string ans;
        while(i<=end){
            // if(s[i]=='[' || s[i]==']') continue;
            if(isdigit(s[i])){
                string dig = "";
                while(s[i]!='['){
                    dig+=s[i];
                    i++;
                }
                int rep = stoi(dig);
                int j = i+1;
                int cnt = 1;
                while(1){
                    if(s[j]=='[') cnt++;
                    if(s[j]==']') cnt--;
                    if(!cnt) break;
                    j++;
                }
                string res = rec(s,i+1,j-1);
                for(int k=0;k<rep;k++) ans+=res;
                i=j+1;
            }
            else{
                ans+=s[i++];
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int n = s.size();
        char v[n];
        for(int i=0;i<n;i++) v[i]=s[i];
        return rec(v,0,n-1);
    }
};