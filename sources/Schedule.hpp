#ifndef EX5_PARTA_NODE_H
#define EX5_PARTA_NODE_H

#endif //EX5_PARTA_NODE_H
#pragma once
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"

using namespace std;
namespace ariel{
    class Schedule{
    public:
        vector<Team*> allTeams;

        Schedule(vector<Team*> gameSet){
            this->allTeams = gameSet;
        }
        ~Schedule(){}

        vector<Game*> makeSchedule (){
            vector<Game*> schedule;
            for (unsigned int i = 0; i < this->allTeams.size(); ++i) {
                for (unsigned int j = i; j < this->allTeams.size(); ++j) {
                    if(i==j){
                        continue;
                    }
                    schedule.push_back(new Game(this->allTeams.at(i), this->allTeams.at(j)));
                }
            }
            for (unsigned int i = 0; i < this->allTeams.size(); ++i) {
                for (unsigned int j = i; j < this->allTeams.size(); ++j) {
                    if(i==j){
                        continue;
                    }
                    schedule.push_back(new Game(this->allTeams.at(j), this->allTeams.at(i)));
                }
            }
            return schedule;
        }
    };
}
