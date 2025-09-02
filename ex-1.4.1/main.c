#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* args[])
{
    srand(time(NULL));
	
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect retan = {40,20,10,10};
    SDL_Rect r[10]; int RGB[10][3];
    SDL_Event evt;
    int mouseX; int mouseY;
    int qntRet = -1;

    while (1) 
    {
        SDL_SetRenderDrawColor(ren, 0XFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);

        SDL_WaitEvent(&evt);
        if (evt.type == SDL_MOUSEBUTTONDOWN)
       	{
		if (qntRet<9)
		{
		  ++qntRet;
	          if (SDL_GetMouseState(&mouseX, &mouseY))
		  {
	              r[qntRet] = {mouseX, mouseY, 10, 10};
		      for (int i =0;i<3;i++)
		      {
		          RGB[qntRet][i] = rand()%256;
		      }
		  }
		}
	}

	if (evt.type == SDL_KEYDOWN)
	{
		switch (evt.key.keysym.sym)
	       	{
               	 case SDLK_UP:
	            if (retan.y > 0) retan.y -=5;
                    break;
                case SDLK_DOWN:
                    if (retan.y + retan.h < 100) retan.y += 5;
                    break;
                case SDLK_LEFT:
                    if (retan.x > 0) retan.x -= 5;
                    break;
                case SDLK_RIGHT:
                    if (retan.x + retan.w < 200) retan.x += 5;
                    break;
		case SDLK_x:
		   SDL_DestroyRenderer(ren);
                   SDL_DestroyWindow(win);
                   SDL_Quit();
		   return 0;
		   break;
		}
	}
	
	SDL_SetRenderDrawColor(ren, 0x00,0X00,0X00, 0x00);
	SDL_RenderFillRect(ren,&retan);	
	for (int i=0;i<=qntRet;i++)
	{
		SDL_SetRenderDrawColor(ren, RGB[i][0], RGB[i][1], RGB[i][2], 0x00);
		SDL_RenderFillRect(ren,&r[i]);
	}

	SDL_RenderPresent(ren);
    }

}
