class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA=0,countB=0,aliceTurns=0,bobTurns=0;
        for(int i = 0;i<colors.length();i++){
            
            
            while(colors[i]=='A'){
                i++;
                countA++;
            }
            if(countA>=3){
                aliceTurns+=countA-2;
            }
            countA=0;
            
            
            while(colors[i]=='B'){
                i++;
                countB++;
            }
            if(countB>=3){
                bobTurns+=countB-2;
            }
            countB=0;
            
            
            i--;
        }
        cout<<"alice ki baari : "<<aliceTurns<<" , bob ki baari : "<<bobTurns<<endl;
        if(aliceTurns>bobTurns) return true;
        else return false;
    }
};