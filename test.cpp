#include <iostream>
#include "heatflow.hpp"
#include <map>
#include <cassert>

using namespace std;

int main(){

    cout <<"\nTest started.\n";

    map<int, float> m1;

    m1[5] = 100;

    Heatflow h = Heatflow(10, 5, 0.1, m1);

    h.tick();

    assert(h.getTemp(5) == 100.00 && h.getTemp(4) == 19.00 && h.getTemp(3) == 10.00);

    h.tick();

    assert(h.getTemp(5) == 100.00 && abs(h.getTemp(4) - 26.2) < 0.1);

    assert(abs(h.getTemp(3) - 10.9) < 0.1 && h.getTemp(2) == 10.00);

    cout << "\nTest passed.\n";


    return 0;
}
