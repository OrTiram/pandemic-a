#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>


namespace pandemic{
 class Scientist:public Player{
    public:
       Scientist(Board b , City c,int n);
 };
}
