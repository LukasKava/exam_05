#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <map>
//#include <utility>      // std::pair, std::make_pair

class Warlock {
	private:
		std::string _name;
		std::string _title;
		SpellBook	_SpellBook;
		

		Warlock();
		Warlock &operator=(const Warlock &other);
		Warlock(const Warlock &other);

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName(void) const;
		const std::string &getTitle(void) const;

		void setTitle(const std::string &title);

		void introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(const std::string &spell_name);
		void	launchSpell(const std::string &spell_name, const ATarget &target);
};