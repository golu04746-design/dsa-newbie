#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int cnt = 0;
        
        while (left <= right) {
            // Can the lightest person share the boat with the heaviest?
            if (people[left] + people[right] <= limit) {
                left++; // Lightest person gets on board
            }
            // Heaviest person ALWAYS gets on this boat
            right--;
            cnt++;  // One boat dispatched
        }
        
        return cnt;
    }
};