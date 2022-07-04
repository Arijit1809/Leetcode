class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string license_without_dashes = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='-') continue;
            else license_without_dashes+=toupper(s[i]);
        }
        int group_one_len = license_without_dashes.length()%k;
        string formatted_license = license_without_dashes.substr(0,group_one_len);
        if(group_one_len != 0 && group_one_len!=license_without_dashes.length()) formatted_license+="-";
        for(int i = group_one_len;i<license_without_dashes.length(); i+=k){
            
            formatted_license+=license_without_dashes.substr(i,k);
            if(i!=(license_without_dashes.length()-k)) formatted_license+="-";
        }
        return formatted_license;
    }
};