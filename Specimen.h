#ifndef SPECIMEN_H_INCLUDED
#define SPECIMEN_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;
/*****************************************
vector <bool> element only contains the lower row, the card value is the same for all Specimens so we omit it
 _______________________________
|Card Value  | 1 | 2 | ... | N  |
|____________|___|___|_____|____|
|A (0) B (1) | 0 | 1 | ... | 1  |
|____________|___|___|_____|____|
*****************************************/
class Specimen
{
    double grade; //max of match_level_a & match_level_b, the closer to 0 the better
    double sum_a;
    double product_b;
    double match_level_a;
    double match_level_b;
public:
    vector < bool > element; //shows which card is on which stack

    Specimen(); //empty specimen
    Specimen(int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal); //initialize a single specimen
    Specimen& operator=(const Specimen& spec);
    void print(); //prints all contents of Specimen class + which cards are on which stack
    void calculate_scores(); //calculate sum_a, product_b
    void calculate_match_levels(double sum_a_goal, double product_b_goal, double match_level_goal); //calculate match_level_a, match_level_b, grade
    void calculate(double sum_a_goal, double product_b_goal, double match_level_goal); //calculate_scores() & calculate_match_levels(), use to fill all Specimen private fields
    void mutate(vector <float> mutationProbability);
    double get_grade() const;
};

#endif // SPECIMEN_H_INCLUDED
