#include "FragTrap.hpp"

FragTrap::FragTrap():
    ClapTrap() {
    _energyPts = 100,
    _attackDmg = 30,
    std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name): 
    ClapTrap(Name) {
    _energyPts = 100,
    _attackDmg = 30,
    std::cout << "FragTrap: Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src) {
    std::cout << "FragTrap: Copy constructor called" << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
    std::cout << "FragTrap: Copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_Name = src._Name;
        this->_hitPts = src._hitPts;
        this->_energyPts = src._energyPts;
        this->_attackDmg = src._attackDmg;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: Destructor called" << std::endl;
}

void    FragTrap::attack(const std::string& target) {
    if (_energyPts && _hitPts) {
        _energyPts--;
        std::cout << "FragTrap " << _Name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << std::endl;
    }
    else if (!_hitPts)
        std::cout << "FragTrap " << _Name << " is dead and cannot attack!" << std::endl;
    else
        std::cout << "FragTrap " << _Name << " has no energy points to attack!" << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount) {
    if (_hitPts) {
        if (amount > _hitPts)
            amount = _hitPts;
        _hitPts -= amount;
        std::cout << "FragTrap " << _Name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "FragTrap " << _Name << " is dead and cannot take damage!" << std::endl;
}

void    FragTrap::beRepaired(unsigned int amount) {
    if (_energyPts && _hitPts) {
        _energyPts--;
        _hitPts += amount;
        std::cout << "FragTrap " << _Name << " repairs itself for " << amount << " hit point";
        if (amount > 1)
            std::cout << "s!" << std::endl;
        else
            std::cout << "!" << std::endl;
    }
    else if (!_hitPts)
        std::cout << "FragTrap " << _Name << " is dead and cannot repair itself!" << std::endl;
    else
        std::cout << "FragTrap " << _Name << " has no energy points to repair itself!" << std::endl;
}

void    FragTrap::highFivesGuys(void) {
    if (_hitPts)
        std::cout << "FragTrap " << _Name << " requests high fives!" << std::endl;
    else
        std::cout << "FragTrap " << _Name << " is dead and cannot request high fives!" << std::endl;
}

