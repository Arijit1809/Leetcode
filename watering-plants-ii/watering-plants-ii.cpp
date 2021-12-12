class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0,r=plants.size()-1;
        int timesRefilled=0;
        int currCapacityA=capacityA,currCapacityB=capacityB;
        while(l<r){
            if(currCapacityA<plants[l]){
                currCapacityA=capacityA;
                timesRefilled++;
            }
            currCapacityA-=plants[l];
            l++;
            if(currCapacityB<plants[r]){
                currCapacityB=capacityB;
                timesRefilled++;
            }
            currCapacityB-=plants[r];
            r--; 
        }
        if(l==r){
            if(currCapacityA>currCapacityB || currCapacityA==currCapacityB){
                    if(currCapacityA<plants[l]){
                    timesRefilled++;
                }
            }else{
                 if(currCapacityB<plants[r]){
                    timesRefilled++;
                }
            }
        }
        return timesRefilled;
    }
};