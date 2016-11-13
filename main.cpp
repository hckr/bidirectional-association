#include "Team.h"
#include "Player.h"
#include "Hobby.h"

int main() {
    auto t1 = std::make_shared<Team>("t1");
    auto t2 = std::make_shared<Team>("t2");

    auto p1 = std::make_shared<Player>("p1");
    auto p2 = std::make_shared<Player>("p2");
    auto p3 = std::make_shared<Player>("p3");

    auto h1 = std::make_shared<Hobby>("h1");
    auto h2 = std::make_shared<Hobby>("h2");

    t1->addPlayer(p1);
    t1->addPlayer(p2);
    t2->addPlayer(p3);

    p1->addHobby(h1);
    p2->addHobby(h1);
    p2->addHobby(h2);
    p3->addHobby(h2);

    std::cout << *t1;
    std::cout << *t2;

    std::cout << *p1;
    std::cout << *p2;
    std::cout << *p3;

    std::cout << *h1;
    std::cout << *h2;
}
