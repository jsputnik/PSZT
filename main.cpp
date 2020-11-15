#include <iostream>
#include <ctime>
#include <vector>
#include "Specimen.h"
#include "Population.h"

using namespace std;

int main() {
    srand(time(nullptr));
    vector <Population> population_list;
    Population pop(20);
    population_list.push_back(pop);
    int pm = 0;
    int pc = 0;
    int mu = 0;
    int t = 0;
    pop.specimens[0].element.push_back(0);
    pop.specimens[0].element.push_back(0);
    pop.specimens[0].element.push_back(0);
    pop.specimens[0].element.push_back(0);
    pop.specimens[0].element.push_back(0);
    pop.specimens[0].element.push_back(0);

    pop.specimens[1].element.push_back(1);
    pop.specimens[1].element.push_back(1);
    pop.specimens[1].element.push_back(1);
    pop.specimens[1].element.push_back(1);
    pop.specimens[1].element.push_back(1);
    pop.specimens[1].element.push_back(1);

    pop.crossover(pop.specimens[0], pop.specimens[1], 2);


    for(int i=0;i<pop.specimens[0].size();i++)
    {
        cout<<pop.specimens[0]<<endl;
    }
    cout<<endl;
    for(int i=0;i<pop.specimens[1].size();i++)
    {
        cout<<pop.specimens[1]<<endl;
    }


    /*p = initialise();
    grade(p0);
    while(!end) {
        t = selection(p);
        o = crossing_and_mutation(t);
        garde(o);
        p = o;
        ++t;
    }*/
}
