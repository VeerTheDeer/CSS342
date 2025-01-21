#ifndef CHILD_H_
#define CHILD_H_
#include <string>
using namespace std;

class Child {
    private:
        string firstName_, lastName_;
        int age_;
    public:
        // Constructor & Destructor
        Child();
        Child(string firstName, string lastName, int age);
        Child(const Child& child);  // Use const reference for copy constructor
        ~Child();

        // Operator Overloads
        bool operator<(const Child& child) const;
        bool operator>(const Child& child) const;
        bool operator==(const Child& child) const;
        bool operator!=(const Child& child) const;
        Child& operator=(const Child& child);  // Return *this for assignment operator

        friend ostream& operator<<(ostream& ostream, const Child& child);
        friend istream& operator>>(istream& istream, Child& child);
};

// Constructor Definitions
Child::Child() : firstName_(""), lastName_(""), age_(0) {

}

Child::Child(const Child& child) : firstName_(child.firstName_), lastName_(child.lastName_), age_(child.age_) {

}

Child::Child(string firstName, string lastName, int age) : firstName_(firstName), lastName_(lastName), age_(age) {

}

Child::~Child() {

}

// Operator Overload Definitions
bool Child::operator<(const Child& child) const {
    if (lastName_ < child.lastName_) {
        return true;

    } else if (lastName_ == child.lastName_ && firstName_ < child.firstName_) {
        return true;

    } else if (lastName_ == child.lastName_ && firstName_ == child.firstName_ && age_ < child.age_) {
        return true;

    }
    return false;
}

bool Child::operator>(const Child& child) const {
    if (lastName_ > child.lastName_) {
        return true;

    } else if (lastName_ == child.lastName_ && firstName_ > child.firstName_) {
        return true;

    } else if (lastName_ == child.lastName_ && firstName_ == child.firstName_ && age_ > child.age_) {
        return true;

    }
    return false;
}

bool Child::operator==(const Child& child) const {
    return (lastName_ == child.lastName_) && (firstName_ == child.firstName_) && (age_ == child.age_);
}

bool Child::operator!=(const Child& child) const {
    return !(*this == child);
}

Child& Child::operator=(const Child& child) {
    if (this != &child) {
        firstName_ = child.firstName_;
        lastName_ = child.lastName_;
        age_ = child.age_;
    }
    return *this;
}

istream& operator>>(istream& istream, Child& child) {
    istream >> child.firstName_ >> child.lastName_ >> child.age_;
    return istream;
}

ostream& operator<<(ostream& ostream, const Child& child) {
    ostream << child.firstName_ << child.lastName_ << child.age_;
    return ostream;
}

#endif