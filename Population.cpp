#include "Population.h"
#include <iostream>

Population::Population(int population_size) {
    size = population_size;
    int temp = 100;
    for (int i = 0; i < population_size; ++i) {
        specimens.push_back(false);
        mutationProbability.push_back(temp);
        temp *= 0.8;
    }
}

int Population::return_size() {
    return size;
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

void Population::mutate(vector <bool> &v1)
{
    int el = rand() % v1.size();
    if( rand() % 100 <= mutationProbability[el])
        v1[el] = !v1[el];
}
