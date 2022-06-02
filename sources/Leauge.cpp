#include <iostream>
#include "Leauge.hpp"
int const MAXTEAMS = 20;
double const EPS = 0.0001;
using namespace std;

namespace ariel{

    Leauge::Leauge(){
        this->leaugeEnd = false;
        for (int i = 0; i < MAXTEAMS; ++i) {
            this->allTeams.push_back(new Team(to_string(i),0.5));
        }
    }
    Leauge::Leauge(vector<Team*> teams){
        if (teams.size()>20){
            throw invalid_argument("Too much teams\n");
        }
        this->leaugeEnd = false;
        for (unsigned int i = 0; i < teams.size(); ++i) {
            this->allTeams.push_back(teams.at(i));
        }
        int i = 0;
        while(teams.size() < MAXTEAMS){
            this->allTeams.push_back(new Team(to_string(i),0.5));
            i++;
        }
    }

    Leauge::~Leauge() {
        for (int i = (int)allTeams.size() - 1; i >= 0; --i) {
            delete allTeams.at((unsigned int)i);
        }
    }

    void Leauge::startLeauge(){
        Schedule* sch = new Schedule(this->allTeams);
        vector<Game*> games = sch->makeSchedule();
        for (unsigned int i = 0; i < games.size(); ++i) {
            games.at(i)->startGame();
        }
        this->leaugeEnd = true;
        fixLeauge();

    }

    void Leauge::fixLeauge(){
        if (!this->leaugeEnd){
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        for (unsigned int i = 0; i < MAXTEAMS; ++i) {
            this->allTeams.at(i)->score = this->allTeams.at(i)->wins + EPS*(this->allTeams.at(i)->scorePts -this->allTeams.at(i)->sufferedPts);
        }
        for (size_t i = 0; i < this->allTeams.size() - 1; ++i) {
            for (size_t j = 0; j < this->allTeams.size() - i - 1; ++j) {
                if (this->allTeams.at(j)->score < this->allTeams.at(j + 1)->score)
                    std::swap(this->allTeams.at(j), this->allTeams.at(j + 1));
            }
        }
    }
    void Leauge::printLeauge(int limit){
        if (!this->leaugeEnd){
            throw invalid_argument("Cant do leauge functions as long as leauge didnt start\n");
        }
        std::cout << "Leauge Ranking" << std::endl;
        for (unsigned int i = 0; i < limit; ++i) {
            std::cout << i+1 << ") " << this->allTeams.at(i)->name << " Wins-Loses: " << this->allTeams.at(i)->wins
                      << "-" << this->allTeams.at(i)->loses << ". Score-Suffer: " << this->allTeams.at(i)->scorePts << "-"
                      << this->allTeams.at(i)->sufferedPts << ". TOTAL SCORE: " << this->allTeams.at(i)->score << std::endl;
        }
        int maxWINS = 0;
        Team* maxWin;
        int maxLOSES = 0;
        Team* maxLose;
        for (unsigned int i = 0; i < MAXTEAMS; ++i){
            if(this->allTeams.at(i)->winSpree_max > maxWINS){
                maxWINS = this->allTeams.at(i)->winSpree_max;
                maxWin = this->allTeams.at(i);
            }
            if(this->allTeams.at(i)->loseSpree_max > maxLOSES){
                maxLOSES = this->allTeams.at(i)->loseSpree_max;
                maxLose = this->allTeams.at(i);
            }
        }
        std::cout << "Most wins spree by " << maxWin->name << " with: " << maxWINS << " spree wins!" << std::endl;
        std::cout << "Most loses spree by " << maxLose->name << " with: " << maxLOSES << " spree loses!" << std::endl;
        std::cout << "Teams that scored more than they suffered:" << std::endl;
        for (unsigned int i = 0; i < MAXTEAMS; ++i) {
            if(this->allTeams.at(i)->scorePts - this->allTeams.at(i)->sufferedPts > 0){
                std::cout << this->allTeams.at(i)->name << " with: " <<this->allTeams.at(i)->scorePts << ":" <<this->allTeams.at(i)->sufferedPts << std::endl;
            }
        }
    }

}