#include <memory>
#include <utility>

#include "Team.h"
#include "Player.h"
#include "Hobby.h"

int main() {
    auto result = Team::createWithNewPlayer("t1", "p1");
    auto t1 = result.first;
    auto p1 = result.second;
    auto p2 = t1->addNewPlayer("p2");

    auto result2 = Team::createWithNewPlayer("t2", "p3");
    auto t2 = result2.first;
    auto p3 = result2.second;

    auto h1 = std::make_shared<Hobby>("h1");
    auto h2 = std::make_shared<Hobby>("h2");

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
