#include "Population.h"
#include <iostream>

const Specimen& Population::operator[](int index) {
    return specimens[index];
}

Population& Population::operator=(const Population& pop) {
    specimens = pop.specimens;
    mutationProbability = pop.mutationProbability;
    return *this;
}

Population::Population() {

}

Population::Population(int population_size, int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal, float baseMutationProbability, int crossoverProbability) {
   this->baseMutationProbability = baseMutationProbability;
   this->crossoverProbability = crossoverProbability;
    for (int i = 0; i < population_size; ++i) {
        Specimen spec(card_quantity, sum_a_goal, product_b_goal, match_level_goal);
        specimens.push_back(spec);
    }
}

void Population::update_population(double sum_a_goal, double product_b_goal, double match_level_goal) {
    for (unsigned int i = 0; i < specimens.size(); ++i) {
        specimens[i].calculate(sum_a_goal, product_b_goal, match_level_goal);
    }
}

void Population::print() {
    for (unsigned int i = 0; i < specimens.size(); ++i) {
        specimens[i].print();
    }
}
int Population::find_best() {
    int best_index = 0;
    for (unsigned int i = 1; i < specimens.size(); ++i) {
        if (specimens[i].get_grade() < specimens[best_index].get_grade()) {
            best_index = i;
        }
    }
    return best_index;
}

void Population::crossover(vector <bool> &v1, vector <bool> &v2, int number)
{
    vector <bool> temp;
    temp.insert(temp.end(), v1.begin(), v1.begin() + number);
    reverse(v1.begin(), v1.end());
    for(int i = 0; i<number; i++)
    {
        v1.pop_back();
    }
    reverse(v1.begin(), v1.end());
    v1.insert(v1.begin(), v2.begin(), v2.begin() + number);
    reverse(v2.begin(), v2.end());
    for(int i = 0; i<number; i++)
    {
        v2.pop_back();
    }
    reverse(v2.begin(), v2.end());
    v2.insert(v2.begin(), temp.begin(), temp.begin() + number);
}

void Population::singleCrossover(int number)
{
    for(unsigned int i=0; i<(specimens.size()/2); i++)
    {
        if(rand() % 100 < crossoverProbability)
            crossover(specimens[2*i].element, specimens[2*i+1].element, number);
    }
}

void Population::singleCrossover()
{
    int number = specimens.size()/2;
    for(unsigned int i=0; i<(specimens.size()/2); i++)
    {
        if(rand() % 100 < crossoverProbability)
            crossover(specimens[2*i].element, specimens[2*i+1].element, number);
    }
}

Population Population::tourney_selection() {
    Population pop;
    int j;
    int k;
    for (unsigned int i = 0; i < specimens.size(); ++i) {
        j = rand() % specimens.size();
        k = rand() % specimens.size();
        if (specimens[j].get_grade() < specimens[k].get_grade()) {
            pop.specimens.push_back(specimens[j]);
        }
        else {
            pop.specimens.push_back(specimens[k]);
        }
    }
    return pop;
}

Population Population::selection()
{
    Population pop;
    int temp;
    for(unsigned int i=0; i < specimens.size(); i++)
    {
        temp = rand() % specimens.size();
        pop.specimens.push_back(specimens[temp]);
    }
    return pop;
}

void Population::calculateMutationProbability(float baseMutationProbability)
{
    for (unsigned int i = 0; i < specimens.size(); i++) {
        mutationProbability.push_back(baseMutationProbability);
        baseMutationProbability *= 0.8;
    }
}

void Population::mutate()
{
    calculateMutationProbability(baseMutationProbability);
    for (unsigned int i = 0; i < specimens.size(); i++) {
        specimens[i].mutate(mutationProbability);
    }
}
