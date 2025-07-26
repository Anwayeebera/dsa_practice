class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findFirstOccurrence(nums,target);
        if(first==-1)return {-1,-1};
        int last=findLastOccurrence(nums,target);
        return {first,last};
    }
    
private:
    int findFirstOccurrence(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int firstOccurrence = -1;
        
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target){
                firstOccurrence=mid;
                h=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
            h=mid-1;
            }
        }
        return firstOccurrence;
    }
    
    int findLastOccurrence(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        int lastOccurrence = -1;
        
       while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]==target){
            lastOccurrence=mid;
            l=mid+1;
        }else if(nums[mid]<target){
            l=mid+1;
        }
        else{
        h=mid-1;
        }
       }
        
        return lastOccurrence;
    }
};
