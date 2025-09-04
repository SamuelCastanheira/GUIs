#include <SDL2/SDL.h>
#include <stdio.h>

#define ESPERA 1000;

int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms)
{
   Uint32 msRetorno = SDL_GetTicks();
   if (msRetorno % *ms == 0)
   {
	*ms = ESPERA;
	printf("1-%d\n",*ms);
        return SDL_WaitEventTimeout(evt,*ms);
   }
   else 
   {
	
	*ms =  msRetorno % *ms;
        printf("2-%d\n", *ms);
	return SDL_WaitEventTimeout(evt,* ms); 
   }
}
