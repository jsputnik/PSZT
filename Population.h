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

    public:
    Population(int population_size); //initialise population
    int return_size();
    void selection();
    void crossover(vector <Specimen> &v1, vector <Specimen> &v2, int number);
   // void crossing_and_mutation();
};

#endif // POPULATION_H_INCLUDED
