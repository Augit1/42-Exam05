#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {
private:
    std::string name;
    std::string title;

    // Suppression du constructeur par défaut et du constructeur de copie
    Warlock();
    Warlock(const Warlock& other);
    Warlock& operator=(const Warlock& other);

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);

    void introduce() const;
};

#endif
