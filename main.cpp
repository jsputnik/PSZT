#include <iostream>
#include <ctime>
#include <vector>
#include "Specimen.h"
#include "Population.h"

using namespace std;

int main() {
    srand(time(nullptr));
    double sum_a_goal = 50;
    double product_b_goal = 3000;
    double match_level_goal = 0.1;

    Population pop(5, 10, sum_a_goal, product_b_goal, match_level_goal);
    pop.print();
    Specimen best_spec;
    best_spec = pop[pop.find_best()];
    cout << "Best specimen of population: " << endl;
    best_spec.print();
    Population pop_after_selection;
    Population pop_after_crossing_and_mutating;
    pop_after_selection = pop.selection();
    cout << "After selection" << endl;
    pop_after_selection.print();
    //while (best_spec.get_grade() > match_level_goal) {}
    //pop[pop.find_best()].print();
    /*
    Population nowa(0,0, sum_a_goal, product_b_goal, match_level_goal);
    nowa = pop.selection(sum_a_goal, product_b_goal, match_level_goal);
    cout<<"after selection"<<endl;
    nowa.print();
    nowa.singleCrossover(3);
    for(int i=0; i<nowa.specimens.size(); i++)
    {
        nowa.specimens[i].calculate(sum_a_goal, product_b_goal, match_level_goal);
    }
    cout<<"after cross"<<endl;
    nowa.print();
    for(int i=0; i<nowa.specimens.size(); i++)
    {
        nowa.mutate(nowa.specimens[i].element);
    }
    cout<<"after mutate"<<endl;

    for(int i=0; i<nowa.specimens.size(); i++)
    {
        nowa.specimens[i].calculate(sum_a_goal, product_b_goal, match_level_goal);
    }
    nowa.print();
    */

    return 0;
}
