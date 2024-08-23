class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        int i=0,j=0,k=0;
        while(v.size()<n){
            int val = min({2*v[i],3*v[j],5*v[k]});
            if(2*v[i]==val) i++;
            if(3*v[j]==val) j++;
            if(5*v[k]==val) k++;
            v.push_back(val);
        }
        // for(int val: v) cout<<val<<" ";
        // cout<<"\n";
        return v.back();
    }
};