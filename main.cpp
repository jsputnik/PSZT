#include <iostream>
#include <ctime>
#include <vector>
#include "Specimen.h"
#include "Population.h"

using namespace std;

int main() {
    srand(time(nullptr));
    vector <Population> population_list;
    Population pop(6, 6);
    population_list.push_back(pop);
    pop.print();
 //   pop.singleCrossover();
    cout<<"after"<<endl;
 //   pop.print();
    int pm = 0;
    int pc = 0;
    int mu = 0;
    int t = 0;
    Population nowa(0,0);
    nowa = pop.selection();
    nowa.print();
   /* for(int i=0;i<pop.specimens[1].element.size();i++)
    {
        cout<<pop.specimens[1].element[i]<<endl;
    }*/


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
