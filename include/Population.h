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
    Population(); //empty population
    Population(int population_size, int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal, float baseMutationProbability, int crossoverProbability); //initialize and grade population
    void print(); //used to print all the specimens in population
    Population selection(); //random selection
    Population tourney_selection(); //tourney selection
    void singleCrossover(int number); //one point crossover in number
    void doubleCrossover(int number1, int number2); //two point crossover in number1 and number2
    void singleCrossover(); //one point crossover in half
    void crossover(vector <bool> &v1, vector <bool> &v2, int number); //used in singleCrossover()
    void crossover2(vector <bool> &v1, vector <bool> &v2, int number1, int number2); //used in doubleCrossover
    void mutate();
    void calculateMutationProbability(float baseMutationProbability);
    void update_population(double sum_a_goal, double product_b_goal, double match_level_goal); //use to fill/update all of Specimen's attributes in whole population
    int find_best(); //finds index of the best specimen in the population
    const Specimen& operator[](int index); //returns Specimen from given index
    Population& operator=(const Population& pop);
};

#endif // POPULATION_H_INCLUDED
