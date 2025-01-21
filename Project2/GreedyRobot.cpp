#include <iostream>
#include <cstdlib>
#include "Robot.h"
#include "Point.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Usage: " << argv[0] << " max_distance robot_x robot_y treasure_x treasure_y" << endl;
        return 1;
    }

    int maxDistance = atoi(argv[1]);
    int robotX = atoi(argv[2]);
    int robotY = atoi(argv[3]);
    int treasureX = atoi(argv[4]);
    int treasureY = atoi(argv[5]);

    if(robotX == treasureX && robotY == treasureY) {
        cout << "You are already at the treasure!!!" << endl;
        return 0;
    } else {
        // Create the start and end points
        Point startPoint(robotX, robotY);
        Point endPoint(treasureX, treasureY);

        // Create the Robot instance
        Robot robot(startPoint, endPoint, maxDistance);

        // Output the paths and number of paths
        cout << robot;
    }

    return 0;
}