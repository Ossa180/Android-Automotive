class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int altitude = 0;
        int sum = 0;
        int maxi = 0;

        for(int val : gain)
        {
            sum = sum + val;
            maxi = max(maxi,sum);
        }
        return maxi;        
    }
};
