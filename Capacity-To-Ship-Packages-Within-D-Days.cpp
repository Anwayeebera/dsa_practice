class Solution {
public:
int findDays(vector<int>& weights,int cap){
    int load=0,day=1;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>cap){
        day=day+1;
        load=weights[i];
        }else
        load+=weights[i];
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            int noofDays=findDays(weights,mid);
            if(noofDays<=days){
                h=mid-1;
            }else l=mid+1;
        }
        return l;
    }
};