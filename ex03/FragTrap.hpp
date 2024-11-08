#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class   FragTrap: virtual public ClapTrap {

public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap(const FragTrap& src);
    FragTrap& operator=(const FragTrap& src);
    ~FragTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    highFivesGuys(void);

};

#endif