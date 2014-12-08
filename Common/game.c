#include "game.h"

#include "glwrapper.h"

void on_surface_created() {
}

void on_surface_changed() {
}

void on_draw_frame() {
     glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void drowTwoEye(int x, int y, int screenheight, int screenwidth) {
	 	 glViewport(x, y, screenwidth, screenheight / 2);
}


