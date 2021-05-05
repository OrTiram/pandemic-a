#pragma once
#include "City.hpp"
#include <iostream>



namespace pandemic{
 class Board{

     public:
      Board();
      int level_des;
      int& operator[](City city);
      friend std::ostream& operator<<(std::ostream& output,const Board& board);
      bool is_clean();
      void remove_cures();

 };
}