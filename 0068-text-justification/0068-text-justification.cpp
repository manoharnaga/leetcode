class Solution {
public:
    string getXSpaces(int n){
        string s="";
        for(int i=0;i<n;i++) s+=" ";
        return s;
    }

    string getTransform(vector<string>& words,int start,int end,int sz,int maxWidth,int isLastWord){
        int len = (end-start+1);
        string s = "";
        int spc = maxWidth-sz;
        if(len==1){
            s += words[start];
            s += getXSpaces(spc);
        }
        else{
            int perword,extra;
            if(isLastWord){
                perword = 1;
                extra = 0;
            }
            else{
                perword = spc/(len-1);
                extra = spc % (len-1);
            }
            for(int j=start;j<end;j++){
                s+=words[j];
                s+=getXSpaces(perword);
                if(extra){
                    s+=" ";
                    extra--;
                }
            }
            s+=words[end];
            if(isLastWord){
                int leftover = maxWidth-sz-(len-1);
                s+=getXSpaces(leftover);
            }
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start = 0;
        int sz = 0,spc = 0;
        for(int i=0;i<words.size();i++){
            if((sz+spc+words[i].size())>maxWidth){
                string s = getTransform(words,start,i-1,sz,maxWidth,0);
                ans.push_back(s);
                start = i;
                sz = spc = 0;
            }
            sz += (int)words[i].size();
            spc++;
        }
        string s = getTransform(words,start,(int)words.size()-1,sz,maxWidth,1);
        ans.push_back(s);
        return ans;
    }
};
