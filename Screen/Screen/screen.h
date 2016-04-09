#define SCREEN_H

#include <allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_primitives.h>
#include<iostream>
#include<string>
using namespace std;

class screen
{
public:
	enum screenState{ title, game, end };

	screenState gameState;

	string menuItem[2];//creates array of the the Play and End buttons.
	int menuCounter;

	ALLEGRO_BITMAP *titleBackGroundImage;//still need to make start screen colourful.

	void Init();

	void Screen(bool &done);

	screen();
	~screen();

	void updateTitleScreen(bool &done);

private:


};

