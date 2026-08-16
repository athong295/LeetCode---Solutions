class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0=0, c1=0, c2=0;
        for(int stone : stones)
        {
            if(stone % 3 == 0) c0++;
            else if(stone % 3 == 1) c1++;
            else c2++;
        }
        if(c0 % 2 ==0)
        {
            return c1 >= 1 && c2 >= 1;
        }
        else return c1 - c2 > 2 || c2 - c1 > 2;
    }
};