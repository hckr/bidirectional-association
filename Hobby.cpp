#include "Hobby.h"
#include "Player.h"

Hobby::Hobby(std::string name) {
    this->name = name;
}

std::string Hobby::getName() {
    return name;
}

void Hobby::addPlayer(std::shared_ptr<Player> player) {
    players.insert(player);
    player->hobbyCallback(shared_from_this());
}

void Hobby::playerCallback(std::shared_ptr<Player> player) {
    players.insert(player);
}

std::ostream& operator<<(std::ostream &output, const Hobby &hobby) { 
    output << "*** Hobby " + hobby.name + " ***\n";
    output << "Players:\n";
    for(auto &player : hobby.players) {
        output << player->getName() << "\n";
    }
    return output;
}
