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
    mutationProbability = 0;
}

Population::Population(int population_size, int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal) {
   // int temp = 100;
   mutationProbability = 10;
    for (int i = 0; i < population_size; ++i) {
        Specimen spec(card_quantity, sum_a_goal, product_b_goal, match_level_goal);
        specimens.push_back(spec);
        //mutationProbability.push_back(temp);
        //temp *= 0.8;
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
        crossover(specimens[2*i].element, specimens[2*i+1].element, number);
    }
}

void Population::singleCrossover()
{
    int number = specimens.size()/2;
    for(unsigned int i=0; i<(specimens.size()/2); i++)
    {
        crossover(specimens[2*i].element, specimens[2*i+1].element, number);
    }
}

Population Population::selection()
{
    Population pop1;
    int temp;
    for(unsigned int i=0; i < specimens.size(); i++)
    {
        temp = rand() % specimens.size();
        pop1.specimens.push_back(specimens[temp]);
    }
    return pop1;
}

void Population::mutate(vector <bool> &v1)
{
    int el = rand() % v1.size();

    if( rand() % 100 <= mutationProbability)
        v1[el] = !v1[el];
}
