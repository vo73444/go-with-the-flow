#include <iostream>
#include <map>
#include <iterator>
#include "heatflow.hpp"

using namespace std;

Heatflow::Heatflow(float temp, int sections, float constant, map<int, float> m){

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

    k = constant;

    step = 1;
}

void Heatflow::tick(){
    map<int,float>::iterator itr;

    if(step % 2 != 0){
        for(int i = 1; i < rod.size() - 1; i++){
            for(itr = sources_sink.begin(); itr != sources_sink.end(); itr++){
                if(itr->first == i){
                    rod2[i] = itr->second;
                    break;
                }
                else{
                    rod2[i] = rod[i] + (k * (rod[i+1] - (2*rod[i]) + rod[i-1]));
                }
            }
            
        }

        step += 1;
    }

    else{
        for(int i = 1; i < rod.size() - 1; i++){
            for(itr = sources_sink.begin(); itr != sources_sink.end(); itr++){
                if(itr->first == i){
                    rod[i] = itr->second;
                    break;
                }
                else{
                    rod[i] = rod2[i] + (k * (rod2[i+1] - (2*rod2[i]) + rod2[i-1]));
                }
            }
            
        }

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

int Heatflow::getSize(){
    return rod.size();
}
