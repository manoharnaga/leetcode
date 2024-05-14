class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int low = j+1;
                int high = n-1;
                int x = -(nums[i]+nums[j]);
                while(low<=high){
                    int mid = (high+low)/2;
                    if(x==nums[mid]){
                        st.insert({nums[i],nums[j],nums[mid]});
                        break;
                    }
                    else if(x<nums[mid]){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
                }
            }
        }
        for(auto it: st) ans.push_back(it);
        return ans;
        
    }
};