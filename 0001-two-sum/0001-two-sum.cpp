class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        map<int,int> mp;
        int n = a.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({a[i],i});
        sort(v.begin(),v.end());
        int low=0,high=n-1;
        while(low<high){
            int sum = v[low].first+v[high].first;
            if(sum>target) high--;
            else if(sum<target) low++;
            else return {v[low].second,v[high].second};
        }
        return {-1,-1};
    }
};