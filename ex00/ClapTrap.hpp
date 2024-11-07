#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {

public:
    ClapTrap();
    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap& src);
    ClapTrap& operator=(const ClapTrap& src);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string     _Name;
    unsigned int    _hitPts;
    unsigned int    _energyPts;
    unsigned int    _attackDmg;

};

#endif