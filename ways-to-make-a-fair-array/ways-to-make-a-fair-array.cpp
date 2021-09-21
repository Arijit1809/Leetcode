class Solution {
public:
    int waysToMakeFair(vector<int>& a) 
    {
        const int n = a.size();
        
        int prefixEven = 0, prefixOdd = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            if(i%2 == 0) prefixEven += a[i];
            else prefixOdd += a[i];
        }
        
        int suffixEven = 0, suffixOdd = 0;
        int count = 0;
        for(int i = n-1 ; i >= 0 ; --i)
        {
            if(i%2 == 0) prefixEven -= a[i];
            else prefixOdd -= a[i];
            
            if((prefixEven + suffixEven) == (prefixOdd + suffixOdd)) ++count;
            
            if(i%2 == 0) suffixOdd += a[i];
            else suffixEven += a[i];
        }
        return count;
    }
};