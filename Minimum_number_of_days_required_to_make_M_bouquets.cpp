#include <vector>
#include <algorithm>

class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        // Use long long to prevent overflow
        if (static_cast<long long>(m) * k > bloomDay.size()) {
            return -1;
        }

        // Initialize the range for binary search
        int low = *std::min_element(bloomDay.begin(), bloomDay.end());
        int high = *std::max_element(bloomDay.begin(), bloomDay.end());

        // Perform binary search
        while (low < high) {
            int mid = low + (high - low) / 2;  // Calculate the middle point
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;  // Try for fewer days
            } else {
                low = mid + 1;  // Try for more days
            }
        }

        return low;  // The minimum day required to make m bouquets
    }

private:
    bool canMakeBouquets(const std::vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;  // Number of bouquets we can make
        int flowers = 0;  // Number of consecutive flowers that have bloomed

        // Iterate through each flower in the bloomDay array
        for (int bloom : bloomDay) {
            if (bloom <= day) {  // If the flower has bloomed by the given day
                flowers++;  // Count this flower
                if (flowers == k) {  // If we have enough flowers for a bouquet
                    bouquets++;  // Make a bouquet
                    flowers = 0;  // Reset the flower count for the next bouquet
                }
            } else {
                flowers = 0;  // Reset the flower count if the flower hasn't bloomed
            }
        }

        return bouquets >= m;  // Return true if we can make enough bouquets
    }
};
