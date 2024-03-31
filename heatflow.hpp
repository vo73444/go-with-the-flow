#include <vector>
#include <iostream>
#include <map>

class Heatflow{

    std::vector<float> rod;

    std::vector<float> rod2;

    std::map<int,float> sources_sink;

    float k;

    float x;

    float t;

    int step;

    void switch_rod(std::vector<float> &current_rod, std::vector<float> &next_rod);

    public:

    Heatflow(float temp, int sections, float k, float x, float t, std::map<int, float> map);

    void tick();

    void prettyPrint();

    float getTemp(int x);
};
