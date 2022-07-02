/* c_hook */



extern void
game_init(void) 
{
    r_src.x = 0;
    r_src.y = 64;
    
    r_src.w = TILE_SIZE_ACTUAL;
    r_src.h = TILE_SIZE_ACTUAL;
    
    r_dest.x = TILE_SIZE;
    r_dest.y = TILE_SIZE;
    
    r_dest.w = TILE_SIZE;
    r_dest.h = TILE_SIZE;
} /* game_init() */



extern void
game_update(void) 
{
    if(Input.left) {
        Input.left = 0;
        if (r_dest.x >= TILE_SIZE) r_dest.x -= TILE_SIZE;
    }
    
    if(Input.right) {
        Input.right = 0;
        if (r_dest.x <= (WINDOW_WIDTH - (2*TILE_SIZE))) r_dest.x += TILE_SIZE;
    }
    
    if(Input.up) {
        Input.up = 0;
        if (r_dest.y >= TILE_SIZE) r_dest.y -= TILE_SIZE;
    }
    
    if(Input.down) {
        Input.down = 0;
        if (r_dest.y <= (WINDOW_HEIGHT - (2*TILE_SIZE))) r_dest.y += TILE_SIZE;
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
