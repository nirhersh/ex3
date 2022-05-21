#include "HealthPoints.h"

using std::cout;
using std::endl;

//to run the tests from the HW examples:

// be in HealthPoints folder
// run: g++ --std=c++11 -Wall -Werror -pedantic-errors HealthPoints.cpp main.cpp -o unitest.exe
// and then ./unitest.exe

int main()
{
    HealthPoints hp1 = 100;
    HealthPoints hp2 = 150;
    hp1 -= 20;
    cout << hp1 << endl;
    hp1 += 100;
    cout << hp1 << endl;
    hp1 -= 150;
    cout << hp1 << endl;
    hp2 = hp2 - 160;
    cout << hp2 << endl;
    hp2 = 160 + hp1;
    cout << hp2 << endl;

    bool comparisonResult;
    HealthPoints HealthPoints1(100);
    HealthPoints HealthPoints2 = 100;
    comparisonResult = HealthPoints1 == HealthPoints2;
    cout << comparisonResult << endl;
    HealthPoints2 = HealthPoints(150);
    cout << HealthPoints2 << endl;
    comparisonResult = HealthPoints1 == HealthPoints2;
    cout << comparisonResult << endl;
    HealthPoints2 -= 50;
    cout << HealthPoints2 << endl;
    comparisonResult = 100 == HealthPoints2;
    cout << comparisonResult << endl;
    comparisonResult =HealthPoints1 < HealthPoints2;
    cout << comparisonResult << endl;
    HealthPoints1 -= 50;
    cout << HealthPoints1 << endl;
    comparisonResult = HealthPoints1 < HealthPoints2;
    cout << comparisonResult << endl;






}