class Solution {
public:
bool possible(vector<int>&arr,int day,int m,int k){
    int cnt=0;
    int noofB=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noofB+=cnt/k;
            cnt=0;
        }}
        noofB+=cnt/k;
      return noofB>=m;
    
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=1LL*m*k;
        if(val>n)return -1;
        int mini=INT_MAX ,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);

        }
        int l=mini,h=maxi;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(possible(bloomDay,mid,m,k)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};