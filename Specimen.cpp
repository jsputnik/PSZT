#include "Specimen.h"

/*****************************************
 _______________________________
|Card Value  | 1 | 2 | ... | N  |
|____________|___|___|_____|____|
|A (0) B (1) | 0 | 1 | ... | 1  |
|____________|___|___|_____|____|
*****************************************/
Specimen::Specimen(int card_quantity) {
    for (int i = 0; i < card_quantity; ++i) {
        int value = rand() % 2;
        element.push_back(value);
    }
}

void Specimen::print() {
    for (int i = 0; i <element.size(); ++i) {
        std::cout << element[i] << "|";
    }
    std::cout << std:: endl;
}


