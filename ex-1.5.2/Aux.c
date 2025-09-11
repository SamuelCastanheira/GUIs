#include <SDL2/SDL.h>
#include <stdio.h>

int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms)
{
   Uint32 msInicio = SDL_GetTicks();
   int ret = SDL_WaitEventTimeout(evt, *ms);
   Uint32 msFim = SDL_GetTicks();

   if (!ret)
   {
        return 0;
   }
   else 
   {
	*ms =  *ms  - (msFim-msInicio);
	return 1; 
   }
}
