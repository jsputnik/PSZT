#ifndef SPECIMEN_H_INCLUDED
#define SPECIMEN_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

class Specimen
{
    double grade; //max of match_level_a & match_level_b, the closer to 0 the better
    double sum_a;
    double product_b;
    double match_level_a;
    double match_level_b;
public:
    vector < bool > element;

    Specimen();
    Specimen(int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal); //initialise a single specimen
    Specimen(int card_quantity, int a, double sum_a_goal, double product_b_goal, double match_level_goal); //initialise a special specimen, to be deleted
    Specimen& operator=(const Specimen& spec);
    void print();
    void calculate_scores(); //calculate sum_a, product_b
    void calculate_match_levels(double sum_a_goal, double product_b_goal, double match_level_goal); //calculate match_level_a, match_level_b, grade
    void calculate(double sum_a_goal, double product_b_goal, double match_level_goal); //calculate_scores() & calculate_match_levels(), use to fill all doubles
    double get_grade() const;
};

#endif // SPECIMEN_H_INCLUDED
