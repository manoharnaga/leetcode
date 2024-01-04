class Solution {
public:
    int candy(vector<int>& ratings) {
        int size=ratings.size();
	 if(size<=1)
		 return size;
	 vector<int> num(size,1);
	 for (int i = 1; i < size; i++)
	 {
		 if(ratings[i]>ratings[i-1])
			 num[i]=num[i-1]+1;
	 }
	 for (int i= size-2; i>=0 ; i--)
	 {
		 if(ratings[i]>ratings[i+1])
			 num[i]=max(num[i+1]+1,num[i]);
	 }
	 int result=0;
	 for (int i = 0; i < size; i++)
	 {
		 result+=num[i];
	 }
	 return result;
    }
};