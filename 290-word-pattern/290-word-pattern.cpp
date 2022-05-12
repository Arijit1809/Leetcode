class Solution {
public:
    bool wordPattern(string pattern, string s) {
        bool isFollow = true;
        unordered_map<char, string> wordMatrix;
        unordered_map<string, char> inverseWordMatrix;
        int stringIndex = 0;
        for(int i = 0;i < pattern.length(); i++){
            string toMatch = "";
            if(stringIndex>s.length()-1){
                isFollow = false;
                break;
            }
            while(s[stringIndex]!=' ' && stringIndex<s.length()){
                toMatch+=s[stringIndex];
                stringIndex++;
            }
            stringIndex++;
            cout<<pattern[i]<<" "<<toMatch<<endl;
            
            //for the letter to word matching
            if(wordMatrix.count(pattern[i])==0){
                wordMatrix[pattern[i]] = toMatch;
            }else{
                if(wordMatrix[pattern[i]]!=toMatch) isFollow = false;
            }
            
            //for the word to letter matching
            if(inverseWordMatrix.count(toMatch)==0){
                inverseWordMatrix[toMatch] = pattern[i];
            }else{
                if(inverseWordMatrix[toMatch]!=pattern[i]) isFollow = false;
            }
        }
        if(stringIndex<s.length()-1) isFollow = false;
        return isFollow;
    }
};