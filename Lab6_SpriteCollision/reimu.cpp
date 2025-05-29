//DT Nesimi

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

		if (i == 3 || i == 2) {
			al_draw_filled_rectangle(x + 6, y - 4, x - 6, y + 10, al_map_rgb(255, 0, 0)); // body
			al_draw_filled_circle(x, y - 10, 10, al_map_rgb(50, 50, 100)); //hair

			al_draw_filled_triangle(x + 5, y + 24, x, y + 32, x, y + 24, al_map_rgb(255, 255, 255)); //left leg
			al_draw_filled_triangle(x - 4, y + 24, x, y + 30, x, y + 24, al_map_rgb(130, 130, 130)); //right leg

			al_draw_filled_triangle(x, y, x + 20, y + 20, x - 20, y + 20, al_map_rgb(255, 0, 0)); //dress
			al_draw_filled_ellipse(x, y + 20, 16, 4, al_map_rgb(255, 0, 0)); // rounded dress bottom
			al_draw_spline(dress_points, al_map_rgb(255, 255, 255), 1); // dress thread
			al_draw_line(x + 6, y + 6, x - 5, y + 6, al_map_rgb(255, 255, 255), 2);//waist ribbon

			al_draw_filled_triangle(x + 6, y - 4, x + 21, y, x + 18, y + 12, al_map_rgb(255, 255, 255)); //left arm
			al_draw_filled_triangle(x - 6, y - 4, x - 21, y, x - 18, y + 12, al_map_rgb(255, 255, 255)); //right arm
			al_draw_line(x + 20, y, x + 16, y + 10, al_map_rgb(255, 0, 0), 2); //left arm thread
			al_draw_line(x - 20, y, x - 16, y + 10, al_map_rgb(255, 0, 0), 2); //right arm thread

			al_draw_filled_triangle(x, y - 18, x + 16, y - 24, x + 12, y - 8, al_map_rgb(255, 0, 0)); //left ribbon
			al_draw_filled_triangle(x, y - 18, x - 16, y - 24, x - 12, y - 8, al_map_rgb(255, 0, 0)); //right ribbon
			al_draw_line(x + 16, y - 24, x + 12, y - 8, al_map_rgb(255, 255, 255), 2); //left ribbon frill
			al_draw_line(x - 16, y - 24, x - 12, y - 8, al_map_rgb(255, 255, 255), 2); //right ribbon frill
			al_draw_line(x + 2, y - 18, x - 2, y - 18, al_map_rgb(255, 0, 0), 3); //ribbon knot

			al_draw_line(x - 20, y + 20, x - 28, y - 30, al_map_rgb(139, 69, 19), 2); //gohei stick
			al_draw_filled_rectangle(x - 28, y - 30, x - 30, y - 25, al_map_rgb(255, 255, 255)); //gohei white pattern
			al_draw_filled_rectangle(x - 30, y - 25, x - 32, y - 20, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x - 28, y - 20, x - 30, y - 15, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x - 30, y - 15, x - 32, y - 10, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x - 28, y - 10, x - 30, y - 5, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x - 30, y - 5, x - 32, y, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x - 28, y, x - 30, y + 5, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x - 30, y + 5, x - 32, y + 10, al_map_rgb(255, 255, 255));
		}
		else {
			al_draw_filled_rectangle(x - 6, y - 4, x + 6, y + 10, al_map_rgb(255, 0, 0)); // body
			al_draw_filled_circle(x, y - 10, 10, al_map_rgb(50, 50, 100)); //hair

			al_draw_filled_triangle(x - 5, y + 24, x, y + 32, x, y + 24, al_map_rgb(255, 255, 255)); //left leg
			al_draw_filled_triangle(x + 4, y + 24, x, y + 30, x, y + 24, al_map_rgb(130, 130, 130)); //right leg

			al_draw_filled_triangle(x, y, x - 20, y + 20, x + 20, y + 20, al_map_rgb(255, 0, 0)); //dress
			al_draw_filled_ellipse(x, y + 20, 16, 4, al_map_rgb(255, 0, 0)); // rounded dress bottom
			al_draw_spline(dress_points, al_map_rgb(255, 255, 255), 1); // dress thread
			al_draw_line(x - 6, y + 6, x + 5, y + 6, al_map_rgb(255, 255, 255), 2);//waist ribbon

			al_draw_filled_triangle(x - 6, y - 4, x - 21, y, x - 18, y + 12, al_map_rgb(255, 255, 255)); //left arm
			al_draw_filled_triangle(x + 6, y - 4, x + 21, y, x + 18, y + 12, al_map_rgb(255, 255, 255)); //right arm
			al_draw_line(x - 20, y, x - 16, y + 10, al_map_rgb(255, 0, 0), 2); //left arm thread
			al_draw_line(x + 20, y, x + 16, y + 10, al_map_rgb(255, 0, 0), 2); //right arm thread

			al_draw_filled_triangle(x, y - 18, x - 16, y - 24, x - 12, y - 8, al_map_rgb(255, 0, 0)); //left ribbon
			al_draw_filled_triangle(x, y - 18, x + 16, y - 24, x + 12, y - 8, al_map_rgb(255, 0, 0)); //right ribbon
			al_draw_line(x - 16, y - 24, x - 12, y - 8, al_map_rgb(255, 255, 255), 2); //left ribbon frill
			al_draw_line(x + 16, y - 24, x + 12, y - 8, al_map_rgb(255, 255, 255), 2); //right ribbon frill
			al_draw_line(x - 2, y - 18, x + 2, y - 18, al_map_rgb(255, 0, 0), 3); //ribbon knot

			al_draw_line(x + 20, y + 20, x + 28, y - 30, al_map_rgb(139, 69, 19), 2); //gohei stick
			al_draw_filled_rectangle(x + 28, y - 30, x + 30, y - 25, al_map_rgb(255, 255, 255)); //gohei white pattern
			al_draw_filled_rectangle(x + 30, y - 25, x + 32, y - 20, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x + 28, y - 20, x + 30, y - 15, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x + 30, y - 15, x + 32, y - 10, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x + 28, y - 10, x + 30, y - 5, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x + 30, y - 5, x + 32, y, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x + 28, y, x + 30, y + 5, al_map_rgb(255, 255, 255));
			al_draw_filled_rectangle(x + 30, y + 5, x + 32, y + 10, al_map_rgb(255, 255, 255));
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
	if (x > width - 64)
	{
		x = width - 64;
		speed = 0;
	}
	if (x < 0)
	{
		x = 0;
		speed = 0;
	}
	if (y > height - 64)
	{
		y = height - 64;
		speed = 0;
	}
	if (y < 0)
	{
		y = 0;
		speed = 0;
	}
}
