#include "Player.h"
#include "Team.h"
#include "Hobby.h"

Player::Player(std::string name) {
    this->name = name;
}

std::string Player::getName() {
    return name;
}

void Player::addTeam(std::shared_ptr<Team> team, bool callback) {
    teams.insert(team);
    if(!callback) team->addPlayer(shared_from_this(), true);
}

void Player::addHobby(std::shared_ptr<Hobby> hobby, bool callback) {
    hobbys.insert(hobby);
    if(!callback) hobby->addPlayer(shared_from_this(), true);
}

std::ostream& operator<<(std::ostream &output, const Player &player) { 
    output << "*** Player " + player.name + " ***\n";
    output << "Teams:\n";
    for(auto &team : player.teams) {
        output << team->getName() << "\n";
    }
    output << "Hobbys:\n";
    for(auto &hobby : player.hobbys) {
        output << hobby->getName() << "\n";
    }
    return output;
}
