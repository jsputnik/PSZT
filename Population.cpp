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
