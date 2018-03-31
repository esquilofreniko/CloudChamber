#ifndef states_h
#define states_h

#include <iostream>

class States {
private:
    int currentState;
    int divisionSize;
public:
    States();
    int getCurrent();
    int getDivisions();
};


#endif /* states_h */
