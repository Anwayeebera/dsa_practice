class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0, j=s.size();
        while(i<=j){
            if(isalpha(s[i])&&isalpha(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }else if(isalpha(s[i])&&!isalpha(s[j]))j--;
            else if(!isalpha(s[i])&&isalpha(s[j]))i++;
            else{
                i++;
                j--;
            }
    }
        return s;
    }
};