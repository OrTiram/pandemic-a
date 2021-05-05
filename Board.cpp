#include "Board.hpp"
#include "City.hpp"
#include <iostream>

using namespace std;

namespace pandemic{
    
    Board::Board(){}
    int& Board::operator[](City city){return this->level_des;}
    ostream& operator<<(ostream& output,const Board& board){return output << "pandemic" << endl;}
    bool Board::is_clean(){return true;}
    void Board::remove_cures(){}

}