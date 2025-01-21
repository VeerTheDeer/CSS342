//TEMPLATIZED VERSION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// #ifndef TIME_SPAN_CPP_
// #define TIME_SPAN_CPP_
// #include <iostream>
// #include "time_span.h"
// using namespace std;

// //CONSTRUCTOR IMPLEMENTATION
// template <class T>
// TimeSpan<T>::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {

// }

// template <class T>
// TimeSpan<T>::TimeSpan(T sec) : hours_(0), minutes_(0), seconds_(sec) {
//     if(sec > 60 || sec < -60) {
//         int tempHr
//         int tempMin;
//         int tempSec = static_cast<int>(sec);
//         tempMin = tempSec / 60;
//         tempSec %= 60
//         tempHr = tempMin / 60;
//         tempMin %= 60;
//         seconds_ = tempSec;
//         minutes_ tempMin;
//         hours_ = tempHr;
//     }
// }

// template <class T>
// TimeSpan<T>::TimeSpan(T min, T sec) : hours_(0), minutes_(min), seconds_(sec) {
//     if(sec > 60 || sec < -60 || min > 60 || min < -60) {
//         int tempHr
//         int tempMin;
//         int tempSec = static_cast<int>(sec) + static_cast<int>(min * 60);
//         tempMin = tempSec / 60
//         tempSec %= 60
//         tempHr = tempMin / 60;
//         tempMin %= 60;
//         seconds_ = tempSec;
//         minutes_ tempMin;
//         hours_ = tempHr;
//     }
// }

// template <class T>
// TimeSpan<T>::TimeSpan(T hr, T min, T sec) : hours_(hr), minutes_(min), seconds_(sec) {
//     if(sec > 60 || sec < -60 || min > 60 || min < -60) {
//         int tempHr
//         int tempMin;
//         int tempSec = static_cast<int>(sec) + static_cast<int>(min * 60) + static_cast<int>(hr * 60 * 60);
//         tempMin = tempSec / 60
//         tempSec %= 60
//         tempHr = tempMin / 60;
//         tempMin %= 60;
//         seconds_ = tempSec;
//         minutes_ tempMin;
//         hours_ = tempHr;
//     }
// }

// //GETTER IMPLEMENTATION
// template <class T>
// int TimeSpan<T>::hours() const {
//     return hours_;
// }

// template <class T>
// int TimeSpan<T>::minutes() const {
//     return minutes_;
// }

// template <class T>
// int TimeSpan<T>::seconds() const {
//     return seconds_;
// }

// //SETTER IMPLEMENTATION
// template <class T>
// void TimeSpan<T>::set_time(int hours, int minutes, int seconds) {
//     int tempHr
//     int tempMin;
//     int tempSec = (seconds) + (minutes * 60) + (hours * 60 * 60);
//     tempMin = tempSec / 60
//     tempSec %= 60
//     tempHr = tempMin / 60;
//     tempMin %= 60;
//     seconds_ = tempSec;
//     minutes_ tempMin;
//     hours_ = tempHr;
// }

// //OVERLOADED METHODS
// template <class T>
// TimeSpan<T> TimeSpan<T>::operator+(const TimeSpan<T> time) const {
//     return TimeSpan<int>((hour_ + time.hours()), (minutes_ + time.minutes()), (seconds_ + time.seconds()));
// }

// template <class T>
// TimeSpan<T> TimeSpan<T>::operator-(const TimeSpan<T> time) const {
//     return TimeSpan<int>((hour_ - time.hours()), (minutes_ - time.minutes()), (seconds_ - time.seconds()));
// }

// template <class T>
// TimeSpan<T> TimeSpan<T>::operator-() {

// }

// template <class T>
// void TimeSpan<T>::operator+=(const TimeSpan<T> time) {
//     set_time((hour_ + time.hours()), (minutes_ + time.minutes()), (seconds_ + time.seconds()));
// }

// template <class T>
// void TimeSpan<T>::operator-=(const TimeSpan<T> time) {
//     set_time((hour_ - time.hours()), (minutes_ - time.minutes()), (seconds_ - time.seconds()))
// }

// template <class T>
// bool TimeSpan<T>::operator==(const TimeSpan time) const {
//     return ((hour_ == time.hours()) && (minutes_ == time.minutes()) && (seconds_ == time.seconds()));
// }

// template <class T>
// bool TimeSpan<T>::operator!=(const TimeSpan time) const {
//     return ((hour_ != time.hours()) || (minutes_ != time.minutes()) || (seconds_ != time.seconds()));
// }

// template <class T>
// bool TimeSpan<T>::operator<(const TimeSpan time) const {
//     return ((hour_ < time.hours()) && (minutes_ < time.minutes()) && (seconds_ < time.seconds()));
// }

// template <class T>
// bool TimeSpan<T>::operator<=(const TimeSpan time) const {
//     return ((hour_ <= time.hours()) && (minutes_ <= time.minutes()) && (seconds_ <= time.seconds()));
// }

// template <class T>
// bool TimeSpan<T>::operator>(const TimeSpan time) const {
//     return ((hour_ > time.hours()) && (minutes_ > time.minutes()) && (seconds_ > time.seconds()));
// }

// template <class T>
// bool TimeSpan<T>::operator>=(const TimeSpan time) const {
//     return ((hour_ >= time.hours()) && (minutes_ >= time.minutes()) && (seconds_ >= time.seconds()));
// }

// //IO IMPLEMENTATION
// //FOLLOWED THE "Hours: -,Minutes: -,Seconds: -" format
// template <class T>
// ostream& operator<<(ostream& ostream, const TimeSpan<T>& time) {
//     ostream << "Hours: " << time.hours() << ",Minutes: " << time.minutes() << ",Seconds: " << time.seconds() << endl;
//     return ostream;
// }

// template <class T>
// istream& operator>>(istream& istream, TimeSpan<T>& time) {
//     cin >> time.hours_;
//     cin >> time.min_;
//     cin >> time.sec_;
//     return istream;
// }

// #endif

//UNTEMPLATIZED VERSION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// #ifndef TIME_SPAN_CPP_
// #define TIME_SPAN_CPP_
// #include <iostream>
// #include "time_span.h"
// using namespace std;

// //CONSTRUCTOR IMPLEMENTATION
// TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {

// }

// TimeSpan::TimeSpan(double sec) : hours_(0), minutes_(0), seconds_(sec) {
//     if(sec > 60 || sec < -60) {
//         int tempHr;
//         int tempMin;
//         int tempSec = static_cast<int>(sec);
//         tempMin = tempSec / 60;
//         tempSec %= 60;
//         tempHr = tempMin / 60;
//         tempMin %= 60;
//         seconds_ = tempSec;
//         minutes_ = tempMin;
//         hours_ = tempHr;
//     }
// }

// TimeSpan::TimeSpan(double min, double sec) : hours_(0), minutes_(min), seconds_(sec) {
//     if(sec > 60 || sec < -60 || min > 60 || min < -60) {
//         int tempHr;
//         int tempMin;
//         int tempSec = static_cast<int>(sec) + static_cast<int>(min * 60);
//         tempMin = tempSec / 60;
//         tempSec %= 60;
//         tempHr = tempMin / 60;
//         tempMin %= 60;
//         seconds_ = tempSec;
//         minutes_ = tempMin;
//         hours_ = tempHr;
//     }
// }

// TimeSpan::TimeSpan(double hr, double min, double sec) : hours_(hr), minutes_(min), seconds_(sec) {
//     if(sec > 60 || sec < -60 || min > 60 || min < -60) {
//         int tempHr;
//         int tempMin;
//         int tempSec = static_cast<int>(sec) + static_cast<int>(min * 60) + static_cast<int>(hr * 60 * 60);
//         tempMin = tempSec / 60;
//         tempSec %= 60;
//         tempHr = tempMin / 60;
//         tempMin %= 60;
//         seconds_ = tempSec;
//         minutes_ = tempMin;
//         hours_ = tempHr;
//     }
// }

// //GETTER IMPLEMENTATION
// int TimeSpan::hours() const {
//     return hours_;
// }

// int TimeSpan::minutes() const {
//     return minutes_;
// }

// int TimeSpan::seconds() const {
//     return seconds_;
// }

// //SETTER IMPLEMENTATION
// void TimeSpan::set_time(int hours, int minutes, int seconds) {
//     int tempHr;
//     int tempMin;
//     int tempSec = (seconds) + (minutes * 60) + (hours * 60 * 60);
//     tempMin = tempSec / 60;
//     tempSec %= 60;
//     tempHr = tempMin / 60;
//     tempMin %= 60;
//     seconds_ = tempSec;
//     minutes_ = tempMin;
//     hours_ = tempHr;
// }

// //OVERLOADED METHODS
// TimeSpan TimeSpan::operator+(const TimeSpan time) const {
//     return TimeSpan((hours_ + time.hours()), (minutes_ + time.minutes()), (seconds_ + time.seconds()));
// }

// TimeSpan TimeSpan::operator-(const TimeSpan time) const {
//     return TimeSpan((hours_ - time.hours()), (minutes_ - time.minutes()), (seconds_ - time.seconds()));
// }

// TimeSpan TimeSpan::operator-() {
//     this->hours_ *= -1;
//     this->minutes_ *= -1;
//     this->seconds_ *= -1;
//     return *this;
// }

// void TimeSpan::operator+=(const TimeSpan time) {
//     set_time((hours_ + time.hours()), (minutes_ + time.minutes()), (seconds_ + time.seconds()));
// }

// void TimeSpan::operator-=(const TimeSpan time) {
//     set_time((hours_ - time.hours()), (minutes_ - time.minutes()), (seconds_ - time.seconds()));
// }

// bool TimeSpan::operator==(const TimeSpan time) const {
//     return ((hours_ == time.hours()) && (minutes_ == time.minutes()) && (seconds_ == time.seconds()));
// }

// bool TimeSpan::operator!=(const TimeSpan time) const {
//     return ((hours_ != time.hours()) || (minutes_ != time.minutes()) || (seconds_ != time.seconds()));
// }

// bool TimeSpan::operator<(const TimeSpan time) const {
//     return ((hours_ < time.hours()) && (minutes_ < time.minutes()) && (seconds_ < time.seconds()));
// }

// bool TimeSpan::operator<=(const TimeSpan time) const {
//     return ((hours_ <= time.hours()) && (minutes_ <= time.minutes()) && (seconds_ <= time.seconds()));
// }

// bool TimeSpan::operator>(const TimeSpan time) const {
//     return ((hours_ > time.hours()) && (minutes_ > time.minutes()) && (seconds_ > time.seconds()));
// }

// bool TimeSpan::operator>=(const TimeSpan time) const {
//     return ((hours_ >= time.hours()) && (minutes_ >= time.minutes()) && (seconds_ >= time.seconds()));
// }

// //IO IMPLEMENTATION
// //FOLLOWED THE "Hours: -,Minutes: -,Seconds: -" format
// ostream& operator<<(ostream& ostream, const TimeSpan& time) {
//     ostream << "Hours: " << time.hours() << ",Minutes: " << time.minutes() << ",Seconds: " << time.seconds() << endl;
//     return ostream;
// }

// istream& operator>>(istream& istream, TimeSpan& time) {
//     int hours, minutes, seconds;
//     char colon1, colon2;

//     istream >> hours >> colon1 >> minutes >> colon2 >> seconds;
//     (colon1 == ':' && colon2 == ':' && !istream.fail()) ? time.set_time(hours, minutes, seconds) : istream.setstate(ios::failbit); 
//     return istream;
// }

// #endif

#ifndef TIME_SPAN_CPP_
#define TIME_SPAN_CPP_
#include <iostream>
#include <cmath>
#include "time_span.h"
using namespace std;

// CONSTRUCTOR IMPLEMENTATION
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {}

TimeSpan::TimeSpan(double sec) : hours_(0), minutes_(0), seconds_(sec) {
    int tempSec = round(sec);
    int tempMin = tempSec / 60;
    tempSec %= 60;
    int tempHr = tempMin / 60;
    tempMin %= 60;
    seconds_ = tempSec;
    minutes_ = tempMin;
    hours_ = tempHr;
}

TimeSpan::TimeSpan(double min, double sec) : hours_(0), minutes_(min), seconds_(sec) {
    double doubleSec = (sec) + (min * 60);
    int tempSec = round(doubleSec);
    int tempMin = tempSec / 60;
    tempSec %= 60;
    int tempHr = tempMin / 60;
    tempMin %= 60;
    seconds_ = tempSec;
    minutes_ = tempMin;
    hours_ = tempHr;
}

TimeSpan::TimeSpan(double hr, double min, double sec) : hours_(hr), minutes_(min), seconds_(sec) {
    double doubleSec = (sec) + (min * 60) + (hr * 3600);
    int tempSec = round(doubleSec);
    int tempMin = tempSec / 60;
    tempSec %= 60;
    int tempHr = tempMin / 60;
    tempMin %= 60;
    seconds_ = tempSec;
    minutes_ = tempMin;
    hours_ = tempHr;
}

// GETTER IMPLEMENTATION
int TimeSpan::hours() const { 
    return hours_; 
}

int TimeSpan::minutes() const { 
    return minutes_;
}

int TimeSpan::seconds() const { 
    return seconds_; 
}

// SETTER IMPLEMENTATION
void TimeSpan::set_time(int hours, int minutes, int seconds) {
    int tempSec = (seconds) + (minutes * 60) + (hours * 3600);
    int tempMin = tempSec / 60;
    tempSec %= 60;
    int tempHr = tempMin / 60;
    tempMin %= 60;
    seconds_ = tempSec;
    minutes_ = tempMin;
    hours_ = tempHr;
}

// OVERLOADED METHODS
TimeSpan TimeSpan::operator+(const TimeSpan time) const {
    return TimeSpan((hours_ + time.hours()), (minutes_ + time.minutes()), (seconds_ + time.seconds()));
}

TimeSpan TimeSpan::operator-(const TimeSpan time) const {
    return TimeSpan((hours_ - time.hours()), (minutes_ - time.minutes()), (seconds_ - time.seconds()));
}

TimeSpan TimeSpan::operator-() {
    this->hours_ *= -1;
    this->minutes_ *= -1;
    this->seconds_ *= -1;
    return *this;
}

void TimeSpan::operator+=(const TimeSpan time) {
    set_time((hours_ + time.hours()), (minutes_ + time.minutes()), (seconds_ + time.seconds()));
}

void TimeSpan::operator-=(const TimeSpan time) {
    set_time((hours_ - time.hours()), (minutes_ - time.minutes()), (seconds_ - time.seconds()));
}

bool TimeSpan::operator==(const TimeSpan time) const {
    return ((hours_ == time.hours()) && (minutes_ == time.minutes()) && (seconds_ == time.seconds()));
}

bool TimeSpan::operator!=(const TimeSpan time) const {
    return ((hours_ != time.hours()) || (minutes_ != time.minutes()) || (seconds_ != time.seconds()));
}

bool TimeSpan::operator<(const TimeSpan time) const {
    return ((hours_ < time.hours()) || (hours_ == time.hours() && minutes_ < time.minutes()) || (hours_ == time.hours() && minutes_ == time.minutes() && seconds_ < time.seconds()));
}

bool TimeSpan::operator<=(const TimeSpan time) const {
    return (*this < time || *this == time);
}

bool TimeSpan::operator>(const TimeSpan time) const {
    return !(*this <= time);
}

bool TimeSpan::operator>=(const TimeSpan time) const {
    return !(*this < time);
}

// IO IMPLEMENTATION
ostream& operator<<(ostream& ostream, const TimeSpan& time) {
    ostream << "Hours: " << time.hours() << ", Minutes: " << time.minutes() << ", Seconds: " << time.seconds();
    return ostream;
}

istream& operator>>(istream& istream, TimeSpan& time) {
    int hours, minutes, seconds;
    char colon1, colon2;
    istream >> hours >> colon1 >> minutes >> colon2 >> seconds;
    if (colon1 == ':' && colon2 == ':' && !istream.fail()) {
        time.set_time(hours, minutes, seconds);
    } else {
        istream.setstate(ios::failbit);
    }
    return istream;
}

#endif