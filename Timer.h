#ifndef TIMER_H
#define TIMER_H

#include <chrono>

using namespace std;

class Timer {
private:
    using hrClock = chrono::high_resolution_clock;
    using durationDouble = chrono::duration<double>;
    chrono::time_point<hrClock> start;

public:
    Timer() : start{hrClock::now()} {}

    void reset() {
        start = hrClock::now();
    }

    double elapsed() const {
        return durationDouble(hrClock::now() - start).count();
    }
};

#endif