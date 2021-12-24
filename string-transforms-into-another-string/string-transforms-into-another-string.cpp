class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        
        unordered_map<char, char> conversionMappings;
        unordered_set<char> uniqueCharactersInStr2;
        
        // Make sure that no character in str1 is mapped to multiple characters in str2.
        for (int i = 0; i < str1.size(); i++) {
            if (conversionMappings.find(str1[i]) == conversionMappings.end()) {
                conversionMappings[str1[i]] = str2[i];
                uniqueCharactersInStr2.insert(str2[i]);
            } else if (conversionMappings[str1[i]] != str2[i]) {
                // this letter maps to 2 different characters, so str1 cannot transform into str2.
                return false;
            }
        }
        
        // No character in str1 maps to 2 or more different characters in str2 and there
        // is at least one temporary character that can be used to break any loops.
        if (uniqueCharactersInStr2.size() < 26) {
            return true;
        }
        
        // The conversion mapping forms one or more cycles and there are no temporary 
        // characters that we can use to break the loops, so str1 cannot transform into str2.
        return false;
    }
};