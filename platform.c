/* c_hook */

#include "game.h"
#include "game.c"



/* functions */
intern void
show_error_box(message)
const char* message;
{
    SDL_Quit();
    Game.running = 0;
    
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                             "Error", message, NULL);
}



intern void
sdl_process_events(Event)
SDL_Event *Event; 
{
    switch (Event->type) {
        case SDL_KEYDOWN: {
            if (Event->key.keysym.sym == SDLK_LEFT)  Input.left++;
            if (Event->key.keysym.sym == SDLK_RIGHT) Input.right++;
            if (Event->key.keysym.sym == SDLK_UP)    Input.up++;
            if (Event->key.keysym.sym == SDLK_DOWN)  Input.down++;
            
            if (Event->key.keysym.sym == SDLK_ESCAPE) Game.running = 0;
        } break;
        
        case SDL_QUIT: {
            Game.running = 0;
        } break;
    }
} /* sdl_process_events() */



int main(void)
{
    /* start game */
    Game.running = 1;
    
    
    /* SDL Init */
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) < 0) {
        show_error_box("SDL_Init() fail");
        return(__LINE__);
    }
    IMG_Init(IMG_INIT_PNG);
    
    h_window = SDL_CreateWindow(WINDOW_TITLE,
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WINDOW_WIDTH, WINDOW_HEIGHT,
                                WINDOW_OPTIONS);
    if (!h_window) {
        show_error_box("SDL_CreateWindow() fail");
        return(__LINE__);
    }
    
    h_render = SDL_CreateRenderer(h_window, -1, 0);
    if (!h_render) {
        show_error_box("SDL_CreateRenderer() fail");
        return(__LINE__);
    }
    
    h_temp = IMG_Load("src/dw.png");
    if (!h_temp) {
        show_error_box("IMG_Load() fail");
        return(__LINE__);
    }
    
    SDL_SetColorKey(h_temp, SDL_TRUE, SDL_MapRGB(h_temp->format, 255, 0, 255));
    h_texture = SDL_CreateTextureFromSurface(h_render, h_temp);
    
    
    /* game init */
    game_init();
    
    
    /* main loop */
    while(Game.running) {
        time_start = SDL_GetTicks();
        
        SDL_Event Event;
        while(SDL_PollEvent(&Event)) {
            sdl_process_events(&Event);
        }
        
        /* game update */
        game_update();
        game_render();
        
        time_frame = SDL_GetTicks() - time_start;
        if (time_frame < FRAME_TIME_MIN) {
            SDL_Delay(FRAME_TIME_MIN - time_frame);
        }
    }
    
    SDL_Quit();
    return(0);
} /* main() */
