#include "HealthPoints.h"
#include <iostream>
using std::cout;
using std::endl;

#define ZERO 0


HealthPoints::HealthPoints(int MaxHp = 100)
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
    m_currentHP = (m_currentHP - number <= ZERO)?  ZERO :  m_currentHP - number;
    return *this;
}
HealthPoints& HealthPoints::operator+=(const int number)
{
    m_currentHP = (m_currentHP - number >= m_maxHP)?  m_maxHP :  m_currentHP - number;
    return *this;
}

HealthPoints operator+(const int number, const HealthPoints& hp)
{
    return HealthPoints((hp.m_currentHP + number >= hp.m_currentHP)? hp.m_maxHP : hp.m_currentHP + number);
}

HealthPoints operator+(const HealthPoints& hp, const int number)
{
    return HealthPoints((hp.m_currentHP + number >= hp.m_currentHP)? hp.m_maxHP : hp.m_currentHP + number);
}

HealthPoints operator-(const HealthPoints& hp, const int number)
{
    return HealthPoints((hp.m_currentHP - number <= ZERO)? ZERO : hp.m_currentHP - number);
}

HealthPoints operator-(const int number, const HealthPoints& hp)
{
    return HealthPoints((hp.m_currentHP - number <= ZERO)? ZERO : hp.m_currentHP - number);
}

bool operator==(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1.m_currentHP == hp2.m_currentHP);
}

bool operator!=(HealthPoints hp1, HealthPoints hp2)
{
    return !(hp1.m_currentHP == hp2.m_currentHP);
}

bool operator>=(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1.m_currentHP >= hp2.m_currentHP);
}

bool operator>(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1.m_currentHP > hp2.m_currentHP);
}

bool operator<=(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1.m_currentHP <= hp2.m_currentHP);
}

bool operator<(HealthPoints hp1, HealthPoints hp2)
{
    return (hp1.m_currentHP < hp2.m_currentHP);
}