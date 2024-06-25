#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock	&Warlock::operator=(const Warlock &other) { this->_name = other._name; this->_title = other._title; return (*this);}

Warlock::Warlock(const Warlock &other) { *this = other; }

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title) {
	std::cout << _name + ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << _name + ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName(void) const { return (_name);}
const std::string &Warlock::getTitle(void) const { return (_title);}

void Warlock::setTitle(const std::string &title) { this->_title = title;}

void Warlock::introduce() const { std::cout << _name + ": I am " + _name + ", " + _title + "!" << std::endl;}

void	Warlock::learnSpell(ASpell *spell) {
	_SpellBook.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell_name) {
	_SpellBook.forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, const ATarget &target) {
	if (_SpellBook.createSpell(spell_name)) {
		_SpellBook.createSpell(spell_name)->launch(target);
	}
}