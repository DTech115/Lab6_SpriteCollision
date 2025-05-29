#include "reimu.h"
reimuClass::reimuClass()
{
	speed = 0;
	x = 100;
	y = 100;
	dir = 1;
	score = 0;
	for (int i = 0; i < 4; i++)
	{
		reimu_bmp[i] = NULL;
	}
}
reimuClass::~reimuClass()
{
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(reimu_bmp[i]);
	}
}
void reimuClass::drawReimu()
{
	al_draw_bitmap(reimu_bmp[getDirection()], getX(), getY(), 0);
}
void reimuClass::create_reimu_bitmap(ALLEGRO_DISPLAY* display)
{
	for (int i = 0; i < 4; i++)
	{
		reimu_bmp[i] = al_create_bitmap(64, 64);
		if (!reimu_bmp[i]) {
			exit(1);
			al_destroy_display(display);

		}

		al_set_target_bitmap(reimu_bmp[i]);
		al_clear_to_color(al_map_rgb(0, 0, 0));

		int x = 32;
		int y = 32;

		//spline stuffs
		float dress_points[8] = {
			x - 18, y + 17,
			x - 12, y + 21,
			x + 8, y + 21,
			x + 17, y + 17
		};

		switch (i)
		{
		case 0: //Up
			al_draw_filled_triangle(x - 10, y - 10, x + 11, y - 10, x, y - 15, al_map_rgb(255, 0, 0));
			break;
		case 1://Right
			al_draw_filled_triangle(x + 11, y - 11, x + 11, y + 11, x + 15, y, al_map_rgb(255, 0, 0));
			break;
		case 2://Down
			al_draw_filled_triangle(x - 11, y + 11, x + 11, y + 11, x, y + 15, al_map_rgb(255, 0, 0));
			break;
		case 3: //Left
			al_draw_filled_triangle(x - 11, y - 11, x - 11, y + 11, x - 15, y, al_map_rgb(255, 0, 0));
			break;
		}
	}
}
void reimuClass::erase_reimu()
{

	int left = x;
	int top = y;
	int right = x + 64;
	int bottom = y + 64;

	al_draw_filled_rectangle(left, top, right, bottom, al_map_rgb(0, 0, 0));
}

void reimuClass::up()
{
	dir = 0;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;
}

void reimuClass::down()
{
	dir = 2;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}


void reimuClass::left()
{
	dir = 3;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}

void reimuClass::right()
{
	dir = 1;
	speed++;
	if (speed > MAXSPEED)
		speed = MAXSPEED;

}
int reimuClass::getDirection()
{
	return dir;
}
int reimuClass::getSpeed()
{
	return speed;
}
int reimuClass::getX()
{
	return x;
}
int reimuClass::getY()
{
	return y;
}
void reimuClass::move_reimu(int width, int height)
{

	//update reimu position based on direction
	switch (dir)
	{
	case 0:
		y -= speed;
		break;
	case 1:
		x += speed;
		break;
	case 2:
		y += speed;
		break;
	case 3:
		x -= speed;
	}

	//keep reimu inside the screen
	if (x > width - 32)
	{
		x = width - 32;
		speed = 0;
	}
	if (x < 0)
	{
		x = 0;
		speed = 0;
	}
	if (y > height - 32)
	{
		y = height - 32;
		speed = 0;
	}
	if (y < 0)
	{
		y = 0;
		speed = 0;
	}
}
