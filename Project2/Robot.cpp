#include "Robot.h"
#include <vector>

vector<string> Robot::allRoutes;

Robot::Robot(Point startP, Point endP, int maxDistance) : startPoint(startP), endPoint(endP), max_steps_(maxDistance), num_paths_(0) {
     num_paths_ = traverse(startPoint, "", 0, 0, 0, 0);

}

int Robot::traverse(Point location, string pathStr, int consecutiveN, int consecutiveS, int consecutiveE, int consecutiveW) {
     // Base case: if current location is the target
     if (location.getX() == endPoint.getX() && location.getY() == endPoint.getY()) {
        allRoutes.push_back(pathStr);
        return 1;
     }

     int pathsToTreasure = 0; // Track the number of valid paths from this point

     // Move North if not exceeding max consecutive moves
     if ((endPoint.getY() > location.getY()) && (consecutiveN < max_steps_)) {
        pathsToTreasure += traverse(Point(location.getX(), location.getY() + 1), pathStr + "N", consecutiveN + 1, 0, 0, 0);
     }

     // Move South if not exceeding max consecutive moves
     if ((endPoint.getY() < location.getY()) && (consecutiveS < max_steps_)) {
        pathsToTreasure += traverse(Point(location.getX(), location.getY() - 1), pathStr + "S", 0, consecutiveS + 1, 0, 0);
     }

     // Move East if not exceeding max consecutive moves
     if ((endPoint.getX() > location.getX()) && (consecutiveE < max_steps_)) {
        pathsToTreasure += traverse(Point(location.getX() + 1, location.getY()), pathStr + "E", 0, 0, consecutiveE + 1, 0);
     }

     // Move West if not exceeding max consecutive moves
     if (endPoint.getX() < location.getX() && consecutiveW < max_steps_) {
        pathsToTreasure += traverse(Point(location.getX() - 1, location.getY()), pathStr + "W", 0, 0, 0, consecutiveW + 1);
     }

     return pathsToTreasure; // Return the total paths found from this point
}

// Output the paths found and the total number of paths
ostream& operator<<(ostream& stream, Robot& robot) {
     if (robot.num_paths_ == 0) {
        stream << "I cannot reach the treasure :(" << endl;
     } else {
        for (const string& route : Robot::allRoutes) {
            stream << route << endl;
        }
        stream << "Number of paths to treasure: " << robot.num_paths_ << endl;
     }
     return stream;
}