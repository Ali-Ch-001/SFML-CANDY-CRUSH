#include <SFML\Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Texture_Data
{

 public:
	sf::Texture effectt;
	sf::Sprite effec;

	sf::RectangleShape rectangle;
	sf::Texture background;

	sf::Texture explosion;

	sf::Sprite exp1;

	sf::Font font;
	sf::Text text_score;

	Texture_Data();

};