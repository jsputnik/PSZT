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
    int dummy;
    vector < int > mutationProbability;

    public:
    Population(int population_size, int card_quantity); //initialise population
    void print();
    int return_size();
    void selection();
    void crossover(vector <bool> &v1, vector <bool> &v2, int number);
    void mutate(vector <bool> &v1);
};

#endif // POPULATION_H_INCLUDED
