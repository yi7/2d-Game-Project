#include "menu.h"

int menu_flag = true;

Sprite *background;

Sprite *button1;
SDL_Rect button1_box;
Sprite *button2;
SDL_Rect button2_box;
Sprite *button3;
SDL_Rect button3_box;
Sprite *button4;
SDL_Rect button4_box;
Sprite *button5;
SDL_Rect button5_box;
Sprite *button6;
SDL_Rect button6_box;

void menu_initialize()
{
	background = sprite_load("images/background.png", 1970, 1130);

	button1_box.x = 80;
	button1_box.y = 80;
	button1_box.w = 80;
	button1_box.h = 40;
	button1 = sprite_load("images/buttons.png", button1_box.w, button1_box.h);
	button2_box.x = 200;
	button2_box.y = 80;
	button2_box.w = 80;
	button2_box.h = 40;
	button2 = sprite_load("images/buttons.png", button2_box.w, button2_box.h);
	button3_box.x = 80;
	button3_box.y = 160;
	button3_box.w = 80;
	button3_box.h = 40;
	button3 = sprite_load("images/buttons.png", button3_box.w, button3_box.h);
	button4_box.x = 200;
	button4_box.y = 160;
	button4_box.w = 80;
	button4_box.h = 40;
	button4 = sprite_load("images/buttons.png", button4_box.w, button4_box.h);
	button5_box.x = 80;
	button5_box.y = 240;
	button5_box.w = 80;
	button5_box.h = 40;
	button5 = sprite_load("images/buttons.png", button5_box.w, button5_box.h);
	button6_box.x = 200;
	button6_box.y = 240;
	button6_box.w = 80;
	button6_box.h = 40;
	button6 = sprite_load("images/buttons.png", button6_box.w, button6_box.h);
}

void menu_draw()
{
	SDL_RenderCopy(graphics_renderer, background->image, NULL, NULL);

	int x, y;
	SDL_Rect mouse;

	SDL_GetMouseState( &x, &y );
	mouse.x = x;
	mouse.y = y;
	mouse.w = 0;
	mouse.h = 0;
	
	if(rect_intersect(mouse, button1_box))
	{
		sprite_draw(button1, 1, button1_box.x, button1_box.y);
	}
	else
	{
		sprite_draw(button1, 0, button1_box.x, button1_box.y);
	}

	if(rect_intersect(mouse, button2_box))
	{
		sprite_draw(button2, 17, button2_box.x, button2_box.y);
	}
	else
	{
		sprite_draw(button2, 16, button2_box.x, button2_box.y);
	}

	if(rect_intersect(mouse, button3_box))
	{
		sprite_draw(button3, 33, button3_box.x, button3_box.y);	
	}
	else
	{
		sprite_draw(button3, 32, button3_box.x, button3_box.y);	
	}

	if(rect_intersect(mouse, button4_box))
	{
		sprite_draw(button4, 49, button4_box.x, button4_box.y);
	}
	else
	{
		sprite_draw(button4, 48, button4_box.x, button4_box.y);
	}

	if(rect_intersect(mouse, button5_box))
	{
		sprite_draw(button5, 65, button5_box.x, button5_box.y);
	}
	else
	{
		sprite_draw(button5, 64, button5_box.x, button5_box.y);
	}

	if(rect_intersect(mouse, button6_box))
	{
		sprite_draw(button6, 81, button6_box.x, button6_box.y);
	}
	else
	{
		sprite_draw(button6, 80, button6_box.x, button6_box.y);
	}
}

void menu_click()
{
	int x, y;
	SDL_Rect mouse;

	SDL_GetMouseState( &x, &y );
	mouse.x = x;
	mouse.y = y;
	mouse.w = 0;
	mouse.h = 0;
	
	if(rect_intersect(mouse, button1_box))
	{
		menu_flag = false;
		tilemap_initialize_system("images/level.map", "images/level_animals.txt");
	}
	else if(rect_intersect(mouse, button2_box))
	{
		menu_flag = false;
		tilemap_initialize_system("images/level2.map", "images/level2_animals.txt");
	}
	else if(rect_intersect(mouse, button3_box))
	{
		menu_flag = false;
		tilemap_initialize_system("images/level3.map", "images/level3_animals.txt");
	}
	else if(rect_intersect(mouse, button4_box))
	{
		menu_flag = false;
		tilemap_initialize_system("images/level4.map", "images/level4_animals.txt");
	}
	else if(rect_intersect(mouse, button5_box))
	{
		menu_flag = false;
		tilemap_initialize_system("images/make.map", "images/make.txt");
	}
	else if(rect_intersect(mouse, button6_box))
	{
		menu_flag = false;
		tilemap_initialize_system("images/made.map", "images/made.txt");
	}
}