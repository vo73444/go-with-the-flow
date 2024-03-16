#include <iostream>
#include "heatflow.hpp"
#include <cassert>

using namespace std;

int main(){

    cout <<"\nTest started.\n";

    Heatflow h = Heatflow(10, 5, 0.1);

    h.tick();

    assert(h.getTemp(0) == 100.00 && h.getTemp(1) == 19.00 && h.getTemp(2) == 10.00);

    h.tick();

    assert(h.getTemp(0) == 100.00 && abs(h.getTemp(1) - 26.2) < 0.1);
    
    assert(abs(h.getTemp(2) - 10.9) < 0.1 && h.getTemp(3) == 10.00);

    cout << "\n\nTest passed.\n";


    return 0;
}

// g++ heatflow.cpp test.cpp
