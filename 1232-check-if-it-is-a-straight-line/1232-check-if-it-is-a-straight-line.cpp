class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(),coordinates.end());
        int dely=coordinates[1][1]-coordinates[0][1];
        int delx=coordinates[1][0]-coordinates[0][0];
        for(int i=1;i<coordinates.size();i++){
            if((coordinates[i][1]-coordinates[i-1][1])*delx!=(coordinates[i][0]-coordinates[i-1][0])*dely)
                return false;
        }
        return true;
    }
};