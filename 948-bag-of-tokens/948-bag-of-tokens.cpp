class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int i=0,j=n-1;
        int score=0;
        sort(tokens.begin(),tokens.end());
        int ans=0;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                i++;
                score+=1;
            }
            else if(score>=1)
            {
                power+=tokens[j];
                j--;
                score-=1;
            }
            else
            {
                break;
            }
            ans=max(ans,score);
        }
        return ans;
    }
};