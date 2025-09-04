#include <SDL2/SDL.h>
#include "Aux.c"
int main (int argc, char* args[])
{
 /* INICIALIZACAO */
 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* win = SDL_CreateWindow("Hello World!",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    800,800, SDL_WINDOW_SHOWN
 );
 SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

 /* EXECUÇÃO */
  SDL_Rect mvTempo = { 40,20, 10,10 };

 SDL_Rect mvTeclado = { 10,20, 10,10 };

 SDL_Rect mvMouse = { 60,20, 10,10 };

  Uint32 espera = 1000;
  int mouseX, mouseY;

 while (1) {
    /* REDESENHO */
     SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);

    SDL_Event evt;
    int isevt = AUX_WaitEventTimeoutCount(&evt, &espera);
    if (isevt) 
    {
        if (evt.type == SDL_KEYDOWN) {
            if (evt.key.keysym.sym == SDLK_UP)
            {
                mvTeclado.y -=10;
            }
             if (evt.key.keysym.sym == SDLK_DOWN)
            {
                mvTeclado.y +=10;
            }
             if (evt.key.keysym.sym == SDLK_LEFT)
            {
                mvTeclado.x -=10;
            }
             if (evt.key.keysym.sym == SDLK_RIGHT)
            {
                mvTeclado.x +=10;
            }

	    if (evt.key.keysym.sym == SDLK_x)
	    {
		 /* FINALIZACAO */
		 SDL_DestroyRenderer(ren);
  		SDL_DestroyWindow(win);
  		SDL_Quit();
		return 0;
	    }
        }
        if (evt.type == SDL_MOUSEMOTION)
        {
            SDL_GetMouseState(&mouseX, &mouseY);
            mvMouse.x = mouseX; mvMouse.y = mouseY;
        }
    } 
    else 
    {
    	mvTempo.x +=10; mvTempo.y +=10;
    }

    SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0xFF);
    SDL_RenderFillRect(ren, &mvTempo);
    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0xFF);
    SDL_RenderFillRect(ren, &mvTeclado);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0xFF);
    SDL_RenderFillRect(ren, &mvMouse);
    SDL_RenderPresent(ren);
 }
}
