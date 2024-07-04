#include "Board.h"

//void Board::set_swap_behaviour( )
//{
//
//	if (swap_make_chain)
//	{
//
//		Check_board();
//		swap_make_chain = false;
//
//		Bonous_m.start_again();
//	
//		swap_behaviour = new Not_swap_back(this);
//	}
//		
//
//	else
//	{
//		swap_behaviour = new swap_back(this);
//	}
//		
//
//}
//	swap_behaviour->swap();


string int_to_string(int n)
{
	stringstream ss;
	ss << n;
	string str = ss.str();
	return str;
}

int Board::Generate_candy()
{
	int random;
	random = rand() % 6;
	return random;

}

bool Board::valid_index_array(int r, int c)
{
	if (r >= 0 && r <= 7 && c >= 0 && c <= 4)
		return true;
	else 
		return false;
}


void Board::Generate_explosion_at(int cnt, char type, int r, int c)      // to do that at same time  draw this at all cell then dispaly  ;)) will run 
{

		for (int i = 1; i <= 5; i++)
		{
			int temp = 0;
			window.clear();
			draw();

			for (int j = 0; j < cnt; j++)
			{
				switch (i)
				{
				case 1:
				{
						  texture_data.explosion.loadFromFile("images/explosion/rsz_explosion01.png");
						  texture_data.exp1.setTexture(texture_data.explosion);
						  if (type == 'r')
						  texture_data.exp1.setPosition(c * 50 + temp + 255, r * 50 + 20);
						  else
							  texture_data.exp1.setPosition(c * 50 + 255, r * 50 + 20+temp);


						  window.draw(texture_data.exp1);
						 
						  temp += 50;
				}
					break;
				case 2:
				{ 
						  texture_data.explosion.loadFromFile("images/explosion/rsz_explosion02.png");
						  if (type == 'r')
						  texture_data.exp1.setPosition(c * 50 + temp + 255, r * 50 + 20);
						  else
							  texture_data.exp1.setPosition(c * 50 + 255, r * 50 + 20 + temp);

						  window.draw(texture_data.exp1);

						  temp += 50;

				}
					break;
				case 3:
				{ 
						  texture_data.explosion.loadFromFile("images/explosion/rsz_explosion03.png");
						  if (type == 'r')
						  texture_data.exp1.setPosition(c * 50 + temp + 255, r * 50 + 20);
						  else
							  texture_data.exp1.setPosition(c * 50 + 255, r * 50 + 20 + temp);

						  window.draw(texture_data.exp1);

						  temp += 50;

				} 
					break;
				case 4:
				{
						  texture_data.explosion.loadFromFile("images/explosion/rsz_explosion04.png");
						  
						  if (type == 'r')
						  texture_data.exp1.setPosition(c * 50 + temp + 255, r * 50 + 20);
						else
						 texture_data.exp1.setPosition(c * 50 + 255, r * 50 + 20 + temp);

						  window.draw(texture_data.exp1);

						  temp += 50;

				}
					break;
				case 5:
				{
						  texture_data.explosion.loadFromFile("images/explosion/rsz_explosion05.png");

						  if (type == 'r')
						  texture_data.exp1.setPosition(c * 50 + temp + 255, r * 50 + 20);
						  else
							  texture_data.exp1.setPosition(c * 50 + 255, r * 50 + 20 + temp);

						  window.draw(texture_data.exp1);

						  temp += 50;


				}
					break;
				}

			}
			if (i<5)                  ////////////
			         {  Sleep(185);   			window.display();}

			if (i == 5)
			{
				if (Bonous_m.Get_curr_bonous() > 0)
				{
					window.clear();
					draw();
					Bonous_m.text_bonous.setPosition(c * 50 + 255, r * 50 + 20);
						Bonous_m.draw_bonous_at(window, int_to_string(Bonous_m.Get_curr_bonous() * 5));

					window.display();
					Sleep(650);

					score_m.Increment_by(5 * Bonous_m.Get_curr_bonous());
				}

			}
		}







	
}


bool Board::Check_col_remove(int col)
{
	int cnt = 0;

	bool again = false;

	for (int i = 2; i < 8; i++)
	{
		if (sprites[i][col].candy_name == sprites[i - 1][col].candy_name && sprites[i][col].candy_name == sprites[i - 2][col].candy_name)                      // edit more that 3 chain should be removed
		{
			again = true;

			Bonous_m.increment();

			//Bonous_m.start_again();

			window.clear();         //////////////////////////////////////// draw the swap then sleep in order to be seen befror remove the chain

			draw();


			window.display();

			int tempI = i;
			while (tempI + 1< 8 && sprites[tempI + 1][col].candy_name == sprites[tempI][col].candy_name) // to get the longest chain
				cnt++, tempI++;

			
			swap_make_chain = true;
		
			S_M.remove_sound.play();



			Generate_explosion_at(cnt + 3, 'c', i - 2, col);

			i = tempI;    // go from bottom to above swap (i now at last candy the same )
			            

			for (int j = i; j >= 0; j--)
			{
				if (valid_index_array(j - 3 - cnt, col))
				{
					sprites[j][col].candy_name = sprites[j - 3 - cnt][col].candy_name;
				    sprites[j][col].t = sprites[j - 3 - cnt][col].t;
				}
				else
				{
					sprites[j][col].candy_name = files_name[Generate_candy()];
					sprites[j][col].t.loadFromFile(sprites[j][col].candy_name);
				}
			}
			score_m.Increment_by ( 30 + cnt * 10);


			Sleep(800);

			window.clear();         ////////////////////////////////////////

			draw();

			window.display();
		//	Sleep(800);


		}

	}
	
	
	/*if (again)
	Check_board();*/
	return again;
}

bool Board::Check_row_remove(int row)
{
	bool again = false;

	int cnt = 0;

	for (int i = 2; i < 5; i++)
	{
		if (sprites[row][i].candy_name == sprites[row][i - 1].candy_name && sprites[row][i].candy_name == sprites[row][i - 2].candy_name)
        {
			again = true;

			Bonous_m.increment();

		
		//	Bonous_m.start_again();

			window.clear();       

			draw();

			window.display();

			int tempI = i;  // represent last col the same
			while (tempI + 1< 5 && sprites[row][tempI].candy_name == sprites[row][tempI + 1].candy_name) // to get the longest chain
				cnt++, tempI++;


			swap_make_chain = true;
			S_M.remove_sound.play();


			Generate_explosion_at(cnt + 3, 'r', row, i - 2);


			while (row != 0)
			{
				
				if (cnt > 0)
				{
					sprites[row][i+1].t = sprites[row - 1][i+1].t;
					sprites[row][i+1].candy_name = sprites[row - 1][i+1].candy_name;
					if (cnt > 1)
					{
						sprites[row][i +2].t = sprites[row - 1][i+2].t;
						sprites[row][i + 2].candy_name = sprites[row - 1][i+2].candy_name;
					}
				}

				sprites[row][i].t = sprites[row - 1][i].t;
				sprites[row][i].candy_name = sprites[row - 1][i].candy_name;
				

				sprites[row][i - 1].t = sprites[row - 1][i - 1].t;
				sprites[row][i - 1].candy_name = sprites[row - 1][i - 1].candy_name;
				

				sprites[row][i - 2].t = sprites[row - 1][i - 2].t;
				sprites[row][i - 2].candy_name = sprites[row - 1][i - 2].candy_name;
				

				row--;
			}

			//  generate a 3(or more) candies at the top of the board ( row inedex 0)

			if (cnt > 0)
			{
				sprites[row][i+1].candy_name = files_name[Generate_candy()];
				sprites[row][i+1].t.loadFromFile(sprites[row][i+1].candy_name);
				if (cnt > 1)
				{
					sprites[row][i+2].candy_name = files_name[Generate_candy()];
					sprites[row][i+2].t.loadFromFile(sprites[row][i+2].candy_name);
				}
			}

			sprites[row][i].candy_name = files_name[Generate_candy()];
			sprites[row][i].t.loadFromFile(sprites[row][i].candy_name);
			
			sprites[row][i - 1].candy_name = files_name[Generate_candy()];
			sprites[row][i - 1].t.loadFromFile(sprites[row][i - 1].candy_name);
			
			sprites[row][i - 2].candy_name = files_name[Generate_candy()];
			sprites[row][i - 2].t.loadFromFile(sprites[row][i - 2].candy_name);

			score_m.Increment_by(30 + 10 * cnt);

			Sleep(800);

			window.clear();         ////////////////////////////////////////

			draw();

			window.display();
		//	Sleep(800);
		}

	}

	/*if (again)
		Check_board();*/

	return again;

}

void Board::Check_board()                          //  recursive consume time but pretty good ;))
{

	bool r;
	for (int i = 0; i < 5; i++)
	{
		r = Check_col_remove(i);
		if (r)
		{ Check_board();}
	
	}
	
	bool c;

	for (int i = 0; i < 8; i++)
	{

		c=Check_row_remove(i);
		if (c)
		{ Check_board();}

	}
}

Board::Board()
{

	window.create(VideoMode(960, 437), "my first sfml game");	
	window.setPosition(sf::Vector2i(100, 50));

	swap_make_chain = false;

	files_name[0] = "images/Candies/GREEN.png";
	files_name[1] = "images/Candies/PURPLE.png";
	files_name[2] = "images/Candies/ORANGE.png";
	files_name[3] = "images/Candies/YELLOW.png";
	files_name[4] = "images/Candies/Red.png";
	files_name[5] = "images/Candies/BLUE.png";


}
void Board::load()
{

	

    srand(time(NULL));

	
	for (int i = 0; i <8; i++)                                       // intalize the board rondomly  (candies names)
		for (int j = 0; j < 5; j++) 
			sprites[i][j].candy_name = files_name[Generate_candy()];

	/*do {
		generate a new random number between 1 and 6
	} while (there are already two cookies of this type to the left
	or there are already two cookies of this type below);
	int candy_name;
	for (int row = 0; row < 8; row++) 
	{
		for (int  column = 0; column < 5; column++) 
		{

			if (sprites[column][row].candy_name !="") 
			{
				 do  {
					candy_name = Generate_candy();
			    	} while ((column >= 2 &&
					sprites[column - 1][row].candy_name == files_name[candy_name] &&
					sprites[column - 2][row].candy_name == files_name[candy_name])
					||
					(row >= 2 &&
					sprites[column][row - 1].candy_name == files_name[candy_name] &&
					sprites[column][row - 2].candy_name == files_name[candy_name]));

				sprites[row][column].candy_name = candy_name;
				
			}
		}
	}*/
	/////////////////////////////////////// check generation 3 at random before draw at first time; (at any row)

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			if (sprites[i][j].candy_name == "images/Candies/GREEN.png" && sprites[i][j + 1].candy_name == "images/Candies/GREEN.png"&& sprites[i][j + 2].candy_name == "images/Candies/GREEN.png")
				sprites[i][j].candy_name = "images/Candies/PURPLE.png";
			
			else if (sprites[i][j].candy_name == "images/Candies/PURPLE.png" && sprites[i][j + 1].candy_name == "images/Candies/PURPLE.png" && sprites[i][j + 2].candy_name == "images/Candies/PURPLE.png")
				sprites[i][j].candy_name = "images/Candies/ORANGE.png";


			else if (sprites[i][j].candy_name == "images/Candies/ORANGE.png" && sprites[i][j + 1].candy_name == "images/Candies/ORANGE.png" && sprites[i][j + 2].candy_name == "images/Candies/ORANGE.png")
				sprites[i][j].candy_name = "images/Candies/YELLOW.png";


			else if (sprites[i][j].candy_name == "images/Candies/YELLOW.png" && sprites[i][j + 1].candy_name == "images/Candies/YELLOW.png" && sprites[i][j + 2].candy_name == "images/Candies/YELLOW.png")
				sprites[i][j].candy_name = "images/Candies/Red.png";

			else if (sprites[i][j].candy_name == "images/Candies/Red.png" && sprites[i][j + 1].candy_name == "images/Candies/Red.png" && sprites[i][j + 2].candy_name == "images/Candies/Red.png")
				sprites[i][j].candy_name = "images/Candies/BLUE.png";

			else if (sprites[i][j].candy_name == "images/Candies/BLUE.png" && sprites[i][j + 1].candy_name == "images/Candies/BLUE.png" && sprites[i][j + 2].candy_name == "images/Candies/BLUE.png")
				sprites[i][j].candy_name = "images/Candies/GREEN.png";


		}

	}
	///////////////////////////////////// check generation 3 at random before draw at first time; (at any col)
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			if (sprites[i][j].candy_name == "images/Candies/GREEN.png" && sprites[i+1][j].candy_name == "images/Candies/GREEN.png"&& sprites[i+2][j].candy_name == "images/Candies/GREEN.png")
				sprites[i][j].candy_name = "images/Candies/PURPLE.png";

			else if (sprites[i][j].candy_name == "images/Candies/PURPLE.png" && sprites[i+1][j].candy_name == "images/Candies/PURPLE.png" && sprites[i+2][j].candy_name == "images/Candies/PURPLE.png")
				sprites[i][j].candy_name = "images/Candies/ORANGE.png";


			else if (sprites[i][j].candy_name == "images/Candies/ORANGE.png" && sprites[i+1][j].candy_name == "images/Candies/ORANGE.png" && sprites[i+2][j].candy_name == "images/Candies/ORANGE.png")
				sprites[i][j].candy_name = "images/Candies/YELLOW.png";


			else if (sprites[i][j].candy_name == "images/Candies/YELLOW.png" && sprites[i+1][j].candy_name == "images/Candies/YELLOW.png" && sprites[i+2][j].candy_name == "images/Candies/YELLOW.png")
				sprites[i][j].candy_name = "images/Candies/Red.png";

			else if (sprites[i][j].candy_name == "images/Candies/Red.png" && sprites[i+1][j].candy_name == "images/Candies/Red.png" && sprites[i + 2][j].candy_name == "images/Candies/Red.png")
				sprites[i][j].candy_name = "images/Candies/BLUE.png";

			else if (sprites[i][j].candy_name == "images/Candies/BLUE.png" && sprites[i+1][j].candy_name == "images/Candies/BLUE.png" && sprites[i + 2][j].candy_name == "images/Candies/BLUE.png")
				sprites[i][j].candy_name = "images/Candies/GREEN.png";
		}

	}

	for (int i = 0; i <8; i++) 
		for (int j = 0; j < 5; j++)
			sprites[i][j].t.loadFromFile( sprites[i][j].candy_name);

	
	for (int i = 0; i <8; i++) // intialze sprites 
	{
		for (int j = 0; j < 5; j++)
		{
			sprites[i][j].s.setTexture(sprites[i][j].t);
			sprites[i][j].type = 'D';
		
			sprites[i][j].s.setPosition(j * 50 + 255, i * 50 + 20);        ///////////////////////

		}
	}
}


bool Board:: valid_cell_window_domain(int x, int y)
{
	if (x >= 255 && x <= 505 && y >= 20 && y <= 420 && x % 50 != 0 && y % 50 != 0)   //in the domain of the CANDY GRID and not
		return true;
	else
		return false;
}

char  valid_swap_cell(int x2cany, int y2canyd,int sourcX,int sourcY)// y row x col
{
	if (y2canyd - sourcY == 1 && x2cany == sourcX)      //  down
		return 'd';
	else if (sourcY - y2canyd == 1 && x2cany == sourcX) // above 
		return 'u';
	else if (x2cany - sourcX == 1 && y2canyd == sourcY)  //right 
		return 'r';

	else if (sourcX - x2cany == 1 && y2canyd == sourcY)  //left
		return 'l';
	else
		return 'n';  // None


}

void Board::Control_mouse_events(RenderWindow& window)
{
	sf::Event event;
	
	static int  xx_prev = -1, yy_prev = -1;


	while (window.pollEvent(event))
{

		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left && valid_cell_window_domain(event.mouseButton.x, event.mouseButton.y))
			{

				int x, y;

				x = event.mouseButton.x; y = event.mouseButton.y;

				if (xx_prev != -1 && yy_prev != -1)
					sprites[yy_prev][xx_prev].type = 'D';

				x -= 255; y -= 20;
				x /= 50; y /= 50;

				sprites[y][x].type = 'A';

				xx_prev = x;    yy_prev = y;

			}
			
		case sf::Event::MouseButtonReleased:
			{
											   int x, y;
											   x = event.mouseButton.x; y = event.mouseButton.y;


											   x -= 255; y -= 20;
											   x /= 50; y /= 50;
															   
		       if (valid_swap_cell(x, y, xx_prev, yy_prev) != 'n'&& valid_index_array(y, x))     // here check vaild adjacent swap to the (prev selection)
							   {

				                      
												   swap(sprites[y][x].t, sprites[yy_prev][xx_prev].t);                   // (1)  swap the texture of both candies
												   swap(sprites[y][x].candy_name, sprites[yy_prev][xx_prev].candy_name); // (2)  swap name of their candies

												   sprites[yy_prev][xx_prev].type = 'D';
												   

													/////////////////
											   if (y == yy_prev)                              // if swap horizontal (2 candy at the same row)
												   {
												   

												       Check_col_remove(x);
													   Check_col_remove(xx_prev);
										     		 Check_row_remove(yy_prev);
													  
												   }

											   else if (x == xx_prev)                     // swap vertical ( at the same col)
											   {

												   Check_row_remove(y);
												   Check_row_remove(yy_prev);

												   Check_col_remove(x);

											   }

											   if (swap_make_chain)
											   {
												   		Check_board();

												   		swap_make_chain = false;
												   
												   		Bonous_m.start_again();
												   	
											   }
											   else
											   {
												   S_M.swap_sound.play();
												   window.clear();
												   draw();
												   window.display();

												   Sleep(600);

												   swap(sprites[y][x].t, sprites[yy_prev][xx_prev].t);
												   swap(sprites[y][x].candy_name, sprites[yy_prev][xx_prev].candy_name);

												   

												   sprites[y][x].s.setTexture(sprites[y][x].t);

												   sprites[yy_prev][xx_prev].s.setTexture(sprites[yy_prev][xx_prev].t);


												   sprites[yy_prev][xx_prev].type = 'D';
												   S_M.swap_sound.play();
											   }



			   

											   }


			}
			break;
		case sf::Event::MouseMoved:
			if (valid_cell_window_domain(event.mouseMove.x, event.mouseMove.y))
				  {
										  int x, y;                      // y represent row and x represent col ;))

										  x = event.mouseMove.x; y = event.mouseMove.y;

										  x -= 255; y -= 20;
										  x /= 50; y /= 50;

										  texture_data.effec.setPosition(x * 50 + 255, y * 50 + 20);

										  
										  window.draw(texture_data.effec);
								
				}
									  break;
		}
	}
}
void Board::draw()
{
	window.draw(texture_data.rectangle);
	
	texture_data.text_score.setString(int_to_string(score_m.Get_curr_score()));


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (sprites[i][j].type == 'A')
			{
				texture_data.effec.setPosition(j * 50 + 255, i * 50 + 20);  // ??
				window.draw(texture_data.effec);

			}

			window.draw(sprites[i][j].s);

		}
	}

	window.draw(texture_data.text_score);


}