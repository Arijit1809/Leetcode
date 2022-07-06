class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribution(k,0);
        return rec(cookies,distribution,0,k);
    }
    
    int rec(vector<int>& cookies, vector<int>& distribution, int index, int k){
        if(index == cookies.size()){
            int max_cookies = *max_element(distribution.begin(),distribution.end());
            return max_cookies;
        }
        int num_of_cookies = cookies[index];
        int min_unfairness = INT_MAX;
        for(int i = 0; i<k;i++){
            distribution[i]+=num_of_cookies;
            min_unfairness = min(min_unfairness, rec(cookies,distribution,index+1,k));
            distribution[i]-=num_of_cookies;
        }
        return min_unfairness;
    }
};