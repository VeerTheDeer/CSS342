// #ifndef TIME_SPAN_H_
// #define TIME_SPAN_H_
// #include <iostream>
// using namespace std;

// template <class T>

// class TimeSpan {
//     private:
//         int hours_;
//         int minutes_;
//         int seconds_;
//     public:
//         //Constructors
//         TimeSpan();
//         TimeSpan(T sec);
//         TimeSpan(T min, T sec);
//         TimeSpan(T hr, T min, T sec);
//         //Getters
//         int hours() const;
//         int minutes() const;
//         int seconds() const;
//         //Setter
//         void set_time(int hours, int minutes, int seconds);
//         //Overloaded Operators
//         // NEED +, -, Negative, +=, -=, ==, !=
//         TimeSpan operator+(const TimeSpan time) const;
//         TimeSpan operator-(const TimeSpan time) const;
//         TimeSpan operator-();
//         void operator+=(const TimeSpan time);
//         void operator-=(const TimeSpan time);
//         bool operator==(const TimeSpan time) const;
//         bool operator!=(const TimeSpan time) const;
//         bool operator<(const TimeSpan time) const;
//         bool operator<=(const TimeSpan time) const;
//         bool operator>(const TimeSpan time) const;
//         bool operator>=(const TimeSpan time) const;


//         friend ostream& operator<<(ostream& stream, const TimeSpan& time);
//         friend istream& operator>>(istream& stream, const TimeSpan& time);
// };

// #include "time_span.cpp"
// #endif

#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;

class TimeSpan {
    private:
        int hours_;
        int minutes_;
        int seconds_;
    public:
        //Constructors
        TimeSpan();
        TimeSpan(double sec);
        TimeSpan(double min, double sec);
        TimeSpan(double hr, double min, double sec);
        //Getters
        int hours() const;
        int minutes() const;
        int seconds() const;
        //Setter
        void set_time(int hours, int minutes, int seconds);
        //Overloaded Operators
        // NEED +, -, Negative, +=, -=, ==, !=
        TimeSpan operator+(const TimeSpan time) const;
        TimeSpan operator-(const TimeSpan time) const;
        TimeSpan operator-();
        void operator+=(const TimeSpan time);
        void operator-=(const TimeSpan time);
        bool operator==(const TimeSpan time) const;
        bool operator!=(const TimeSpan time) const;
        bool operator<(const TimeSpan time) const;
        bool operator<=(const TimeSpan time) const;
        bool operator>(const TimeSpan time) const;
        bool operator>=(const TimeSpan time) const;


        friend ostream& operator<<(ostream& stream, const TimeSpan& time);
        friend istream& operator>>(istream& stream, const TimeSpan& time);
};

#include "time_span.cpp"
#endif