//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

#define MAXSPEED 3

class reimuClass
{
public:
	reimuClass();
	~reimuClass();
	void create_reimu_bitmap(ALLEGRO_DISPLAY* display);
	void erase_reimu();
	void move_reimu(int width, int height);
	void drawReimu();
	int getDirection();
	int getSpeed();
	int getX();
	int getY();
	void up();
	void down();
	void right();
	void left();
private:

	int x, y;
	int dir, speed;
	//int color;
	int score;
	ALLEGRO_BITMAP* reimu_bmp[4];

};