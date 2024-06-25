#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string	_name;
		std::string	_effects;
		ASpell();
	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell();

		ASpell(const ASpell &other);
		ASpell	&operator=(const ASpell &other);

		std::string	getName(void) const;
		std::string	getEffects(void) const;

		virtual	ASpell	*clone()  const = 0;

		void launch( const ATarget &target) const;

};