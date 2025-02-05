class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> candies(ratings.size(), 1);

        // right pass
        for(int i=1; i<ratings.size(); ++i){
            if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        }
        // left pass
        for (int i=ratings.size()-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1]+1);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};