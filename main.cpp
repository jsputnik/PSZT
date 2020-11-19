#include <iostream>
#include <ctime>
#include <vector>
#include <cstdio>
#include "Specimen.h"
#include "Population.h"

using namespace std;

int main() {
    clock_t start = clock();
    srand(time(nullptr));
    double sum_a_goal = 19400;
    double product_b_goal = 6.89557e+197;
    double match_level_goal = 0.3;
    float baseMutationProbability = 100;
    int crossoverProbability = 100;
    fstream plik;
    plik.open("t1.txt", ios::out);
    if(!plik)
	{
		cout << "Unable to open file";
		return 1;
	}
	plik<<"Generation Grade"<<endl;
    Population pop(100, 200, sum_a_goal, product_b_goal, match_level_goal, baseMutationProbability, crossoverProbability);
  //  pop.print();
    Specimen best_spec; //best of all time
    Specimen spec; //best of ith population
    best_spec = pop[pop.find_best()];
    cout << "Best specimen of population: " << endl;
    best_spec.print();
    Population pop_after_selection;
    Population pop_after_crossing;
    Population pop_after_mutating;
    int i = 0;
    int n1 = 0, n2 = 0;
    while (best_spec.get_grade() > match_level_goal && i < 1000) {
        //cout << "Starting population: " << endl;
        //pop.print();
        pop_after_selection = pop.tourney_selection();
        //pop_after_selection = pop.selection();
        //cout << "After selection: " << endl;
        //pop_after_selection.print();
        pop_after_crossing = pop_after_selection;
        while(n1 == n2)
        {
            n1 = rand() % pop.specimens.size();
            n2 = rand() % pop.specimens.size();
        }
        if(n1 < n2)
            pop_after_crossing.doubleCrossover(n1, n2);
        else
           pop_after_crossing.doubleCrossover(n2, n1);
        //pop_after_crossing.singleCrossover(); //crossing with set cross point
        pop_after_crossing.update_population(sum_a_goal, product_b_goal, match_level_goal);
        //cout << "After crossing: " << endl;
        //pop_after_crossing.print();
        pop_after_mutating = pop_after_crossing;
        pop_after_mutating.mutate();

        pop_after_mutating.update_population(sum_a_goal, product_b_goal, match_level_goal);
        pop = pop_after_mutating;
        spec = pop[pop.find_best()]; //just this line without if if want to look at best spec from each population
       //// cout << "Best specimen of population " << i << ": " << endl;
       //// spec.print();
        long double x = spec.get_grade();
        plik <<i+1<<" "<<x<<endl;
        if (best_spec.get_grade() > spec.get_grade()) {
            best_spec = spec;
        }
        ++i;
    }
    cout << "End population: " <<i<< endl;
    //pop.print();
    cout << "Best specimen: " << endl;
    best_spec.print();
    float time = (clock() - start) / 1000.000;
    cout<<"Time: "<<time<<" s" <<endl;
    plik.close();
    return 0;
}
