#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        
        int size = flowerbed.size();
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                // Check if left and right neighbors are empty (or out of bounds)
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // Plant a flower
                    n--;
                    if (n <= 0) return true; // Early exit
                }
            }
        }
        
        return n <= 0;
    }
};