#include "FieldDoctor.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic{  
      
  FieldDoctor::FieldDoctor(Board b , City c): Player(b,c){}
}