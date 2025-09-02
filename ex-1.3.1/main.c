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
 bool direita  = true;
 bool esquerda = false;

 while (1)
{
    if (r2.x < 0)
    {
       direita = true; esquerda = false;  
    }
    else if (r2.x + r2.w > 800)
    {
       direita = false; esquerda = true;
    }
    
    if (direita)
    {
       r.x += 10; r2.x += 10;
    }
    
    if (esquerda)
    {
      r.x -=10; r2.x -= 10;
    }

    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(ren, &r);

    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
    SDL_RenderFillRect(ren, &r2);
    SDL_RenderPresent(ren);
    SDL_Delay(500);

}
 /* FINALIZACAO */
 SDL_DestroyRenderer(ren);
 SDL_DestroyWindow(win);
 SDL_Quit();
}
