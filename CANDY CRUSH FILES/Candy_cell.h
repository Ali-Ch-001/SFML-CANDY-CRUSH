#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include<SFML\Audio.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>  
#include <time.h>       /* time */
#include <windows.h>
using namespace std;
using namespace sf;

class Candy_cell
{

public:                                           
	Sprite s;
	string candy_name;
	Texture t;
	char type;                                      // A, or D  Activate or Deactivae
};
