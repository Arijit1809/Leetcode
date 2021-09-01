class Solution {
public:
    vector<int> dp;
    int getKth(int lo, int hi, int k) {
        // memset(dp, -1, sizeof(dp)); // initializing the array with -1
        dp.resize(1000001,-1);
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++){
            v.push_back({power(i),i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
        // return power(12);
    }
     int power(int i){
        if(dp[i] != -1) return dp[i]; // if power of ith element is already known, simply return dp[i]
        if(i == 1) return 0; // since, for 1 -> 1, steps = 0 
        int cnt = 0; // counter to count the number of steps
        if(i & 1){ // if i is odd call power(3*i+1)
            cnt = 1 + power(3*i+1);
        }else{ // if i is even call power(i/2)
            cnt = 1 + power(i/2);
        }
        return dp[i] = cnt; // store the power of ith element in dp[i], *Note: this is where memoization is done*
    }
};