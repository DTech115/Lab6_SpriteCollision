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

	int x = 8;
	int y = 8;

	al_draw_filled_circle(x, y, 7, al_map_rgb(255, 255, 255)); // white back circle

	al_draw_filled_circle(x, y - 3, 4, al_map_rgb(255, 0, 0));
	al_draw_filled_triangle(x - 8, y+1, x-5, y -6, x, y-4, al_map_rgb(255, 0, 0));
	al_draw_line(x - 5, y - 5, x, y - 5, al_map_rgb(255, 0, 0), 1);
	al_draw_filled_circle(x, y - 4, 1, al_map_rgb(255, 255, 255)); //white eye
	al_draw_filled_circle(x-3, y + 3, 1, al_map_rgb(255, 0, 0)); //red eye
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


