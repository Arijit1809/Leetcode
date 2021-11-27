class Solution {
public:
    string customSortString(string S, string T) {
        int size=S.size();
        unordered_map<char, int>mp;
        for(auto c: T) mp[c]++;
        string str="";
        for(char c: S){
            if(mp.find(c) != mp.end()){
                str+=string(mp[c], c);
                mp.erase(c);
            }
        }
        for(auto m:mp){
            str+=string(m.second, m.first);
        }
        return str;
    }
};