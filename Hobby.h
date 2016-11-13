#pragma once

#include <string>
#include <set>
#include <memory>
#include <iostream>

class Player;

class Hobby : public std::enable_shared_from_this<Hobby> {
    std::string name;
    std::set<std::shared_ptr<Player>> players;

public:
    Hobby(std::string name);
    std::string getName();
    void addPlayer(std::shared_ptr<Player> player, bool callback=false);
    friend std::ostream& operator<<(std::ostream &output, const Hobby &team);
};

std::ostream& operator<<(std::ostream &output, const Hobby &team);
