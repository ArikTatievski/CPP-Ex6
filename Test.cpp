#include "doctest.h"
#include "sources/Leauge.hpp"
using namespace ariel;
TEST_CASE("Teams tests"){
    std::vector<Team*> myTeam;
    CHECK_THROWS(myTeam.push_back(new Team("",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\r",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\n",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\t",0)));
    CHECK_THROWS(myTeam.push_back(new Team("\r",0)));
    CHECK_THROWS(myTeam.push_back(new Team(" ",0)));
    CHECK_NOTHROW(myTeam.push_back(new Team("Arik",0)));
    CHECK_NOTHROW(myTeam.push_back(new Team("OdArik",0.1)));
    CHECK_NOTHROW(myTeam.push_back(new Team("MaleArik",0.2)));
    CHECK_NOTHROW(myTeam.push_back(new Team("Arikim",0.3)));
    CHECK_NOTHROW(myTeam.push_back(new Team("YoterMidayArik",0.005)));
    CHECK_NOTHROW(myTeam.push_back(new Team("TovArikAharon",1)));
    CHECK_NOTHROW(myTeam.push_back(new Team("UlayOdArik",0.9999)));
    CHECK_NOTHROW(myTeam.push_back(new Team("OdArikKedeyLeashlimLe20Testim",0.65)));
    CHECK_NOTHROW(myTeam.push_back(new Team("ArikBiglalMaSheRashumLemala",0.77)));
    CHECK_NOTHROW(myTeam.push_back(new Team("ArikRagilBliHafir",0.123456)));
    CHECK_THROWS(myTeam.push_back(new Team("ArikLoTov",-1)));
    CHECK_THROWS(myTeam.push_back(new Team("ArikLoTov",1.1)));

}
TEST_CASE("Test Leauge"){
    vector<Team*> myTeams;
    myTeams.push_back(new Team("Golden State Warriors", 1));
    myTeams.push_back(new Team("Boston Celtics", 0.4));
    myTeams.push_back(new Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new Team("Denver Nuggets", 0.3));
    myTeams.push_back(new Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new Team("Chicago Bulls", 0.3));
    myTeams.push_back(new Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new Team("LA Clippers", 0.5));
    myTeams.push_back(new Team("Los Angeles Lakers", 1));
    myTeams.push_back(new Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new Team("Miami Heat", 0.6));
    myTeams.push_back(new Team("Phoenix Suns", 0.8));
    myTeams.push_back(new Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new Team("Utah Jazz", 0.3));
    myTeams.push_back(new Team("Washington Wizards", 0));
    myTeams.push_back(new Team("Oklahoma City Thunder", 0.1));
    Leauge* l = new Leauge(myTeams);
    CHECK_THROWS(l->printLeauge(5));
    l->startLeauge();
    CHECK_NOTHROW(l->printLeauge(5));
}