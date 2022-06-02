#ifndef EX5A_ITERATOR_H
#define EX5A_ITERATOR_H

#endif //EX5A_ITERATOR_H
#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Team.hpp"

namespace ariel{
    class Game{
    public:
        Team* home;
        Team* away;

        Game(Team* a,Team* b){
            this->home = a;
            this->away = b;
        }
        ~Game(){}

        int randNum(int A, int B){
            int r = (rand()%(B-A)) + A;
            return r;
        }

        Team* startGame(){
            int homeRand = randNum(55,100);
            int awayRand = randNum(50,100);
            homeRand += (int)(this->home->talent * 10);
            awayRand += (int)(this->away->talent * 10);
            this->home->scorePts+=(homeRand);
            this->home->sufferedPts+=(awayRand);
            this->away->scorePts+=(awayRand);
            this->away->sufferedPts+=(homeRand);
            if(homeRand>=awayRand){
                this->home->teamStatus = true;
                this->home->loseSpree_curr = 0;
                this->home->winSpree_curr+=1;
                this->home->wins+=1;
                if (this->home->winSpree_curr > this->home->winSpree_max){
                    this->home->winSpree_max = this->home->winSpree_curr;
                }
                this->away->teamStatus = false;
                this->away->winSpree_curr = 0;
                this->away->loseSpree_curr+=1;
                this->away->loses+=1;
                if (this->away->loseSpree_curr > this->away->loseSpree_max){
                    this->away->loseSpree_max = this->away->loseSpree_curr;
                }
                std::cout << this->home->name << " Won " << this->away->name << " "
                << homeRand << ":" << awayRand << std::endl;
                return this->home;
            }
            this->away->teamStatus = true;
            this->away->loseSpree_curr = 0;
            this->away->winSpree_curr+=1;
            this->away->wins+=1;
            if (this->away->winSpree_curr > this->away->winSpree_max){
                this->away->winSpree_max = this->away->winSpree_curr;
            }
            this->home->teamStatus = false;
            this->home->winSpree_curr = 0;
            this->home->loseSpree_curr+=1;
            this->home->loses+=1;
            if (this->home->loseSpree_curr > this->home->loseSpree_max){
                this->home->loseSpree_max = this->home->loseSpree_curr;
            }
            std::cout << this->away->name << " Won " << this->home->name << " "
            << awayRand << ":" << homeRand << std::endl;
            return this->away;
        }
    };
}
