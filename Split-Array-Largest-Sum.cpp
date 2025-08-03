class Solution {
public:
  int largestsum(vector<int>& nums, int sum1){
    int stu=1;
    int splitsums=0;
    for(int i=0;i<nums.size();i++){
        if(splitsums+nums[i]<=sum1){
            splitsums+=nums[i];
        }else{
            stu++;
            splitsums=nums[i];
        }
    }
    return stu;
  }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)return -1;
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            if(largestsum(nums,mid)>k){
                l=mid+1;
            }
            else h=mid-1;
        }
        return l;
        
    }
};