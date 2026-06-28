class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        
        vector<vector<int>> merged;
        
        int currentStart = occupiedIntervals[0][0];
        int currentEnd = occupiedIntervals[0][1];
        
        for (int i = 1; i < occupiedIntervals.size(); i++) {
            int nextStart = occupiedIntervals[i][0];
            int nextEnd = occupiedIntervals[i][1];
            
            if (nextStart <= currentEnd + 1) {
                currentEnd = max(currentEnd, nextEnd);
            } else {
                merged.push_back({currentStart, currentEnd});
                currentStart = nextStart;
                currentEnd = nextEnd;
            }
        }
        merged.push_back({currentStart, currentEnd});
        
        vector<vector<int>> result;
        
        for (int i = 0; i < merged.size(); i++) {
            int start = merged[i][0];
            int end = merged[i][1];
            
            int removeStart = max(start, freeStart);
            int removeEnd = min(end, freeEnd);
            
            if (removeStart > removeEnd) {
                result.push_back({start, end});
            } else {
                if (start < removeStart) {
                    result.push_back({start, removeStart - 1});
                }
                if (end > removeEnd) {
                    result.push_back({removeEnd + 1, end});
                }
            }
        }
        
        return result;
    }
};