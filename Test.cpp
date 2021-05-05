#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace pandemic;
using namespace std;



TEST_CASE("Working Test:"){
    cout << boolalpha;
	Board board;

    Player player1(board, City::SaoPaulo);
    OperationsExpert player2(board, City::NewYork);

    CHECK(board.is_clean());
    board[City::Lima] = 2;
    CHECK(!board.is_clean());
    board[City::Lima] = 0;
    CHECK(board.is_clean());
    CHECK_THROWS(player1.drive(City::BuenosAires));
    CHECK_THROWS(player1.drive(City::Algiers));
    CHECK_THROWS(player1.fly_direct(City::Madrid));
    CHECK_THROWS(player1.fly_charter(City::Montreal));
    CHECK_THROWS(player1.fly_shuttle(City::Essen));

    player1.take_card(City::Madrid);
	player1.take_card(City::Montreal);
	player1.take_card(City::Essen);
	player1.take_card(City::Milan);
	player1.take_card(City::Delhi);

    CHECK_NOTHROW(player1.fly_direct(City::Madrid));
    CHECK_NOTHROW(player1.fly_direct(City::Montreal));
    CHECK_NOTHROW(player1.fly_direct(City::Essen));
    CHECK_NOTHROW(player1.fly_direct(City::Milan));
    CHECK_NOTHROW(player1.fly_direct(City::Delhi));
    
    CHECK_NOTHROW(player2.drive(City::Washington));
    CHECK_NOTHROW(player2.drive(City::Montreal));
    CHECK_NOTHROW(player2.build());

    FieldDoctor player3(board,City::Delhi);
    CHECK_NOTHROW(player3.treat(City::Kolkata));

    Virologist player4(board,City::MexicoCity);
    CHECK_THROWS(player4.treat(City::Washington));
    board[City::HongKong]=1;

    Researcher player5(board,City::Delhi);
    CHECK_THROWS(player5.discover_cure(Color::Blue));
    board[City::Bangkok]=1;
    CHECK_NOTHROW(player5.discover_cure(Color::Blue));

    CHECK_EQ(player2.role(),"OperationsExpert");
    CHECK_EQ(player3.role(),"FieldDoctor");
    CHECK_EQ(player4.role(),"Virologist");
    CHECK_EQ(player5.role(),"Researcher");

}
