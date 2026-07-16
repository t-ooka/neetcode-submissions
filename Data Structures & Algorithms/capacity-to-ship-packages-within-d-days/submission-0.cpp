class Solution {
private:
    bool canShip(const vector<int>& weights, int availableDays, int capacity) {
        int requiredDays = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                ++requiredDays;

                if (requiredDays > availableDays) {
                    return false;
                }

                currentLoad = weight;
            } else {
                currentLoad += weight;
            }
        }

        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minimumCapacity = *max_element(weights.begin(), weights.end());

        int maximumCapacity = accumulate(weights.begin(), weights.end(), 0);

        while (minimumCapacity < maximumCapacity) {
            int capacity =
                minimumCapacity + (maximumCapacity - minimumCapacity) / 2;

            if (canShip(weights, days, capacity)) {
                maximumCapacity = capacity;
            } else {
                minimumCapacity = capacity + 1;
            }
        }

        return minimumCapacity;
    }
};