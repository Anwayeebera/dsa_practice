class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
           int n = nums.size();
    vector<int> result;

    // Iterate through each subarray of size k
    for (int i = 0; i <= n - k; i++) {
        vector<int> sub(nums.begin() + i, nums.begin() + i + k);

        // Step 1: Count frequency
        unordered_map<int, int> freq;
        for (int num : sub) freq[num]++;

        // Step 2: Sort by frequency and value
        vector<pair<int, int>> arr(freq.begin(), freq.end());
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            if (a.second == b.second) return a.first > b.first; // higher value wins tie
            return a.second > b.second; // higher frequency first
        });

        // Step 3: Choose top x elements
        unordered_set<int> topX;
        for (int j = 0; j < x && j < arr.size(); j++)
            topX.insert(arr[j].first);

        // Step 4: Sum only top x frequent elements in subarray
        int sum = 0;
        for (int num : sub)
            if (topX.count(num))
                sum += num;

        result.push_back(sum);
    }
return result;
    }
};