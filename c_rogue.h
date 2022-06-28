/* c_hook */



/* std */
#include <stdio.h>

/* SDL */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



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



/* Constant */
const int WINDOW_WIDTH =640;
const int WINDOW_HEIGHT =480;



/* Global */
SDL_Window *h_window;
SDL_Renderer *h_render;

u32 isRunning = 1;

u32 frameTime = 0;
u32 frameStart = 0;

/* temporary player stuff */
SDL_Texture *h_texture;
SDL_Rect r_src;
SDL_Rect r_dest;