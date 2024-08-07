class Solution {
public:
    typedef long long ll;
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        set<vector<int>> v;
        for(int i=0;i<n;i++){
            if (i > 0 && a[i] == a[i - 1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && a[j-1]==a[j]) continue;
                int low = j+1,high = n-1;
                while(low<high){
                    ll sum = ((ll)a[i]+a[j])+((ll)a[low]+a[high]);
                    if(sum==target){
                        ans.push_back({a[i],a[j],a[low],a[high]});
                        int plow = low;
                        int phigh = high;
                        while(a[low]==a[plow] && low<high) low++;
                        while(a[high]==a[phigh] && low<high) high--;
                        // low++;
                        // high--;
                    }
                    else if(sum>target) high--;
                    else  low++;
                }
            }
        }
        // for(auto i: v) ans.push_back(i);
        return ans;
    }
};