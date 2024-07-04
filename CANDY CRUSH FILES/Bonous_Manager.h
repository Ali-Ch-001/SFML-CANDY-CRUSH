#include <SFML\Graphics.hpp>
#include <string>
#include<Windows.h>
using namespace std;
using namespace sf;

class Bonous_manager
{
private:
	int bonous;
	sf::Font font;

public:
	Text text_bonous;
	Bonous_manager();
	void increment();
	int Get_curr_bonous();
	void start_again();
	void draw_bonous_at(RenderWindow & widow, string bonous_str);

};