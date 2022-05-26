#include "HealthPoints.h"
#include <iostream>
using std::cout;
using std::endl;

#define ZERO 0


HealthPoints::HealthPoints(int MaxHp)
{
    if(MaxHp <=0)
    {
        throw InvalidArgument();
    }
    m_currentHP = MaxHp;
    m_maxHP = MaxHp;
}



HealthPoints& HealthPoints::operator-=(const int number)
{
    *this += -number;
    return *this;
}
HealthPoints& HealthPoints::operator+=(const int number)
{
    if(m_currentHP + number >= m_maxHP)
    {
        m_currentHP = m_maxHP;
    }
    else if (m_currentHP + number <= ZERO)
    {
        m_currentHP = ZERO;
    }
    else m_currentHP = m_currentHP + number;
    return *this;
}

HealthPoints operator+(int number, const HealthPoints& healthPoints)
{
    HealthPoints newHealthPoints = healthPoints;
    newHealthPoints += number;
    return newHealthPoints;
}

HealthPoints operator+(const HealthPoints& healthPoints, int number)
{
    return number + healthPoints;
}

HealthPoints operator-(const HealthPoints& healthPoints, int number)
{
    return healthPoints + -number;
}

bool operator==(HealthPoints healthPoints1, HealthPoints healthPoints2)
{
    return ((healthPoints1 >= healthPoints2) && (healthPoints2 >= healthPoints1));
}

bool operator!=(HealthPoints healthPoints1, HealthPoints healthPoints2)
{
    return !(healthPoints1 == healthPoints2);
}

bool operator>=(HealthPoints healthPoints1, HealthPoints healthPoints2)
{
    return (healthPoints1.m_currentHP >= healthPoints2.m_currentHP);
}

bool operator>(HealthPoints healthPoints1, HealthPoints healthPoints2)
{
    return ((healthPoints1 >= healthPoints2) && (healthPoints1 != healthPoints2));
}

bool operator<=(HealthPoints healthPoints1, HealthPoints healthPoints2)
{
    return (!(healthPoints1 >= healthPoints2) || (healthPoints1 == healthPoints2));
}

bool operator<(HealthPoints healthPoints1, HealthPoints healthPoints2)
{
    return !(healthPoints1 >= healthPoints2);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.m_currentHP << "(" << hp.m_maxHP << ")";
    return os;
}