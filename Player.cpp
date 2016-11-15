#include "Player.h"
#include "Team.h"
#include "Hobby.h"

std::shared_ptr<Player> Player::makeWithoutTeam(std::string const &name) {
    return std::shared_ptr<Player>(new Player(name));
}

Player::Player(std::string const &name)
    : name(name) {}

std::string Player::getName() {
    return name;
}

void Player::addTeam(std::shared_ptr<Team> team) {
    teams.insert(team);
    team->playerCallback(shared_from_this());
}

void Player::teamCallback(std::shared_ptr<Team> team) {
    teams.insert(team);
}

void Player::addHobby(std::shared_ptr<Hobby> hobby) {
    hobbys.insert(hobby);
    hobby->playerCallback(shared_from_this());
}

void Player::hobbyCallback(std::shared_ptr<Hobby> hobby) {
    hobbys.insert(hobby);
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
