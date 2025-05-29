//DT Nesimi

#include "yinyang.h"


yinyang::yinyang()
{
	alive = false;;
	srand(time(0));
	yinyang_bmp = NULL; //sets the bitmap to NULL

}

//destructor for bullet
yinyang::~yinyang() {
	al_destroy_bitmap(yinyang_bmp);
}

bool yinyang::getStatus()
{
	return alive;
}

//draws the bullet wherever the next position is
void yinyang::drawYinYang() {

	al_draw_bitmap(yinyang_bmp, x, y, 0);

}

//draws the initial bullet to the top of the screen
void yinyang::fire()
{
	x = rand() % 615 + 10;
	y = 10;
	alive = true;

}

//creates the actual sprite of the bullet
void yinyang::create_yinyang_bitmap(ALLEGRO_DISPLAY* display) {
	yinyang_bmp = al_create_bitmap(16, 16);
	if (!yinyang_bmp) {
		exit(1);
		al_destroy_display(display);
	}

	al_set_target_bitmap(yinyang_bmp);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	int posX = 8;
	int posY = 8;

	al_draw_filled_rectangle(posX, posY, posX + 5, posY + 5, al_map_rgb(0, 255, 0));
}

void yinyang::erase_yinyang()
{
	al_draw_filled_rectangle(x, y, x + 5, y + 5, al_map_rgb(0, 0, 0)); //black color
}

int yinyang::move_yinyang(int reimuX, int reimuY, int width, int length, int height)
{
	y++;

	if (x > reimuX && x < reimuX + width && y > reimuY && y < reimuY + length) {
		al_draw_filled_rectangle(x, y, x + 5, y + 5, al_map_rgb(0, 0, 0)); //BLACK
		alive = false;
		return 1;
	}
	if (y > height) {
		al_draw_filled_rectangle(x, y, x + 5, y + 5, al_map_rgb(0, 0, 0)); //BLACK
		alive = false;
	}
	return 0;
}


