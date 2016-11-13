#include "Team.h"
#include "Player.h"

Team::Team(std::string name) {
    this->name = name;
}

std::string Team::getName() {
    return name;
}

void Team::addPlayer(std::shared_ptr<Player> player, bool callback) {
    players.insert(player);
    if(!callback) player->addTeam(shared_from_this(), true);
}

std::ostream& operator<<(std::ostream &output, const Team &team) {
    output << "*** Team " + team.name + " ***\n";
    output << "Players:\n";
    for(auto &player : team.players) {
        output << player->getName() << "\n";
    }
    return output;
}
