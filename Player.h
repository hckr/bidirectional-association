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
    static std::shared_ptr<Player> makeWithoutTeam(std::string const &name);
    Player(std::string const &name);

public:
    std::string getName();
    void addTeam(std::shared_ptr<Team> team);
    void teamCallback(std::shared_ptr<Team> team);
    void addHobby(std::shared_ptr<Hobby> hobby);
    void hobbyCallback(std::shared_ptr<Hobby> hobby);

    friend Team;
    friend std::ostream& operator<<(std::ostream &output, const Player &player);
};

std::ostream& operator<<(std::ostream &output, const Player &player);
