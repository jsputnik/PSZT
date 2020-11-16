#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include "Specimen.h"
#include <vector>
#include <bits/stdc++.h>

class Population
{
    public:
    vector < Specimen > specimens;
   // vector < int > mutationProbability;
    int mutationProbability;
    public:
    Population(int population_size, int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal); //initialise and grade population
    void print();
    Population selection(double sum_a_goal, double product_b_goal, double match_level_goal);
    void singleCrossover(int number);
    void singleCrossover();//crossover in half
    void crossover(vector <bool> &v1, vector <bool> &v2, int number);
    void mutate(vector <bool> &v1);
    void update_population(double sum_a_goal, double product_b_goal, double match_level_goal); //use to fill/update all of specimen's fields in whole population
};

#endif // POPULATION_H_INCLUDED
