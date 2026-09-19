class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Closest point in the rectangle to the circle's center
        int nx = max(x1, min(xCenter, x2));
        int ny = max(y1, min(yCenter, y2));

        long long dx = xCenter - nx;
        long long dy = yCenter - ny;

        return dx * dx + dy * dy <= (long long)radius * radius;
    }
};