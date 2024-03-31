#include <iostream>
#include <map>
#include "heatflow.hpp"

using namespace std;

int main(){

    map<int, float> sourcesAndSinks;

    sourcesAndSinks[1] = 100.0;

    Heatflow h(10, 5, 0.1, 2, 3, sourcesAndSinks);
    cout << endl;
    h.prettyPrint();

    h.tick();
    h.prettyPrint();

    h.tick();
    h.prettyPrint();
    
    return 0;
}
