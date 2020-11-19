#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include "Specimen.h"
#include <vector>
#include <bits/stdc++.h>

class Population
{
    public:
    vector < Specimen > specimens;
    vector < float > mutationProbability;
    int crossoverProbability;
    float baseMutationProbability;

    public:
    Population();
    Population(int population_size, int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal, float baseMutationProbability, int crossoverProbability); //initialise and grade population
    void print();
    Population selection();
    Population tourney_selection();
    void singleCrossover(int number);
    void doubleCrossover(int number1, int number2);
    void singleCrossover();//crossover in half
    void crossover(vector <bool> &v1, vector <bool> &v2, int number);
    void crossover2(vector <bool> &v1, vector <bool> &v2, int number1, int number2);
    void mutate();
    void calculateMutationProbability(float baseMutationProbability);
    void update_population(double sum_a_goal, double product_b_goal, double match_level_goal); //use to fill/update all of specimen's fields in whole population
    int find_best(); //finds index of the best specimen in the population
    const Specimen& operator[](int index); //returns Specimen from given index
    Population& operator=(const Population& pop);
};

#endif // POPULATION_H_INCLUDED
