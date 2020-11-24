#include "Specimen.h"
#include <cmath>

using namespace std;

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
}

void Specimen::mutate(vector <float> mutationProbability)
{
    int el = rand() % element.size();

    if( rand() % 100 <= mutationProbability[el])
        element[el] = !element[el];
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

double Specimen::get_grade() const {
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
    vector <int> a_stack;
    vector <int> b_stack;
    for (unsigned int i = 0; i < element.size(); ++i) {
        if (element[i] == 0) {
            a_stack.push_back(i + 1);
        }
        else {
            b_stack.push_back(i + 1);
        }
    }
    cout << "Cards on A: ";
    for (unsigned int i = 0; i < a_stack.size(); ++i) {
        cout << a_stack[i] << "; ";
    }
    cout << endl;
    cout << "Cards on B: ";
    for (unsigned int i = 0; i < b_stack.size(); ++i) {
        cout << b_stack[i] << "; ";
    }
    cout << endl;
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

void Specimen::calculate_match_levels(double sum_a_goal, double product_b_goal, double match_level_goal) {
    match_level_a = abs(sum_a_goal - sum_a)/sum_a_goal;
    match_level_b = abs(product_b_goal - product_b)/product_b_goal;
    grade = max(match_level_a, match_level_b);
}

void Specimen::calculate(double sum_a_goal, double product_b_goal, double match_level_goal) {
    calculate_scores();
    calculate_match_levels(sum_a_goal, product_b_goal, match_level_goal);
}
