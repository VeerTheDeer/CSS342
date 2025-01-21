#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
#include <string>
#include <vector>
#include "Point.h"
using namespace std;

class Robot {
public:
    // Constructor
    Robot(Point startP, Point endP, int maxDistance);

    // Recursively find paths
    int traverse(Point current, string path, int consecutiveN, int consecutiveS, int consecutiveE, int consecutiveW);

    // Output operator
    friend ostream& operator<<(ostream& stream, Robot& robot);

private:
    Point startPoint;
    Point endPoint;
    int max_steps_;   // Maximum allowed steps in one direction
    int num_paths_;   // Total number of unique paths
    static vector<string> allRoutes; // Stores all valid paths
};

#endif // ROBOT_H_