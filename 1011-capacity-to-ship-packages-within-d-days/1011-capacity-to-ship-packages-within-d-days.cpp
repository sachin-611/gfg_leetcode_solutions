class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); // minimum possible weight capacity
        int right = accumulate(weights.begin(), weights.end(), 0); // maximum possible weight capacity
        while (left < right) {
            int mid = left + (right - left) / 2; // current weight capacity to check
            int cur = 0; // current weight on the ship
            int need = 1; // number of ships needed to transport all weights
            for (int w : weights) {
                if (cur + w > mid) {
                    cur = 0;
                    need++;
                }
                cur += w;
            }
            if (need <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};