#include <allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<iostream>
#include<string>
#include"screen.h"

#define ScreenWidth 800
#define ScreenHeight 600

using namespace std;

screen::screen()//constructor
{

}

screen::~screen()//destructor
{

}


void screen::Init()
{
	ALLEGRO_DISPLAY *display;

	gameState = title;//initialises the gameState to 0.

	menuItem[0] = "Play";
	menuItem[1] = "End";

	if (!al_init())//if allegro is  initialised this will prompt this message to popup.
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not ....", NULL, NULL);
	}

}

void screen::Screen(bool &done)
{
	switch (gameState)
	{
	case title:
		screen::updateTitleScreen(done);
		break;

    //still need to include other screen types ie.gameScreen and gameOver screen.

	}

}



void screen::updateTitleScreen(bool &done)
{

	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY *display = al_create_display(ScreenWidth, ScreenHeight);
	al_set_window_position(display, 200, 100);


	ALLEGRO_FONT *font = al_load_font("orbitron-black.ttf", 36, NULL);


	ALLEGRO_EVENT_QUEUE *event = al_create_event_queue();
	al_register_event_source(event, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event, &events);

		if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (events.keyboard.keycode)
			{

			case ALLEGRO_KEY_DOWN: //if down key is pressed this will assign 1 to menucounter.
				menuCounter = 1;

				break;

			case ALLEGRO_KEY_UP: //if up key is pressed this will assign 0 to menucounter. 
				menuCounter = 0;

				break;

			case ALLEGRO_KEY_ENTER: //if enter is pressed is first checks what the menucounter is equal to, if its 0 then gamestate will equal game(the gameScreen stage) and if it is 1 then done is true and will exit the game.

				if (menuCounter == 0)
				{
					gameState = game;
				}

				else if (menuCounter == 1)
				{
					done = true;
				}

				break;

			case ALLEGRO_KEY_ESCAPE: //the escape key can also be pressed to exit the game.
				done = true;
				break;
			}
		}

		for (int i = 0; i <= 1; i++) //a loop that will print the 2 menuItems.
		{
			al_draw_text(font, al_map_rgb(44, 117, 255), ScreenWidth / 2, (ScreenHeight + (i * 100)) / 2, ALLEGRO_ALIGN_CENTER, menuItem[i].c_str());
		}


		//this print will highlight either "Play" or "End" depending on which key is pressed ie.up or down keys.
		al_draw_text(font, al_map_rgb(0, 255, 0), ScreenWidth / 2, (ScreenHeight + (menuCounter * 100)) / 2, ALLEGRO_ALIGN_CENTER, menuItem[menuCounter].c_str());

		al_flip_display();

		//just to show which is pressed and displays either 1 or 0.
		cout << menuCounter << endl;
	}

	al_flip_display();
	al_rest(10.0);
	al_destroy_display(display);

	al_destroy_font(font);




}