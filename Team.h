#pragma once

#include <string>
#include <set>
#include <memory>
#include <iostream>

class Player;

class Team : public std::enable_shared_from_this<Team> {
    std::string name;
    std::set<std::shared_ptr<Player>> players;

public:
    Team(std::string name);
    std::string getName();
    void addPlayer(std::shared_ptr<Player> player, bool callback=false);
    friend std::ostream& operator<<(std::ostream &output, const Team &team);
};

std::ostream& operator<<(std::ostream &output, const Team &team);
