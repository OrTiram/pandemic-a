#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>




namespace pandemic{
 class Medic: public Player{
    public:
       Medic(Board b , City c);
 };
}
