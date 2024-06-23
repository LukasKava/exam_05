#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects): _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell &other) { *this = other;}
ASpell	&ASpell::operator=(const ASpell &other) { this->_name = other.getName(); this->_effects = other.getEffects(); return (*this);}

std::string	ASpell::getName(void) const { return (_name);}
std::string	ASpell::getEffects(void) const { return (_effects);}

void ASpell::launch(const ATarget &target) const { target.getHitBySpell(*this);}

ASpell::~ASpell() {
	
}