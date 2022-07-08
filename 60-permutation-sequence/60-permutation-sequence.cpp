class Solution {
public:
   int fact(int n){
        int res = 1, i;
        for (i = 2; i <= n; i++)
            res *= i;
        return res;
    }
    
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int i = 0; i<n;i++){
            nums[i] = i+1;
        }
        return rec(n, k, nums);
    }
    
    string rec(int n, int k, vector<int> nums){
        if(n==1) return to_string(nums[0]);
        
        int curr_digit = 0; //ye index hai uss number ka jo iss spot pe aayega
        
        int factorialNMinus1 = fact(n-1); //ye maine agle n-1 wale number ke total perms possible nikaal liye
        
        if(k % factorialNMinus1 == 0){
            curr_digit = k/factorialNMinus1-1; //agar suppose k is 6 and n-1 ! is 6 then index should be 0, ki mujhe pehla possible digit chahiye
        }else{ //varna if k is 7 and n-1 ! is 6 then 1 wala dedo
            curr_digit = k/factorialNMinus1;
        }
        
        int new_k = 0; //ab baki bache digits ke jo number of positions possible hai wo dekho, jo agle me kaam aayenge

        new_k = k - curr_digit*factorialNMinus1;
            
        vector<int> remaining_nums; //ye bache huye digits hai jo kaam nahi aaye
        
        for(int i = 0; i< nums.size();i++){ //mai ab sare digits add kar dunga
            if(i==curr_digit) continue; //agar wo number ka index match hua, to usse nahi daalna, add the remaining
            else remaining_nums.push_back(nums[i]);
        }
        
        return to_string(nums[curr_digit]) + rec(n-1,new_k,remaining_nums); // ab suppose currPerm is 2 and then aage recursion se milega 134
    }
};