class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
      int n= nums.size() ;
      int c =0 ;
      
      for(int i=0 ; i< n ; i++){
        for(int j=i+1 ; j< n ;j++){
          for(int k=j+1 ; k < n ; k++) {
            for(int d =k+1 ; d<n ; d++){
            if(nums[i] + nums[j] + nums[k] == nums[d]){
              c++ ;
            }
                
              }
          }
        }
      }
      
  
      
      return c ;
        
    }
};