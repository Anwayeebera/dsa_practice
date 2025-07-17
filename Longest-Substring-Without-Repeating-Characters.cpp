class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxlen=0;
        unordered_set<char> cs;
        int l=0;
        for(int r=0;r<n;r++){
            if(cs.count(s[r])==0){
                cs.insert(s[r]);
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            else{
                while(cs.count(s[r])){
                    cs.erase(s[l]);
                    l++;
                }
                cs.insert(s[r]);
        }
        }
        return maxlen ;
    }
};