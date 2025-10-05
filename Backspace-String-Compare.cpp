class Solution {
    public:
    string removeStars(string s){
        stack<char> st;
        for(char c:s){
            if(c=='#'&& !st.empty()){
                st.pop();
            }
            else if(c!='#'){
                st.push(c);
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    bool backspaceCompare(string s, string t) {
        return removeStars(s)== removeStars(t);
        
    }
};