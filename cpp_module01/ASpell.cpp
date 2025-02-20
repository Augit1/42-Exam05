#include "ASpell.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects) : name(name), effects(effects) {}

ASpell::~ASpell() {}

std::string	ASpell::getName() const
{
	return this->name;
}

std::string	ASpell::getEffects() const
{
	return this->effects;
}

void	ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
