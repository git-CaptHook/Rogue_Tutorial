/* c_hook */



#include "c_rogue.h"



/* functions */

static void
game_init(void)
{
    r_src.x = 0;
    r_src.y = 64;
    
    r_src.w = 16;
    r_src.h = 16;
    
    r_dest.w = 256;
    r_dest.h = 256;
} /* game_init() */



static void
game_load(void)
{
    SDL_Surface *h_temp = IMG_Load("dw.png");
    SDL_SetColorKey(h_temp, SDL_TRUE, SDL_MapRGB(h_temp->format, 255, 0, 255));
    h_texture = SDL_CreateTextureFromSurface(h_render, h_temp);
    
    SDL_FreeSurface(h_temp);
} /* game_load() */



static void
game_update(void)
{
} /* game_update() */



static void
game_render(void)
{
    SDL_SetRenderDrawColor(h_render, 30, 30, 30, 255);
    SDL_RenderClear(h_render);
    
    SDL_RenderCopy(h_render, h_texture, &r_src, &r_dest);
    SDL_RenderPresent(h_render);
} /* game_render() */



static void 
sdl_process_events(SDL_Event *Event) 
{
    switch(Event->type) 
    {
        case SDL_KEYDOWN:
        {
            switch(Event->key.keysym.sym)
            {
                case SDLK_RIGHT:
                {
                    r_dest.x += 4;
                } break;
                
                case SDLK_LEFT:
                {
                    r_dest.x -= 4;
                } break;
                
                case SDLK_UP:
                {
                    r_dest.y -= 4;
                } break;
                
                case SDLK_DOWN:
                {
                    r_dest.y += 4;
                } break;
                
                case SDLK_ESCAPE:
                {
                    isRunning = 0;
                } break;
            }
        } break;
        
        case SDL_QUIT: 
        {
            isRunning = 0;
        } break;
    }
} /* sdl_process_events() */



/* **************************************** */

int main(int argc, char** args) 
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0) return (__LINE__);
    IMG_Init(IMG_INIT_PNG);
    
    h_window = SDL_CreateWindow("C_Rogue",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH, WINDOW_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if(!h_window) return(__LINE__);
    
    h_render = SDL_CreateRenderer(h_window, -1, 0);
    if(!h_render) return(__LINE__);
    
    game_init();
    game_load();
    
    
    
    while(isRunning) 
    {
        frameStart = SDL_GetTicks();
        
        SDL_Event Event;
        while(SDL_PollEvent(&Event)) 
        {
            sdl_process_events(&Event);
        }
        
        game_update();
        game_render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < 16) 
        {
            SDL_Delay(16 - frameTime);
        }
    }
    
    SDL_Quit();
    
    return(0);
}/* main() */