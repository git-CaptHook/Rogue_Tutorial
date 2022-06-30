/* c_hook */

#include <stdio.h>

/* tilemap constants */
const int WIDTH = 30;
const int HEIGHT = 10;


/* main function */
int main(argc, args)
int argc; char** args;
{
    /* loop iterate and char input */
    int i, j;
    int c = 0;
    
    /* player x and y, player char, floor char , wall char*/
    int px = 5, py = 5;
    char pc = '@';
    char fc = '.';
    char wc = '#';
    
    /* linux only, for raw input without needing to press enter */
    system("stty raw");

    /* move curser, clear screen, flush buffer */
    printf("\033[0;0H");
    printf("\033[0J");
    fflush(stdout);
    
Loop:
    /* top message */
    printf("Use 'WASD' to move, press 'Q' to quit");
    
    /* top wall */
    printf("\033[2;1H");
    printf("################################");

    /* draw loop */
    for (i = 0; i < WIDTH; i++) 
    {
        for (j = 0; j < HEIGHT; j++) 
        {
            /* if at player/wall/floor location, draw player/wall/floor */
            if(i == px && j == py) 
            {
                /* move curser to location, draw player char */
                printf("\033[%d;%dH%c",j+3,i+1,pc);
            } 
            else if (i == 1)
            {
            	/* move curser to location, draw wall char */
                printf("\033[%d;%dH%c",j+3,i,wc);
            }
            else
            {
                /* move curser to location, draw floor char */
                printf("\033[%d;%dH%c",j+3,i+1,fc);
            }
            
            /* right side wall */
            printf(" #");
            
            /* flush buffer */
	    fflush(stdout);
        }
    }
    
    /* bottom wall */
    printf("\033[E");
    printf("################################");
    
    /* input */
    c = getchar();
    
    /* move curser, clear screen, flush buffer */
    printf("\033[0;0H");
    printf("\033[0J");
    fflush(stdout);

    /* player input */
    if (c == 'a') px--;
    if (c == 'd') px++;
    if (c == 'w') py--;
    if (c == 's') py++;
    
    /* bounds */
    if (px < 2) px = 2;
    if (px > WIDTH-1) px = WIDTH-1;
    if (py < 0) py = 0;
    if (py > HEIGHT-1) py = HEIGHT-1;
    
    /* quit ? */
    if (c == 'Q' || c == 'q') return 0;
    goto Loop;
}
