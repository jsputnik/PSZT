#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include "Specimen.h"
#include <vector>
#include <bits/stdc++.h>

class Population
{
    public:
    vector < Specimen > specimens;
    int size;
    vector < int > mutationProbability;

    public:
    Population(int population_size, int card_quantity); //initialise population
    void print();
    int return_size();
    Population selection();
    void singleCrossover(int number);
    void singleCrossover();//crossover in half
    void crossover(vector <bool> &v1, vector <bool> &v2, int number);
    void mutate(vector <bool> &v1);
};

#endif // POPULATION_H_INCLUDED
