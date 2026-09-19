class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi=clamp(xCenter,x1,x2);
        int yi=clamp(yCenter,y1,y2);
        return sqrt((xi-xCenter)*(xi-xCenter)+(yi-yCenter)*(yi-yCenter))<=radius;
    }
};