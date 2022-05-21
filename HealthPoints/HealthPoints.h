
#ifndef EX3_HealthPoints_H
#define EX3_HealthPoints_H

#include <stdbool.h>


class HealthPoints {
public:

    class InvalidArgument{};

     /*
    *
    * C'tor of the healthPoints class
    * 
    * @param maxHP - the maximum HP the player can have, default value is 100
    * @return 
    *        A new instance of a health points
    */
    HealthPoints(int MaxHp = 100);

    

     /*
    * -= operator
    */          
    HealthPoints& operator-=(const int number);

     /*
    * - (minus) operator
    */
    HealthPoints& operator+=(const int number);


     /*
    * taking the default c'tor d'tor and assignment
    */
    HealthPoints& operator=(const HealthPoints& other) = default;
    ~HealthPoints() = default;
    HealthPoints(const HealthPoints&) = default;





private:
    int m_maxHP;
    int m_currentHP;

     /*
    * boolean operators
    */
    friend bool operator==(HealthPoints hp1, HealthPoints hp2);
    friend bool operator!=(HealthPoints hp1, HealthPoints hp2);
    friend bool operator>=(HealthPoints hp1, HealthPoints hp2);
    friend bool operator>(HealthPoints hp1, HealthPoints hp2);
    friend bool operator<=(HealthPoints hp1, HealthPoints hp2);
    friend bool operator<(HealthPoints hp1, HealthPoints hp2);

     /*
    *
    * + operator
    */
    friend HealthPoints operator+(const int number, const HealthPoints& hp);
    friend HealthPoints operator+(const HealthPoints& hp, const int number);

     /*
    * - (minus) operator
    */
    friend HealthPoints operator-(const int number, const HealthPoints& hp);
    friend HealthPoints operator-(const HealthPoints& hp, const int number);
    
    /*
    * print operator
    */
    friend std::ostream& operator<<(std::ostream& os, HealthPoints& hp)
    {
        os << hp.m_currentHP << "(" << hp.m_maxHP << ")";
    }
};



#endif //EX3_HealthPoints_H