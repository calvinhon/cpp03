#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class   DiamondTrap: public ScavTrap, public FragTrap {

public:
	DiamondTrap();
	DiamondTrap(std::string Name);
	DiamondTrap(const DiamondTrap& src);
	DiamondTrap& operator=(const DiamondTrap& src);
	~DiamondTrap();

    void    attack(const std::string& target);
	void	whoAmI();

private:
    std::string 	_Name;

};

#endif