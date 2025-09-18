#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include "Aux.c"

int main (void) 
{

/* INICIALIZACAO */
SDL_Init(SDL_INIT_EVERYTHING);
IMG_Init(0);
SDL_Window*
win = SDL_CreateWindow("Imagem em Tiras",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,800,SDL_WINDOW_SHOWN
		);
SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
SDL_Texture* img = IMG_LoadTexture(ren, "bird.png");
assert(img != NULL);

/* EXECUÇÃO */
int isup = 0;
int x = 10;
Uint32 espera = 500;
SDL_Rect r = { x,50, 100,80 };
SDL_Rect c = {0, 0, 100, 80};
Uint32 ultimo_evento = 0;
Uint32 intervalo;
 while (1)
{   
    /* REDESENHO */
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);      
    SDL_Event evt;
    if (AUX_WaitEventTimeoutCount(&evt, &espera))
    {
	intervalo = SDL_GetTicks() - ultimo_evento;
	if (intervalo >= 250)
	{
        if (evt.type == SDL_KEYDOWN)
        {
            if (evt.key.keysym.sym == SDLK_LEFT)
            {
                if (r.x > 0)
                {
                    r.x -=10;
                
                    if (isup)
                    {
                        c = (SDL_Rect) {200,0, 100,80 };
                    }
                    else
                    {
                        c = (SDL_Rect) { 300,0, 100,80 };
                    }
                    isup = !isup;

	        }        
	    }

            if (evt.key.keysym.sym == SDLK_RIGHT)
            {
                    if (r.x + r.w < 800)
                    {
                        r.x +=10;
                
		         if (isup)
                         {
                             c = (SDL_Rect) {0,0, 100,80 };
                         }
                         else
                         {
                             c = (SDL_Rect) { 100,0, 100,80 };
                         }
                         isup = !isup;

	            }
	    }

	    if (evt.key.keysym.sym == SDLK_x)
            {
                 /* FINALIZACAO */
                SDL_DestroyTexture(img);
		SDL_DestroyRenderer(ren);
                SDL_DestroyWindow(win);
                SDL_Quit();
                return 0;
            }
	    ultimo_evento = SDL_GetTicks();
        }
	}
	else
	{
         espera = 500;
	}
    }
        SDL_RenderCopy(ren, img, &c, &r);
        SDL_RenderPresent(ren);
  }
}
