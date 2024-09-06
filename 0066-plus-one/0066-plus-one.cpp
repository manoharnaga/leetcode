class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int n = a.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            a[i] += carry;
            carry = a[i]/10;
            a[i] = a[i]%10;
        }
        if(carry){
            a.insert(a.begin(),carry);
        }
        return a;
    }
};