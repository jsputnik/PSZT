#include "Specimen.h"
#include <cmath>

using namespace std;

/*****************************************
 _______________________________
|Card Value  | 1 | 2 | ... | N  |
|____________|___|___|_____|____|
|A (0) B (1) | 0 | 1 | ... | 1  |
|____________|___|___|_____|____|
*****************************************/
Specimen::Specimen(int card_quantity, double sum_a_goal, double product_b_goal, double match_level_goal) {
    for (int i = 0; i < card_quantity; ++i) {
        int value = rand() % 2;
        element.push_back(value);
    }
    calculate(sum_a_goal, product_b_goal, match_level_goal);
}

Specimen::Specimen() {
    grade = 0;
    sum_a = 0;
    product_b = 0;
    match_level_a = 0;
    match_level_b = 0;
    ;
}
//making a special case divisions, all cards on A (a = 0) or all on B (a = 1)
Specimen::Specimen(int card_quantity, int a, double sum_a_goal, double product_b_goal, double match_level_goal) {
    if (a == 0) {
        for (int i = 0; i < card_quantity; ++i) {
            element.push_back(0);
        }
    }
    else if (a == 1) {
        for (int i = 0; i < card_quantity; ++i) {
            element.push_back(1);
        }
    }
    else {
        for (int i = 0; i < card_quantity; ++i) {
            int value = rand() % 2;
            element.push_back(value);
        }
    }
    calculate(sum_a_goal, product_b_goal, match_level_goal);
}

Specimen& Specimen::operator=(const Specimen& spec) {
    element = spec.element;
    grade = spec.grade;
    sum_a = spec.sum_a;
    product_b = spec.product_b;
    match_level_a = spec.match_level_a;
    match_level_b = spec.match_level_b;
    return *this;
}

double Specimen::get_grade() {
    return grade;
}

void Specimen::print() {
    cout << "|";
    for (unsigned int i = 0; i < element.size(); ++i) {
        cout << element[i] << "|";
    }
    cout << " ";
    cout << "Sum A: " << sum_a << ", ";
    cout << "Product B: " << product_b << ", ";
    cout << "Match level A: " << match_level_a << ", ";
    cout << "Match level B: " << match_level_b << ", ";
    cout << "Grade: " << grade << endl;
}

void Specimen::calculate_scores() {
    sum_a = 0;
    product_b = 0;
    for (unsigned int i = 0; i < element.size(); ++i) {
        if (!element[i]) {
            sum_a += i + 1;
        }
        else {
            product_b = (product_b > 0) ? product_b * (i + 1) : (i + 1);
        }
    }
}
//the closer to 0 the better
void Specimen::calculate_match_levels(double sum_a_goal, double product_b_goal, double match_level_goal) {
    match_level_a = abs(sum_a_goal - sum_a)/sum_a_goal;
    match_level_b = abs(product_b_goal - product_b)/product_b_goal;
    grade = max(match_level_a, match_level_b);
}

void Specimen::calculate(double sum_a_goal, double product_b_goal, double match_level_goal) {
    calculate_scores();
    calculate_match_levels(sum_a_goal, product_b_goal, match_level_goal);
}
