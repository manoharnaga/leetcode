class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] =  1;
        mp['V'] =  5;
        mp['X'] =  10;
        mp['L'] =  50;
        mp['C'] =  100;
        mp['D'] =  500;
        mp['M'] =  1000;
        int ans=0;
        int n=s.size();
        int i;
        for(i=0;i<n-1;i++){
            if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X')){
                if(s[i+1]=='V'){
                    ans += 4;
                }
                else{
                    ans += 9;
                }
                i++;
            }
            else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C')){
                if(s[i+1]=='L'){
                    ans += 40;
                }
                else{
                    ans += 90;
                }
                i++;
            }
            else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')){
                if(s[i+1]=='D'){
                    ans += 400;
                }
                else{
                    ans += 900;
                }
                i++;
            }
            else{
                ans += mp[s[i]];
            }
        }
        if(i<n) ans+=mp[s[i]];
        return ans;
    }
};