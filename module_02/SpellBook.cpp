#include "SpellBook.hpp"

SpellBook	&SpellBook::operator=(const SpellBook &other) {
	_SpellBook = other._SpellBook;
	return (*this);
}

SpellBook::SpellBook(const SpellBook &other) {
	*this = other;
}

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell *>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); it ++) {
		delete it->second;
	}
	_SpellBook.clear();
}

void	SpellBook::learnSpell(ASpell *spell) {
	if (spell) {
		_SpellBook[spell->getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(const std::string &spellName) {
	std::map<std::string, ASpell *>::iterator it = _SpellBook.find(spellName);
	if (it != _SpellBook.end()) {
		delete it->second;
		_SpellBook.erase(it);
	}
}

ASpell	*SpellBook::createSpell(const std::string &spellName) {
	ASpell	*tmp = NULL;
	if (_SpellBook.find(spellName) != _SpellBook.end()) {
		tmp = _SpellBook[spellName];
	}
	return (tmp);
}