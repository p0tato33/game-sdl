#include <iostream>
#include <SDL.h>
#include "window.h"
#include "tank.h"
#include "text.h"

void pollEvents(Window& window, Tank& tank1, Tank& tank2) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		tank1.pollEvents(event);
		tank2.pollEvents(event);
		window.pollEvents(event);
	}
}

int main(int argc, char** argv) {
	Window window("Tanks Game", 1000, 1000);
	Tank tank1(50, 50, "res/tank.png", false);
	Tank tank2(900, 900, "res/tank.png", true);

	while (!window.isClosed()) {
		pollEvents(window, tank1, tank2);
		tank1.draw();
		tank2.draw();
		window.clear();
	}

	return 0;
}