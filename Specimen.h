#ifndef SPECIMEN_H_INCLUDED
#define SPECIMEN_H_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

class Specimen
{
    public:
    vector < bool > element;
    float grade;

public:
    Specimen(int card_quantity); //initialise a single specimen
    void gradeMe();
};

#endif // SPECIMEN_H_INCLUDED
