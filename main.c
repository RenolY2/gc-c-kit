#include "headers/example.h"

// Arrays should be initialized like this.
// Weird compiler behavior happens when initializing an array to zeros.
int staticarray = { [0 ... 31] = 1};

void onSomeGameActionHappens(uint32* someReference, int arg2) {
    OSReport("Hey, a thing happened! Test %i", staticarray[0]);
    // We run some function of the game that does something 
    SomeFunction(0);
    // We run the game function that was originally supposed to run so the game
    // continues to work.
    someGameHandlingFunction(someReference, arg2);
}
