class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> an(n);
        for (int i=0;i<n;i++){
            string s=words[i];
            sort(s.begin(),s.end());
            an[i]=s;
        }

          vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < n; i++) {
            if (an[i] != an[i - 1]) {
                ans.push_back(words[i]);
            }
        }

        return ans; 
    }
};