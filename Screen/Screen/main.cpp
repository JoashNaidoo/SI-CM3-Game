#include <allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<iostream>
#include<string>
#include"screen.h"

using namespace std;

#define ScreenWidth 800
#define ScreenHeight 600

int main()
{

	bool done = false;
	screen showScreen;

	showScreen.updateTitleScreen(done); //display the titleScreen.

	return 0;
}

