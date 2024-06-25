#pragma once 
#include "ASpell.hpp"
#include <map>

class SpellBook {
	private:
		SpellBook	&operator=(const SpellBook &other);
		SpellBook(const SpellBook &other);

		std::map<std::string, ASpell *> _SpellBook;
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell *spell);
		void	forgetSpell(const std::string &spellName);
		ASpell	*createSpell(const std::string &spellName);
};