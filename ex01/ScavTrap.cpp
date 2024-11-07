#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
    ClapTrap(),
    _guardingGate(0) {
    _energyPts = 50,
    _attackDmg = 20,
    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name): 
    ClapTrap(Name),
    _guardingGate(0) {
    _energyPts = 50,
    _attackDmg = 20,
    std::cout << "ScavTrap: Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src) {
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
    std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_Name = src._Name;
        this->_hitPts = src._hitPts;
        this->_energyPts = src._energyPts;
        this->_attackDmg = src._attackDmg;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (_energyPts && _hitPts) {
        _energyPts--;
        std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
    }
    else if (!_hitPts)
        std::cout << "ScavTrap " << _Name << " is dead and cannot attack!" << std::endl;
    else
        std::cout << "ScavTrap " << _Name << " has no energy points to attack!" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount) {
    if (_hitPts) {
        if (amount > _hitPts)
            amount = _hitPts;
        _hitPts -= amount;
        std::cout << "ScavTrap " << _Name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _Name << " is dead and cannot take damage!" << std::endl;
}

void    ScavTrap::beRepaired(unsigned int amount) {
    if (_energyPts && _hitPts) {
        _energyPts--;
        _hitPts += amount;
        std::cout << "ScavTrap " << _Name << " repairs itself for " << amount << " hit point";
        if (amount > 1)
            std::cout << "s!" << std::endl;
        else
            std::cout << "!" << std::endl;
    }
    else if (!_hitPts)
        std::cout << "ScavTrap " << _Name << " is dead and cannot repair itself!" << std::endl;
    else
        std::cout << "ScavTrap " << _Name << " has no energy points to repair itself!" << std::endl;
}

void    ScavTrap::guardGate() {
    if (!_hitPts)
        std::cout << "ScavTrap " << _Name << " is dead and cannot guard the gate!" << std::endl;
    else if (!_guardingGate) {
        std::cout << "ScavTrap " << _Name << " is now guarding the gate!" << std::endl;
        _guardingGate = 1;
    }
    else
        std::cout << "ScavTrap " << _Name << " is already guarding the gate!" << std::endl;
}
