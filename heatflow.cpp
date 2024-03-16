#include <iostream>
#include "heatflow.hpp"

using namespace std;

Heatflow::Heatflow(float temp, int sections, float constant){
    rod.push_back(100.00);
    for(int i = 1; i <= sections; i++){
        rod.push_back(temp);
    }

    rod2.push_back(100.00);
    for(int i = 1; i <= sections; i++){
        rod2.push_back(temp);
    }

    k = constant;

    step = 1;
}

void Heatflow::tick(){
    if(step % 2 != 0){
        for(int i = 1; i < rod.size() - 1; i++){
            rod2[i] = rod[i] + (k * (rod[i+1] - (2*rod[i]) + rod[i-1]));
        }

        step += 1;
    }

    else{
        for(int i = 1; i < rod.size() - 1; i++){
            rod[i] = rod2[i] + (k * (rod2[i+1] - (2*rod2[i]) + rod2[i-1]));
        }

        step += 1;
    }
}

void Heatflow::prettyPrint(){
    if(step % 2 != 0){
        for(int i = 0; i < rod.size(); i++){
            cout << rod[i] << " ";
        }
    }

    else{
        for(int i = 0; i < rod.size(); i++){
            cout << rod2[i] << " ";
        }
    }

    cout << endl;
}

float Heatflow::getTemp(int x){
    if(step% 2 != 0){
        return rod[x];
    }

    else{
        return rod2[x];
    }
}

int Heatflow::getSize(){
    return rod.size();
}
