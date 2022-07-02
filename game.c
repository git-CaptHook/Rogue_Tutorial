/* c_hook */



extern void
game_init(void) 
{
    r_src.x = 0;
    r_src.y = 64;
    
    r_src.w = 16;
    r_src.h = 16;
    
    r_dest.x = 64;
    r_dest.y = 64;
    
    r_dest.w = 64;
    r_dest.h = 64;
} /* game_init() */



extern void
game_update(void) 
{
    if(Input.left) {
        printf("left\n");
        Input.left = 0;
        if (r_dest.x >= 64) r_dest.x -= 64;
    }
    
    if(Input.right) {
        printf("right\n");
        Input.right = 0;
        if (r_dest.x <= (WINDOW_WIDTH - 128)) r_dest.x += 64;
    }
    
    if(Input.up) {
        printf("up\n");
        Input.up = 0;
        if (r_dest.y >= 64) r_dest.y -= 64;
    }
    
    if(Input.down) {
        printf("down\n");
        Input.down = 0;
        if (r_dest.y <= (WINDOW_HEIGHT - 128)) r_dest.y += 64;
    }
} /* game_update() */



extern void
game_render(void) 
{
    SDL_SetRenderDrawColor(h_render, 30, 30, 30, 255);
    SDL_RenderClear(h_render);
    
    SDL_RenderCopy(h_render, h_texture, &r_src, &r_dest);
    SDL_RenderPresent(h_render);
} /* game_render() */
