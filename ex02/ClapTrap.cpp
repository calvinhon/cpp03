#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
    _hitPts(100),
    _energyPts(10),
    _attackDmg(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name):
    _Name(Name),
    _hitPts(100),
    _energyPts(10),
    _attackDmg(0) {
    std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_Name = src._Name;
        this->_hitPts = src._hitPts;
        this->_energyPts = src._energyPts;
        this->_attackDmg = src._attackDmg;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (_energyPts && _hitPts) {
        _energyPts--;
        std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
    }
    else if (!_hitPts)
        std::cout << "ClapTrap " << _Name << " is dead and cannot attack!" << std::endl;
    else
        std::cout << "ClapTrap " << _Name << " has no energy points to attack!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPts) {
        if (amount > _hitPts)
            amount = _hitPts;
        _hitPts -= amount;
        std::cout << "ClapTrap " << _Name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _Name << " is dead and cannot take damage!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPts && _hitPts) {
        _energyPts--;
        _hitPts += amount;
        std::cout << "ClapTrap " << _Name << " repairs itself for " << amount << " hit point";
        if (amount > 1)
            std::cout << "s!" << std::endl;
        else
            std::cout << "!" << std::endl;
    }
    else if (!_hitPts)
        std::cout << "ClapTrap " << _Name << " is dead and cannot repair itself!" << std::endl;
    else
        std::cout << "ClapTrap " << _Name << " has no energy points to repair itself!" << std::endl;
}