class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
    int Xn = max(x1, min(xc, x2));
    int Yn = max(y1, min(yc, y2));
     
    // Find the distance between the 
    // nearest point and the center 
    // of the circle
    // Distance between 2 points, 
    // (x1, y1) & (x2, y2) in 
    // 2D Euclidean space is
    // ((x1-x2)**2 + (y1-y2)**2)**0.5
    int Dx = Xn - xc;
    int Dy = Yn - yc;
    return (Dx * Dx + Dy * Dy) <= r * r;
    }
};