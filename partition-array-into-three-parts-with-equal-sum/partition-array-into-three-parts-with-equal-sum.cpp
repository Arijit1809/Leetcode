class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%3!=0) return false;
        int val = sum/3;
        int count =0;
        sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==val){
                count++;
                sum=0;
            }
            if(count==3) break;
        }
        return count==3?true:false;
    }
};