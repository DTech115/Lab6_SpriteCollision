//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>


class yinyang
{
public:
	yinyang();
	~yinyang();
	void create_yinyang_bitmap(ALLEGRO_DISPLAY* display);
	void drawYinYang();
	void fire();
	int move_yinyang(int reimuX, int reimuY, int width, int length, int height);
	void erase_yinyang();
	bool getStatus();
private:
	int x, y;
	bool alive;
	ALLEGRO_BITMAP* yinyang_bmp;
};

