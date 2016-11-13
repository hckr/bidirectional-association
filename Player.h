#pragma once

#include <string>
#include <set>
#include <memory>
#include <iostream>

class Team;
class Hobby;

class Player : public std::enable_shared_from_this<Player> {
    std::string name;
    std::set<std::shared_ptr<Team>> teams;
    std::set<std::shared_ptr<Hobby>> hobbys;
public:
    Player(std::string name);
    std::string getName();
    void addTeam(std::shared_ptr<Team> team, bool callback=false);
    void addHobby(std::shared_ptr<Hobby> hobby, bool callback=false);
    friend std::ostream& operator<<(std::ostream &output, const Player &player);
};

std::ostream& operator<<(std::ostream &output, const Player &player);
