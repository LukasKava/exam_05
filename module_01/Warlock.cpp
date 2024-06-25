#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock	&Warlock::operator=(const Warlock &other) { this->_name = other._name; this->_title = other._title; return (*this);}

Warlock::Warlock(const Warlock &other) { *this = other; }

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title) {
	std::cout << _name + ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() { std::cout << _name + ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell *>::iterator it  = _spells.begin(); it != _spells.end(); ++it){
		delete it->second;
	}
	_spells.clear();
}

const std::string &Warlock::getName(void) const { return (_name);}
const std::string &Warlock::getTitle(void) const { return (_title);}

void Warlock::setTitle(const std::string &title) { this->_title = title;}

void Warlock::introduce() const { std::cout << _name + ": I am " + _name + ", " + _title + "!" << std::endl;}

void	Warlock::learnSpell(ASpell *spell) {
	if  (spell) {
		if (_spells.find(spell->getName()) == _spells.end()) {
			_spells[spell->getName()] = spell->clone();
		}
		//_spells.insert(std::make_pair(spell->getName(), spell->clone()));
	}
}

void	Warlock::forgetSpell(std::string &spell_name) {
	if (_spells.find(spell_name) != _spells.end()) {
		_spells.erase(_spells.find(spell_name));
	}
}

void	Warlock::launchSpell(std::string &spell_name, const ATarget &target) {
	if (_spells.find(spell_name) != _spells.end()) {
		_spells[spell_name]->launch(target);
	}
}