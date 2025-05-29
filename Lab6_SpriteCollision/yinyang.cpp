#include "yinyang.h"
yinyang::yinyang()
{
	alive = false;;
	srand(time(0));
}
bool yinyang::getStatus()
{
	return alive;
}

void yinyang::fire()
{
	x = rand() % 615 + 10;
	y = 10;
	alive = true;

}
void yinyang::erase_yinyang()
{
	al_draw_filled_rectangle(x, y, x + 5, y + 5, al_map_rgb(0, 0, 0)); //black color
}
int yinyang::move_yinyang(int reimuX, int reimuY, int width, int length, int height)
{
	y++;
	al_draw_filled_rectangle(x, y, x + 5, y + 5, al_map_rgb(255, 255, 0));//yellow color


	if (x > reimuX && x < reimuX + width && y > reimuY && y < reimuY + length) {
		al_draw_filled_rectangle(x, y, x + 5, y + 5, al_map_rgb(0, 0, 0)); //BLACK
		alive = false;
		return 1;
	}
	if (y > height)
		alive = false;
	return 0;


}


