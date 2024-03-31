#include <iostream>
#include <map>
#include <iterator>
#include "heatflow.hpp"

using namespace std;

Heatflow::Heatflow(float temp, int sections, float k, float x, float t, map<int, float> m){

    sources_sink = m;
    
    map<int, float>::iterator itr;

    for(int i = 0; i < sections + 2; i++){
        rod.push_back(temp);
    }

    for(int i = 0; i < sections + 2; i++){
        rod2.push_back(temp);
    }

    for(itr = sources_sink.begin(); itr != sources_sink.end(); itr++){
        rod[itr->first] = itr->second;
        rod2[itr->first] = itr->second;
    }

    this->k = k;
    this->x = x;
    this->t = t;

    step = 1;
}

void Heatflow::switch_rod(std::vector<float> &current_rod, std::vector<float> &next_rod){
    map<int,float>::iterator itr;

    for(int i = 1; i < rod.size() - 1; i++){
            for(itr = sources_sink.begin(); itr != sources_sink.end(); itr++){
                if(itr->first == i){
                    next_rod[i] = itr->second;
                    break;
                }
                else{
                    next_rod[i] = current_rod[i] + ((k * t) * ((current_rod[i+1] - (2 * current_rod[i]) + current_rod[i-1]) / pow(x, 2)));
                }
            }

    }
}

void Heatflow::tick(){


    if(step % 2 != 0){
        
        switch_rod(rod, rod2);

        step += 1;
    }

    else{
        
        switch_rod(rod2, rod);

        step += 1;
    }
}

void Heatflow::prettyPrint(){
    if(step % 2 != 0){
        cout << "| ";
        for(int i = 1; i < rod.size() - 1; i++){
            cout << rod[i] << " | ";
        }
        cout << endl;
    }

    else{
        cout << "| ";
        for(int i = 1; i < rod.size() - 1; i++){
            cout << rod2[i] << " | ";
        }
        cout << endl;
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
