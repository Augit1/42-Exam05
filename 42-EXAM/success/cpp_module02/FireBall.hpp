#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class FireBall : public ASpell
{
	public:
		FireBall();
		virtual ~FireBall();

		virtual ASpell* clone() const;
};

#endif
