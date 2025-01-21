#include "Point.h"

Point::Point() : x_(0), y_(0) {

}
Point::Point(int x, int y) : x_(x), y_(y) {
    
}

int Point::getX() const {
    return x_;
}

int Point::getY() const {
    return y_;
}