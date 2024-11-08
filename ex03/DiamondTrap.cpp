#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
    _hitPts = FragTrap::_hitPts;
	_energyPts = ScavTrap::_energyPts,
    _attackDmg = FragTrap::_attackDmg,
    std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name): ClapTrap(Name + "_clap_name"), ScavTrap(), FragTrap() {
	ScavTrap::_Name = Name;
	FragTrap::_Name = Name;
    _Name = Name;
	_hitPts = FragTrap::_hitPts;
	_energyPts = ScavTrap::_energyPts,
    _attackDmg = FragTrap::_attackDmg,
    std::cout << "DiamondTrap: Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap: Copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
    std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
    if (this != &src) {
        this->_Name = src._Name;
		this->ClapTrap::_Name = src.ClapTrap::_Name;
        this->_hitPts = src._hitPts;
        this->_energyPts = src._energyPts;
        this->_attackDmg = src._attackDmg;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void    DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
    std::cout << "Who am I? I AM " << _Name << ", DESCENDANT OF " << ClapTrap::_Name << "!!!" << std::endl;
	std::cout << "I have " << _hitPts << " hit points and " << _energyPts << " energy points." << std::endl;
}
