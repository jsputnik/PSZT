#include <iostream>
#include <ctime>
#include <vector>
#include <cstdio>
#include "Specimen.h"
#include "Population.h"

using namespace std;

//number of cards N, sum A, product B, match level goal G
int main(int argc, char* argv[]) {
    clock_t start = clock();
    srand(time(nullptr));
    if (argc != 5) {
        cout << "Incorrect number of parameters given" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    double sum_a_goal = atof(argv[2]); //19400
    double product_b_goal = atof(argv[3]); //6.89557e+197
    double match_level_goal = atof(argv[4]); //0.3
    cout << "Number of cards N: " << n << endl;
    cout << "Sum A goal: " << sum_a_goal << endl;
    cout << "Product B goal: " << product_b_goal << endl;
    cout << "Match level goal: " << match_level_goal << endl << endl;
    float baseMutationProbability = 100;
    int crossoverProbability = 100;
    int numberOfSpecimens = 200;
    fstream plik;
    plik.open("t1.txt", ios::out);
    if(!plik)
	{
		cout << "Unable to open file";
		return 1;
	}
	plik<<"Generation Grade"<<endl;
    Population pop(numberOfSpecimens, n, sum_a_goal, product_b_goal, match_level_goal, baseMutationProbability, crossoverProbability);
    //pop.print();
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
        pop_after_selection = pop.tourney_selection(); //tourney selection
        //pop_after_selection = pop.selection(); //random selection
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
        //pop_after_crossing.singleCrossover(); //one point crossing with set cross point
        pop_after_crossing.update_population(sum_a_goal, product_b_goal, match_level_goal);
        cout << "bp" << endl;
        pop_after_mutating = pop_after_crossing;
        pop_after_mutating.mutate();
        pop_after_mutating.update_population(sum_a_goal, product_b_goal, match_level_goal);
        pop = pop_after_mutating; //succession
        spec = pop[pop.find_best()];
        double x = spec.get_grade();
        plik <<i+1<<" "<<x<<endl;
        if (best_spec.get_grade() > spec.get_grade()) {
            best_spec = spec;
        }
        ++i;
    }
    cout << "End population: " <<i<< endl;
    cout << "Best specimen: " << endl;
    best_spec.print();
    float time = (clock() - start) / 1000000.000;
    cout<<"Time: "<<time<<" s" <<endl;
    plik.close();
    fstream plik2;
    plik2.open("time.txt", ios::app);
    if(!plik2)
	{
		cout << "Unable to open file";
		return 1;
	}
	plik2<<sum_a_goal<<" "<<product_b_goal<<" "<<match_level_goal<<" "<<baseMutationProbability<<" "<<crossoverProbability<<" "<<numberOfSpecimens<<" "<<n<<" "<<time<<endl;
	plik2.close();
    return 0;
}
