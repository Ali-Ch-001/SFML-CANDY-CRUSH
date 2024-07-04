#include"Score_manager.h"

Score_manager::Score_manager()
{
	current_score = 0;
}
int Score_manager::Get_curr_score()
{
	return current_score;
}
void Score_manager::Increment_by(int n)
{
	current_score += n;
}