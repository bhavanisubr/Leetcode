/**
 * Find the total area covered by two rectilinear rectangles in a 2D plane where each rectangle is defined by 
 * its bottom left corner and top right corner.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
       int area = ((D - B) * (C - A)) + ((H - F) * (G - E));
       if (C < E || D < F || G < A || H < B)   return area;
       return area - ((min(C, G) - max(A, E)) * (min(D, H) - max(B, F)));
    }
};