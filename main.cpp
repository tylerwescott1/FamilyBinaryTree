#include "familyTree.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main(int args, char * argv[]) 
{
    ifstream infile(argv[1]);
    vector<int> familyMembers;
    familyTree * oldCountry;
    
    int wealth = 0;

    while (infile >> wealth)
        familyMembers.push_back(wealth);

    oldCountry = new familyTree(familyMembers);

    cout << "Orignal Tree" << endl;
    oldCountry->outputTree();

    oldCountry->updateInheritance();
    cout << endl;

    cout << "Updated Tree" << endl;
    oldCountry->outputTree();

    delete oldCountry;
    
    return 0;
}