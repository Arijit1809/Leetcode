class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end()),right = accumulate(weights.begin(),weights.end(),0);
        while(left<right){
            int mid = left + (right-left)/2;
            //here value of mid is the maximum weight possible to be put on the ship
            int currWeight = 0,daysNeeded = 1;
            for(int i =0;i<weights.size();i++)
            {
                if(currWeight+weights[i]<=mid){
                    currWeight+=weights[i];  
                }else{
                    currWeight = weights[i];
                    daysNeeded++;
                }
            }
            if(daysNeeded>days) left = mid+1;
            else right = mid;
        }
        return left;
    }
};