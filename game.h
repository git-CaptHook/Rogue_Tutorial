/* c_hook */

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



/* define */
#define intern static


/* types */
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

typedef float    r32;
typedef double   r64;

typedef struct
{
    u8 left;
    u8 right;
    u8 up;
    u8 down;
} str_Input;

typedef struct
{
    u32 running;
} str_Game;



/* Configuration */
const int TILE_SIZE = 64;

const char* WINDOW_TITLE = "C_Rogue";
const int   WINDOW_WIDTH = 16 * TILE_SIZE;
const int   WINDOW_HEIGHT = 9 * TILE_SIZE;

const u32 FPS_TARGET = 30;
const u32 FRAME_TIME_MIN = 1000 / FPS_TARGET;


/* Window Options */
int WINDOW_OPTIONS = (SDL_WINDOW_SHOWN |
                      SDL_WINDOW_BORDERLESS);



/* Global */
SDL_Window *h_window;
SDL_Renderer *h_render;

u32 time_start = 0;
u32 time_frame = 0;

/* Data Strucures */
str_Input Input = {0};
str_Game Game = {0};

/* temporary player stuff */
SDL_Surface *h_temp;
SDL_Texture *h_texture;
SDL_Rect r_src;
SDL_Rect r_dest;

