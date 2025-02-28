#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		std::string type;

		ATarget(const std::string& type);
		virtual ~ATarget();

		std::string	getType() const;

		virtual ATarget* clone() const = 0;

		void	getHitBySpell(const ASpell& spell) const;
};

#endif
