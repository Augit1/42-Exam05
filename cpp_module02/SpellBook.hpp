#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <string>
# include <map>
# include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	spells;

		SpellBook(const SpellBook& other);
		SpellBook&	operator=(const SpellBook& other);
	
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell* spell);
		void	forgetSpell(const SpellBook& other);
		ASpell*	createSpell(const std::string& spellName);
};

#endif
