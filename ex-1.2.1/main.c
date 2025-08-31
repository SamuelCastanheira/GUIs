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
 SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
 SDL_RenderClear(ren);
 SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
 SDL_Rect r = { 400,50, 10,100 };
 SDL_RenderFillRect(ren, &r);
 SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
 SDL_Rect r2 = { 355,90, 100,10 };
 SDL_RenderFillRect(ren, &r2);

 SDL_RenderPresent(ren);




 SDL_Delay(5000);
 /* FINALIZACAO */
 SDL_DestroyRenderer(ren);
 SDL_DestroyWindow(win);
 SDL_Quit();
}
