#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>


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
while (1)
{
 SDL_Rect linhaChegada = {700,0,10,800};
 SDL_Rect mvTempo = { 40,20, 10,10 };
 mvTempo.x=40;mvTempo.y=20;
 int  goTempo = 1;
 SDL_Rect mvTeclado = { 10,30, 10,10 };
 int  goTeclado = 1;
 SDL_Rect mvMouse = { 60,40, 10,10 };
 int  goMouse = 1;
 char vencedor[10];
  int espera = 500;
  int mouseX, mouseY;

 while (goTempo || goMouse || goTeclado) 
 {
    Uint32 antes = SDL_GetTicks();
    /* REDESENHO */
     SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);

    SDL_Event evt;
    int isevt = SDL_WaitEventTimeout(&evt, espera);
    if (isevt) {
        espera -= (SDL_GetTicks() - antes);
        if (evt.type == SDL_KEYDOWN) {
             if (!SDL_HasIntersection(&mvTeclado, &linhaChegada))
	     {
                 if (evt.key.keysym.sym == SDLK_LEFT)
                {
                    mvTeclado.x -=10;
                }
                if (evt.key.keysym.sym == SDLK_RIGHT)
                {
                    mvTeclado.x +=10;
                }
            }
	     else
	     {
		goTeclado = 0;
		if (vencedor == NULL)
		{
	           strcpy( vencedor,"verde");
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
        if (evt.type == SDL_MOUSEMOTION)
        {
	    if (!SDL_HasIntersection(&mvMouse, &linhaChegada))
	    {
               SDL_GetMouseState(&mouseX, &mouseY);
                mvMouse.x = mouseX;
	    }
	    else
	    {
	       goMouse = false;
	       if (vencedor == NULL)
	       {
		  strcpy(vencedor, "azul");
	       }
	    }
        }
    } 
    else 
    {
	if (!SDL_HasIntersection(&mvTempo, &linhaChegada))
	{
        espera = 500;
    	mvTempo.x +=10;
	}
	else 
	{
	    goTempo = false;
	    if (vencedor == NULL)
	    {
		    strcpy(vencedor, "vermelho");
	    }
	}
    }
    SDL_SetRenderDrawColor(ren,0x00,0x00,0x00,0xFF);
    SDL_RenderFillRect(ren, &linhaChegada);
    SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0xFF);
    SDL_RenderFillRect(ren, &mvTempo);
    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0xFF);
    SDL_RenderFillRect(ren, &mvTeclado);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0xFF);
    SDL_RenderFillRect(ren, &mvMouse);
    SDL_RenderPresent(ren);
 }
    printf("O vencedor é %s",vencedor);
}
}
