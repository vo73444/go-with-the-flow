#include <vector>
#include <iostream>
#include <map>

class Heatflow{

    std::vector<float> rod;

    std::vector<float> rod2;

    std::map<int,float> sources_sink;

    float k;

    int step;

    public:

    Heatflow(float temp, int sections, float k, std::map<int, float> map);

    void tick();

    void prettyPrint();

    float getTemp(int x);
};
