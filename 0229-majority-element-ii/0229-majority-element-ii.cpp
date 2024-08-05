class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        if(n==1) return {a[0]};
        // if(n==2) return {a[0],a[1]};
        int cnt1=0,cnt2=0;
        int ele1=INT_MAX,ele2=INT_MAX;
        for(int i=0;i<n;i++){
            if(!cnt1 && ele2!=a[i]){
                cnt1=1;
                ele1 = a[i];
            }
            else if(!cnt2 && ele1!=a[i]){
                cnt2 = 1;
                ele2 = a[i];
            }
            else if(a[i]==ele1) cnt1++;
            else if(a[i]==ele2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1==a[i]) cnt1++;
            if(ele2==a[i]) cnt2++;
        }
        vector<int> ans;
        if(cnt1>(n/3)) ans.push_back(ele1);
        if(cnt2>(n/3)) ans.push_back(ele2);
        return ans;
    }
};