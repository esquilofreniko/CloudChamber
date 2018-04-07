#ifndef states_h
#define states_h

#include <iostream>

class States {
private:
    int currentState;
public:
    States();
    void changeState();
    int getCurrent();
};


#endif /* states_h */
