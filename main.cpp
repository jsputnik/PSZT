#include <iostream>
#include <ctime>
#include <vector>
#include "Specimen.h"
#include "Population.h"

using namespace std;

int main() {
    srand(time(nullptr));
    double sum_a_goal = 40;
    double product_b_goal = 2500;
    double match_level_goal = 0.05;
    float baseMutationProbability = 50;
    int crossoverProbability = 50;

    Population pop(8, 11, sum_a_goal, product_b_goal, match_level_goal, baseMutationProbability, crossoverProbability);
    pop.print();
    Specimen best_spec; //best of all time
    best_spec = pop[pop.find_best()];
    cout << "Best specimen of population: " << endl;
    best_spec.print();
    Population pop_after_selection;
    Population pop_after_crossing;
    Population pop_after_mutating;


    while (best_spec.get_grade() > match_level_goal) {
        pop_after_selection = pop.selection();
        //cout << "After selection" << endl;
        //pop_after_selection.print();
        pop_after_crossing = pop_after_selection;
        pop_after_crossing.singleCrossover();
        pop_after_crossing.update_population(sum_a_goal, product_b_goal, match_level_goal);
        //cout << "After crossing" << endl;
        //pop_after_crossing.print();
        pop_after_mutating = pop_after_crossing;
        for(unsigned int i=0; i<pop_after_mutating.specimens.size(); i++)
        {
            pop_after_mutating.mutate();
        }
        pop_after_mutating.update_population(sum_a_goal, product_b_goal, match_level_goal);
        //cout << "After mutating" << endl;
        //pop_after_mutating.print();
        pop = pop_after_mutating;
        if (best_spec.get_grade() > pop[pop.find_best()].get_grade()) {
            best_spec = pop[pop.find_best()]; //just this line without if if want to lok at best spec from each population
        }
        cout << "Best specimen of population: " << endl;
        best_spec.print();
    }
    pop.print();
    return 0;
}
