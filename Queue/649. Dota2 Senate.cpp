// Bruteforce

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int i = 0;
        int aliveR = 0, aliveD = 0;

        // initial count
        for(char c : senate){
            if(c == 'R') aliveR++;
            else aliveD++;
        }
        map<int,bool> dead;  // <index, true>
        while(aliveR > 0 && aliveD > 0){
            // check if the senator is Ban or not
            if(dead.find(i) == dead.end()){
                char senator = senate[i]; // current senator
                // current senator is not Bannedd so he can Ban the opponent just next to him
                int j = (i+1) % n;
                 // find next alive opponent
                while(j != i){
                    if(dead.find(j) == dead.end() && senate[j] != senator){
                        break;
                    }
                    j = (j + 1) % n;
                }

                // it is opponent
                if(j != i){
                    dead[j] = true;
                    if(senate[j] == 'R') aliveR--;
                    else aliveD--;
                }
            }
            i = (i+1) % n;
        }
        return aliveR > 0 ? "Radiant" : "Dire";
    }
};