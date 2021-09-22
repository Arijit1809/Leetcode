class Solution {
public:
    int numSplits(string s) {
        
        int n = s.length();
        vector<int> left(n);
        vector<int> right(n);
        set<char> se;
        int ans =0;
        for(int i =0;i<n-1;i++){
            se.insert(s[i]);
            left[i] = se.size();
        }
        se.clear();
        for(int i =n-1;i>0;i--){
            se.insert(s[i]);
            right[i] = se.size();
        }
        
        for(int i =0;i<n-1;i++){
            if(left[i]==right[i+1]) ans++;
        } 
        
        return ans;
    }
};