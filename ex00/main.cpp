#include "ClapTrap.hpp"

int main(void){
    ClapTrap    c0;
    ClapTrap    c1("Jim");

    std::cout << "=========== ClapTrap Tests ===========" << std::endl;
    for (int i = 0; i < 11; i++)
        c1.attack("a random ClapTrap");
    for (int i = 0; i < 11; i++)
        c1.beRepaired(1);
    c1.takeDamage(10);
    c1.takeDamage(11);
    c1.takeDamage(1);
    c1.beRepaired(1);
    c1.attack("someone");
    return 0;
}