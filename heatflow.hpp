#include <vector>
#include <iostream>

class Heatflow{

    std::vector<float> rod;

    std::vector<float> rod2;

    float k;

    int step;

    public:

    Heatflow(float temp, int sections, float k );

    void tick();

    void prettyPrint();

    float getTemp(int x);

    int getSize();

};
