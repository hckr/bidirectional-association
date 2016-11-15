#include "Team.h"
#include "Player.h"

Team::Team(std::string name, std::shared_ptr<Player> firstPlayer)
    : name(name), players()
{
    players.insert(firstPlayer);
}

auto Team::createWithNewPlayer(std::string teamName, std::string playerName) -> std::pair<std::shared_ptr<Team>, std::shared_ptr<Player>> {
    auto unfinishedPlayer = Player::makeWithoutTeam(playerName);
    auto team = std::shared_ptr<Team>(new Team(teamName, unfinishedPlayer));
    unfinishedPlayer->teamCallback(team);
    return { team, unfinishedPlayer };
}

std::string Team::getName() {
    return name;
}

void Team::addPlayer(std::shared_ptr<Player> player) {
    players.insert(player);
    player->teamCallback(shared_from_this());
}

std::shared_ptr<Player> Team::addNewPlayer(std::string name) {
    auto unfinishedPlayer = Player::makeWithoutTeam(name);
    players.insert(unfinishedPlayer);
    unfinishedPlayer->teamCallback(shared_from_this());
    return unfinishedPlayer;
}

void Team::playerCallback(std::shared_ptr<Player> player) {
    players.insert(player);
}

std::ostream& operator<<(std::ostream &output, const Team &team) {
    output << "*** Team " + team.name + " ***\n";
    output << "Players:\n";
    for(auto &player : team.players) {
        output << player->getName() << "\n";
    }
    return output;
}
