#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		std::string	name;
		std::string	effects;

		ASpell(const std::string& name, const std::string& effects);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell* clone() const = 0;

		void	launch(const ATarget& target) const;
};

#endif
