#pragma once

#include <string>
#include <set>
#include <memory>
#include <iostream>
#include <utility>

class Player;

class Team : public std::enable_shared_from_this<Team> {
    std::string name;
    std::set<std::shared_ptr<Player>> players;
    Team(std::string name, std::shared_ptr<Player> firstPlayer);

public:
    static auto createWithNewPlayer(std::string teamName, std::string playerName) -> std::pair<std::shared_ptr<Team>, std::shared_ptr<Player>>;
    std::string getName();
    void addPlayer(std::shared_ptr<Player> player);
    std::shared_ptr<Player> addNewPlayer(std::string name);
	void playerCallback(std::shared_ptr<Player> player);

    friend class Player;
    friend std::ostream& operator<<(std::ostream &output, const Team &team);
};

std::ostream& operator<<(std::ostream &output, const Team &team);
