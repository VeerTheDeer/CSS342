#ifndef POINT_H_
#define POINT_H_
#include <iostream>
using namespace std;

class Point {
    public:
        //Constructors
        Point();
        Point(int x, int y);

        //Getters
        int getX() const;
        int getY() const;

    private:
        int x_;
        int y_;
};

#endif // POINT_H_