
#include<SFML\Audio.hpp>


using namespace std;
using namespace sf;

class Sound_manager
{
	bool sound_status;

public:
	Sound_manager();
	SoundBuffer swap_buffer;
	Sound swap_sound;

	SoundBuffer remove_Buffer;
	Sound remove_sound;
	void Set_status();
	bool Get_status();

};
