#include <SDL2/SDL.h>
int main (int argc, char* args[])
{
 /* INICIALIZACAO */
 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* win = SDL_CreateWindow("Hello World!",
 SDL_WINDOWPOS_UNDEFINED,
SDL_WINDOWPOS_UNDEFINED,
800, 200, SDL_WINDOW_SHOWN
 );
 SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

 /* EXECUÇÃO */

 SDL_Rect r = { 400,50, 10,100 };
 SDL_Rect r2 = { 355,90, 100,10 };
 Uint32 espera = 500;

 while (1)
{
    Uint32 antes = SDL_GetTicks();
    /* REDESENHO */
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);

    SDL_Event evt;
    int isevt = SDL_WaitEventTimeout(&evt, espera);
    if (isevt) 
    {
        espera -= (SDL_GetTicks() - antes);
        if (evt.type == SDL_KEYDOWN) 
	{
            if (evt.key.keysym.sym == SDLK_LEFT)
            {
	        if (r2.x > 0)
		{
                    r.x -=10; r2.x -=10;
		}
	    }
            if (evt.key.keysym.sym == SDLK_RIGHT)
            {
		    if (r2.x + r2.w < 800)
		    {
                        r.x +=10; r2.x +=10;
		    }
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
    }


    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(ren, &r);

    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
    SDL_RenderFillRect(ren, &r2);
    SDL_RenderPresent(ren);
}

 /* FINALIZACAO */
 SDL_DestroyRenderer(ren);
 SDL_DestroyWindow(win);
 SDL_Quit();
}
