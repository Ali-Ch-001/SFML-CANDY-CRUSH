#include"Bonous_Manager.h"

Bonous_manager::Bonous_manager()
{
	font.loadFromFile("Fonts/MAGNETOB.TTF");

	text_bonous.setFont(font);
	text_bonous.setCharacterSize(20);

	text_bonous.setColor(sf::Color::Black);
	text_bonous.Bold;
	text_bonous.Italic;

	bonous = -1;
}
int  Bonous_manager::Get_curr_bonous()
{
	return bonous;
}
void Bonous_manager::increment()
{
	bonous++;
}
void Bonous_manager::start_again()
{
	bonous = -1;
}
void Bonous_manager::draw_bonous_at(RenderWindow& window,string bonous_str)
{
	string temp = "+";
	temp += bonous_str;

	text_bonous.setString(temp);
	
	
	window.draw(text_bonous);
   
}