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
    m_currentHP = (m_currentHP - number <= ZERO)?  ZERO :  m_currentHP - number;
    return *this;
}
HealthPoints& HealthPoints::operator+=(const int number)
{
    m_currentHP = (m_currentHP + number >= m_maxHP)?  m_maxHP :  m_currentHP + number;
    return *this;
}

HealthPoints& operator+(int number, HealthPoints& hp)
{
    hp.m_currentHP = (hp.m_currentHP + number >= hp.m_currentHP)? hp.m_maxHP : hp.m_currentHP + number;
    return hp;
}

HealthPoints& operator+(HealthPoints& hp, int number)
{
    hp.m_currentHP = (hp.m_currentHP + number >= hp.m_currentHP)? hp.m_maxHP : hp.m_currentHP + number;
    return hp;
}

HealthPoints& operator-(HealthPoints& hp, int number)
{
    hp.m_currentHP = (hp.m_currentHP - number <= ZERO)? ZERO : hp.m_currentHP - number;
    return hp;
}

HealthPoints& operator-(int number, HealthPoints& hp)
{
    hp.m_currentHP = (hp.m_currentHP - number <= ZERO)? ZERO : hp.m_currentHP - number;
    return hp;
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

    std::ostream& operator<<(std::ostream& os, HealthPoints& hp)
    {
        os << hp.m_currentHP << "(" << hp.m_maxHP << ")";
        return os;
    }