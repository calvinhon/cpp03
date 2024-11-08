#include "ClapTrap.hpp"

int main(void){
    std::cout << "=========== ClapTrap Tests ===========" << std::endl;
    ClapTrap    c0;
    ClapTrap    c1("Jim");

    for (int i = 0; i < 11; i++)
		c1.attack("a random ClapTrap");
	c1.beRepaired(1);
    c1.takeDamage(10);
    c1.takeDamage(11);
    c1.beRepaired(1);
    c1.attack("someone");
    return 0;
}