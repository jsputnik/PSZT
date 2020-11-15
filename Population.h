#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include "Specimen.h"
#include <vector>

class Population
{
    vector < Specimen > specimens;
    int size;

public:
    Population(int population_size); //initialise population
    int return_size();
    void selection();
    void crossing_and_mutation();
};

#endif // POPULATION_H_INCLUDED
