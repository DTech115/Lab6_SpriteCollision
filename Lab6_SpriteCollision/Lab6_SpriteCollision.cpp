//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "reimu.h";
#include "yinyang.h"

int main(void)
{
	reimuClass reimu;
	yinyang orb[10];
	int score = 0;
	bool redraw = true;
	const int FPS = 60;

	//variables
	int width = 640;
	int height = 520;
	bool done = false;

	int countdownTime = 30;

	//allegro variable
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;

	ALLEGRO_TIMER* countdown = NULL;	//countdown timer

	//program init
	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if (!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT* text = al_load_font("DFPPOPCorn-W12.ttf", 18, 0);	//use font for text

	reimu.create_reimu_bitmap(display);
	for (int i = 0; i < 10; i++) {
		orb[i].create_yinyang_bitmap(display);
	}

	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	reimu.drawReimu();
	al_flip_display();
	al_start_timer(timer);

	countdown = al_create_timer(1.0); //created countdown timer
	al_register_event_source(event_queue, al_get_timer_event_source(countdown));
	al_start_timer(countdown);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			//draw the initial time for the first second
			al_draw_filled_rectangle(width / 2, 490, width, 520, al_map_rgb(0, 0, 0));
			al_draw_textf(text, al_map_rgb(255, 255, 255), width, 490, ALLEGRO_ALIGN_RIGHT, "TIME: %i", countdownTime);

			//checks if its the countdown timer
			if (ev.timer.source == countdown) {
				
				if (countdownTime > 0) {
					//hide previous second time & draw new over it
					al_draw_filled_rectangle(width / 2, 490, width, 520, al_map_rgb(0, 0, 0));
					al_draw_textf(text, al_map_rgb(255, 255, 255), width, 490, ALLEGRO_ALIGN_RIGHT, "TIME: %i", countdownTime);
					countdownTime -= 1;
				}
				//once time hits 0, game over
				else if (countdownTime == 0) {
					done = true;
				}

			}
			//frame by frame timer
			else {
				redraw = true;
				for (int i = 0; i < 10; i++)
				{
					if (!orb[i].getStatus()) {
						orb[i].fire();
					}
				}
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				reimu.up();
				break;
			case ALLEGRO_KEY_DOWN:
				reimu.down();
				break;
			case ALLEGRO_KEY_LEFT:
				reimu.left();
				break;
			case ALLEGRO_KEY_RIGHT:
				reimu.right();
				break;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			if (reimu.getSpeed() != 0) {
				reimu.erase_reimu();
				reimu.move_reimu(width, height-40);
			}
			reimu.drawReimu();
			for (int i = 0; i < 10; i++)
			{
				orb[i].erase_yinyang();
				score += orb[i].move_yinyang(reimu.getX(), reimu.getY(), 47, 60, height-40);
				orb[i].drawYinYang();

				//score text here!
				al_draw_filled_rectangle(0, 490, width/2, 520, al_map_rgb(0, 0, 0));
				al_draw_textf(text, al_map_rgb(255, 255, 255), 10, 490, 0, "SCORE: %i", score);
			}

		}
		al_flip_display();
	}
	al_destroy_font(text);	//destroy font
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);						//destroy our display object
	system("pause");
	return 0;
}
