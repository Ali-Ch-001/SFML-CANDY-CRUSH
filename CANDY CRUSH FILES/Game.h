#include "Board.h"

//class window_behaviour
//{
//
//public:
//	virtual void set_window(RenderWindow&) = 0;
//};
//
//class main_window :public window_behaviour
//{
//public:
//	void set_window(RenderWindow& window)
//	{
//	}
//};
//
//class board_window :public window_behaviour
//{
//	RenderWindow board;
//public:
//	board_window()
//	{}
//	void set_window(RenderWindow&  window)
//	{
//	
//	}
//};
//

class Game
{
private:
	Board  board;
public :
	Game();
	void Run();

};

Game::Game()
{

	board.load();

	board.draw();

	board.window.display();

	board.Check_board();

}

void Game::Run()
{
	while (board.window.isOpen())
	{
		board.window.clear();

		board.draw();

		board.Control_mouse_events(board.window);

		board.window.display();

	}

}

