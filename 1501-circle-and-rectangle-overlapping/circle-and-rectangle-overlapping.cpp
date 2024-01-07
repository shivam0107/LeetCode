class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int  nearest_x = max(x1 , min(xCenter , x2));
        int nearest_y = max(y1 , min(yCenter , y2));

       int dist_x = nearest_x - xCenter;
        int dist_y = nearest_y - yCenter;

        return pow(dist_x , 2) + pow(dist_y , 2) <= pow(radius , 2);


    }
};