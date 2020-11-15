#include "Population.h"
#include <iostream>

Population::Population(int population_size) {
    size = population_size;
    for (int i = 0; i < population_size; ++i) {
        specimens.push_back(false);
    }
}

int Population::return_size() {
    return size;
}

void Population::crossover(vector <Specimen> &v1, vector <Specimen> &v2, int number)
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
