class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=cp.size();
        int sum=0;
        for(int i=n-k;i<n;i++){
            sum+=cp[i];
        }
        int ans=sum;
        for(int i=0;i<k;i++){
            sum=sum-cp[n-k+i];
            sum=sum+cp[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};