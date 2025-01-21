#include <iostream>
#include "time_span.h"
using namespace std;

bool CheckValues(TimeSpan time, int hours, int minutes, int seconds) {
    if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds() != seconds)) {
        return false;
    }
    return true;
}

bool TestZeros() {
    TimeSpan ts(0, 0, 0);
    return CheckValues(ts, 0, 0, 0);
}

bool TestFloatSeconds() {
    TimeSpan ts(127.86);
    return CheckValues(ts, 0, 2, 8);
}

bool TestNegativeMinute() {
    TimeSpan ts(8, -23, 0);
    return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour() {
    TimeSpan ts(-3, 73, 2);
    return CheckValues(ts, -1, -46, -58);
}

bool TestAdd() {
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
    return CheckValues(add_it_up, 4, 7, 5);
}

bool TestAddInPlace() {
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1))) {
        return false;
    }
    ts1 += ts2;
    if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1))) {
        return false;
    }
    return true;
}

bool TestSubtract() {
    TimeSpan ts1(5, 0, 0);
    TimeSpan ts2(2, 30, 0);
    TimeSpan result = ts1 - ts2;
    return CheckValues(result, 2, 30, 0);
}

bool TestSubtractInPlace() {
    TimeSpan ts1(10, 15, 30);
    TimeSpan ts2(2, 20, 40);
    ts1 -= ts2;
    return CheckValues(ts1, 7, 54, 50);
}

bool TestComparisonOperators() {
    TimeSpan ts1(3, 45, 20);
    TimeSpan ts2(3, 45, 20);
    TimeSpan ts3(2, 30, 0);

    if (!(ts1 == ts2)) {
        cout << "Failed: Comparison == operator" << endl;
        return false;
    }
    if (ts1 != ts2) {
        cout << "Failed: Comparison != operator" << endl;
        return false;
    }
    if (!(ts3 < ts1)) {
        cout << "Failed: Comparison < operator" << endl;
        return false;
    }
    if (!(ts3 <= ts1)) {
        cout << "Failed: Comparison <= operator" << endl;
        return false;
    }
    if (ts1 < ts3) {
        cout << "Failed: Comparison < operator" << endl;
        return false;
    }
    if (!(ts1 >= ts2)) {
        cout << "Failed: Comparison >= operator" << endl;
        return false;
    }
    return true;
}

//EVEN MORE TEST CASES

bool TestNegativeSeconds() {
    TimeSpan ts(0, 0, -75);  // -1 minute, -15 seconds
    return CheckValues(ts, 0, -1, -15);
}

bool TestZeroAddition() {
    TimeSpan ts1(5, 30, 15);
    TimeSpan ts2(0, 0, 0);
    TimeSpan result = ts1 + ts2;
    return CheckValues(result, 5, 30, 15);
}

bool TestSubtractResultNegative() {
    TimeSpan ts1(2, 0, 0);
    TimeSpan ts2(3, 0, 0);
    TimeSpan result = ts1 - ts2;
    return CheckValues(result, -1, 0, 0);
}

bool TestChainedAddition() {
    TimeSpan ts1(1, 20, 30);
    TimeSpan ts2(2, 45, 15);
    TimeSpan ts3(0, 30, 45);
    TimeSpan result = ts1 + ts2 + ts3;
    return CheckValues(result, 4, 36, 30);
}

bool TestNegateOperator() {
    TimeSpan ts(1, 30, 45);
    TimeSpan negated = -ts;
    return CheckValues(negated, -1, -30, -45);
}



int main() {
    cout << "Testing TimeSpan Class" << endl;
    if (!TestZeros()) {
        cout << "Failed: TestZeros" << endl;
    }

    if (!TestZeroAddition()) {
        cout << "Failed: TestFloatSeconds" << endl;
    }

    if (!TestNegativeMinute()) {
        cout << "Failed: TestNegativeMinute" << endl;
    }

    if (!TestNegativeHour()) {
        cout << "Failed: TestNegativeHour" << endl;
    }

    if (!TestAdd()) {
        cout << "Failed: TestAdd" << endl;
    }

    if (!TestAddInPlace()) {
        cout << "Failed: TestAddInPlace" << endl;
    }

    //EVEN MORE TEST CASES

    if (!TestNegativeSeconds()) {
        cout << "Failed: TestAddInPlace" << endl;
    }

    if (!TestZeroAddition()) {
        cout << "Failed: TestAddInPlace" << endl;
    }

    if (!TestSubtractResultNegative()) {
        cout << "Failed: TestAddInPlace" << endl;
    }

    if (!TestChainedAddition()) {
        cout << "Failed: TestAddInPlace" << endl;
    }

    if (!TestNegateOperator()) {
        cout << "Failed: TestAddInPlace" << endl;
    }

    cout << "Testing Complete" << endl;
}