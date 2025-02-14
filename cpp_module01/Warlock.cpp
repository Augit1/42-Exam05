#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;

    for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it)
        delete it->second;
    spells.clear();
}

const std::string& Warlock::getName() const {
    return this->name;
}

const std::string& Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(const std::string& newTitle) {
    this->title = newTitle;
}

void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
    if (it != spells.end())
	{
        delete it->second;
        spells.erase(it);
    }
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target) 
{
    std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
    if (it != spells.end())
        it->second->launch(target);
}
