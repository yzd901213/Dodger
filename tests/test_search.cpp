
#include <iostream>
#include <iterator>
#include <list>
#include "point.hpp"
#include "roadmap.hpp"
#include "rmgenerator.hpp"
#include "model.hpp"
#include "agent.hpp"
#include "path.hpp"
#include "search.hpp"

int main() {

    double speed = 2;
    double wait_time = 0.1;
    std::list<Agent> agents;

    Agent ag(
        new SinModel(2, 1, 1, 2),
        new LinearModel(0, 1));

    Agent ag2(
        new SinModel(-2, 2, 1, 2),
        new LinearModel(0, 1.3));

    Agent ag3(
        new SinModel(2, 2.5, 1, 2),
        new LinearModel(0, 1.8));

    Agent ag4(
        new SinModel(-2, 3, 1, 2),
        new LinearModel(0, 2.1));

    Agent ag5(
        new SinModel(2, 5, 1, 2),
        new LinearModel(0, 2.5));

    Agent ag6(
        new SinModel(-2, 4, 1, 2),
        new LinearModel(0, 3));


    agents.push_back(ag);
    agents.push_back(ag2);
    agents.push_back(ag3);
    agents.push_back(ag4);
    agents.push_back(ag5);
    agents.push_back(ag6);

    Point start(2, 0);
    Point goal(2, 4);
    RoadmapGenerator rmgr(5, 5, start, 0.3);
    Roadmap rm = rmgr.generate(1000);

    Search search(rm, speed, wait_time);
    Path path = search.get_path(start, goal, agents);
    std::cout << Search::json(path, agents) << std::endl;

}