#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif //EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <string.h>

namespace ariel{
    class Team{
    public:
        std::string name;
        double talent;
        int wins;
        int loses;
        int winSpree_curr;
        int winSpree_max;
        int loseSpree_curr;
        int loseSpree_max;
        bool teamStatus;
        double score;
        int scorePts;
        int sufferedPts;

        Team(std::string teamName,double teamTalent){
            if (teamName == "\t" || teamName == "\n" || teamName.empty() || teamName == " " || teamName == "\r"){
                throw std::invalid_argument("Invalid team name\n");
            }
            if (teamTalent<0 || teamTalent>1){
                throw std::invalid_argument("Invalid talent range(Must be in range of [0,1])\n");
            }
            this->name = teamName;
            this->talent = teamTalent;
            this->winSpree_max = 0;
            this->winSpree_curr = 0;
            this->loseSpree_curr = 0;
            this->loseSpree_max = 0;
            this->wins = 0;
            this->loses = 0;
            this->scorePts = 0;
            this->sufferedPts = 0;
        }
        ~Team(){

        }
        bool operator==(const Team& other) const {
            return name == other.name;
        }

        bool operator!=(const Team& other) const {
            return name != other.name;
        }
    };
}
