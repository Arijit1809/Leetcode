class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0,right = 0, n = fruits.size();
        int result=0;
        unordered_map<int,int> types;
        for(right;right<n;right++){
            types[fruits[right]]++;
            // cout<<"leftFruit= "<<fruits[left]<<" rightFruit= "<<fruits[right]<<" ,size = ";
            // cout<<types.size()<<" ,left: "<<left<<" ,right: "<<right<<endl;
            // cout<<"----------------------------------"<<endl;
            // for(auto dict:types){
            //     cout<<dict.first<<" : "<<dict.second<<", ";
            // }cout<<endl;
            // cout<<"----------------------------------"<<endl;
            if(types.size()>2){
                // cout<<"Size is more so we decrease "<< fruits[left];
                types[fruits[left]]--; 
                // cout<<" leftFruit left "<<types[fruits[left]]<<" ";
                if(types[fruits[left]]==0) types.erase(fruits[left]);
                    // cout<<"###### Erased -> "<<fruits[left]<<" #####"<<endl;
                left++;
            }
        }
        // cout<<"----------------------------------"<<endl;
        // cout<<"right: "<<right<<", left: "<<left<<endl; 
        return right-left;
    }
};