#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <assert.h>
#include "Aux.c"
#include <SDL2/SDL_mixer.h>

int main (int argc, char* args[])
{	
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         400, 400, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    SDL_Texture* img = IMG_LoadTexture(ren, "../img/1.png");
    assert(img != NULL);

   TTF_Init();
   TTF_Font* fnt = TTF_OpenFont("../img/tiny.ttf", 20);
   assert(fnt != NULL);
   SDL_Color clr = {0xFF,0x00,0x00,0xFF};
   SDL_Surface* sfc = TTF_RenderText_Blended(fnt, "Tudo o que voce toca envelhece... mas volta", clr);
   assert(sfc != NULL);
   SDL_Texture* txt = SDL_CreateTextureFromSurface(ren, sfc);
   assert(txt != NULL);
   SDL_FreeSurface(sfc);

   sfc = TTF_RenderText_Blended(fnt, "Clique multiplas vezes para usar o toque mortífero", clr);
   assert(sfc != NULL);
   SDL_Texture* txt_rodape  = SDL_CreateTextureFromSurface(ren, sfc);
   assert(txt_rodape  != NULL);
   SDL_FreeSurface(sfc);

if (Mix_Init(MIX_INIT_MP3) == 0) {
    return -1;
}

if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    return -1;
}

Mix_Music* music = Mix_LoadMUS("../img/music.mp3");
if (!music) {
    return -1;
}

Mix_PlayMusic(music, -1);

    /* EXECUÇÃO */
    SDL_Rect r = {160,160,80,80};
    SDL_Rect c = {0, 0, 1024, 1024};

    SDL_Rect titulo = { 5,5, 395,80 };
    SDL_Rect rodape = {5,320,395,80};
    SDL_Event evt; 
    Uint32 espera = 500;
    int n = 0;

    while (1) 
    {
        SDL_SetRenderDrawColor(ren, 0X00,0x00,0x00,0x00);
        SDL_RenderClear(ren);

        if (AUX_WaitEventTimeoutCount(&evt, &espera))
	{
        	if (evt.type == SDL_MOUSEBUTTONDOWN)
      		{
	    	n++; 
		espera = 250;
		SDL_Event death_touch; 
		death_touch.type = SDL_USEREVENT;
		death_touch.user.code = n; 
		SDL_PushEvent(&death_touch);
		}

		if (evt.type == SDL_KEYDOWN)
		{
            		if (evt.key.keysym.sym == SDLK_x)
            		{
                	 /* FINALIZACAO */
                 	SDL_DestroyRenderer(ren);
                 	SDL_DestroyWindow(win);
			SDL_DestroyTexture(txt);
			SDL_DestroyTexture(txt_rodape);
			TTF_CloseFont(fnt);
			TTF_Quit();
			Mix_FreeMusic(music);
			Mix_CloseAudio();
			Mix_Quit();
                 	SDL_Quit();
                 	return 0;
            		}
		}

		if (evt.type == SDL_USEREVENT)
		{
			printf("%d\n",evt.user.code);
			if (evt.user.code == 2) img = IMG_LoadTexture(ren, "../img/2.png"); 
			if (evt.user.code == 3) img = IMG_LoadTexture(ren, "../img/3.png");
			if (evt.user.code == 4) img = IMG_LoadTexture(ren, "../img/4.png");
			if (evt.user.code == 5) img = IMG_LoadTexture(ren, "../img/5.png");

		}
	} 
	else
	{
	    n = 0;	
	    espera = 500;
	    img = IMG_LoadTexture(ren, "../img/1.png");
	}
	
	SDL_SetRenderDrawColor(ren, 0x00,0X00,0X00, 0x00);
	SDL_RenderCopy(ren, img, &c, &r);
        SDL_RenderCopy(ren, txt, NULL, &titulo);
        SDL_RenderCopy(ren, txt_rodape, NULL, &rodape);

	SDL_RenderPresent(ren);
    }
}
