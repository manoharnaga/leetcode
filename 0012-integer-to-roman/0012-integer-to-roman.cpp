class Solution {
public:
    string intToRoman(int n) {
        map<int,char> mp;
        mp[1]='I';
        mp[5]='V';
        mp[10]='X';
        mp[50]='L';
        mp[100]='C';
        mp[500]='D';
        mp[1000]='M';
        
        // map<char,int> mp2;
        // mp2['I']=7;
        // mp2['V']=6;
        // mp2['X']=5;
        // mp2['L']=4;
        // mp2['C']=3;
        // mp2['D']=2;
        // mp2['M']=1;
        vector<int> v = {1000,500,100,50,10,5,1};
        // vector<char> v2 = {'I','V','X','L','C','D','M'};
        // reverse(v2.begin(),v2.end());
        string ans;
        for(int i=0;i<v.size();i++){
            while((n-v[i])>=0){
                n-=v[i];
                ans+=mp[v[i]];
            }
            if(n==4 && (i==5)){
                ans += "IV";
                n -= 4;
            }
            else if(n==9 && (i==4)){
                ans += "IX";
                n -= 9;
            }
            else if((n/40) == 1 && (i==3)){
                ans += "XL";
                n -= 40;
            }
            else if((n/90) == 1 && (i==2)){
                ans += "XC";
                n -= 90;
            }
            else if((n/400) == 1 && (i==1)){
                ans += "CD";
                n -= 400;
            }
            else if((n/900) == 1 && (i==0)){
                ans += "CM";
                n -= 900;
            }
        }
        return ans;
    }
};