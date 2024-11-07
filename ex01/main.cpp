#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
    std::cout << "=========== ClapTrap Tests ===========" << std::endl;
    ClapTrap    c0;
    ClapTrap    c1("Jim");

    for (int i = 0; i < 11; i++)
        c1.attack("a random ClapTrap");
    for (int i = 0; i < 11; i++)
        c1.beRepaired(1);
    c1.takeDamage(10);
    c1.takeDamage(11);
    c1.takeDamage(1);
    c1.beRepaired(1);
    c1.attack("someone");
    std::cout << std::endl;

    std::cout << "=========== ScavTrap Tests ===========" << std::endl;
    ScavTrap    s0;
    ScavTrap    s1("Jim");

    for (int i = 0; i < 1; i++)
        s1.attack("a random ClapTrap");
    for (int i = 0; i < 50; i++)
        s1.beRepaired(1);
    s1.takeDamage(100);
    s1.guardGate();
    s1.guardGate();
    s1.takeDamage(49);
    s1.beRepaired(1);
    s1.attack("someone");
    return 0;
}