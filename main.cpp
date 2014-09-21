#include "SDL2/SDL.h"

int main(int argc, char** argv){
  
  const char* title = "Title"; // window title (titulo).
  
  int x, y, w, h;
  
  x = 0; 	// window X position.
  y = 0; 	// window Y position.
  w = 640; 	// window width (largura).
  h = 480; 	// window height (altura).
  
  SDL_Window* window; // to create window
  SDL_Renderer* renderer; // to create renderer
  
  if(SDL_Init(SDL_INIT_VIDEO) != 0) // if it's not possible to initialize SDL throw SDL_GetError().
    throw SDL_GetError();
  
  window = SDL_CreateWindow(title, x, y, w, h); // create window
  
  if(!window) // if window it's null throw SDL_GetError().
    throw SDL_GetError();
  
  renderer = SDL_CreateRenderer(renderer, -1, 0); // create renderer
  
  if(!renderer)
    throw SDL_GetError(); // if renderer it's null throw SDL_GetError().
    
  while(!quit){ // while the loop is true don't quit
    while(SDL_PollEvent(&event)){ // verify events
      switch(event.type){ // type of event
	case SDL_QUIT: // if the window is closed in the X button
	  quit = true; // quit turns true and the loop ends. (the program ends)
	  break;
	  
	default:
	  break;
      }
    }
    //Logic()
    //Draw()
    //Update()
  }
  
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  
  SDL_Quit();
  return 0;
}