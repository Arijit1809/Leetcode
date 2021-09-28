class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
	unordered_map<string, string> mp; 
	for(auto& pair : knowledge) mp[pair[0]] = pair[1];
	int n = size(s); string ans = "";
	for(int i = 0; i < n; i++)
		if(s[i] == '('){                
			string key = "";			
			while(++i < n && s[i] != ')') key += s[i];   
			ans += (mp.count(key) ? mp[key] : "?");    
		}
		else ans += s[i];  
	
	return ans;
}
};