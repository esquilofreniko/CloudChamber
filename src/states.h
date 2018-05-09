#ifndef states_h
#define states_h

#include <iostream>

class States {
private:
    int currentState;
    int numStates;
public:
    States();
    void genLengths();
    void changeState(int newState);
    int getCurrent();
};


#endif /* states_h */
