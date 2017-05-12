/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
int totalTiles = -1;

// curent blank location
int bx = -1, by = -1;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    } else {
        totalTiles = d * d - 1;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(1000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int x = totalTiles;
    bool needSwap = (d % 2 == 0) ? true : false;
    
    for (int r = 0; r < d; ++r) {
        for (int c = 0; c < d; ++c) {
            board[r][c] = x;
            --x;
        }
    }
    
    if (needSwap) {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
    
    bx = d - 1;
    by = d - 1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int r = 0; r < d; ++r) {
        for (int c = 0; c < d; ++c) {
            if (board[r][c] == 0) {
                printf(" _ ");
            } else {
                printf("%2i ", board[r][c]);
            }
        }
        printf("\n");
    }
}

bool find_tile_position(int tile, int *x, int *y) {
    for (int r = 0; r < d; ++r) {
        for (int c = 0; c < d; ++c) {
            if (board[r][c] == tile) {
                *x = r;
                *y = c;
                return true;
            }
        }
    }
    
    return false;
}

bool is_neighbor(int tile) {
    // up
    if ((by - 1 >= 0) && (board[bx][by-1] == tile)) {
        // has up tile
        return true;
    }
    
    // down
    if ((by + 1 < d) && (board[bx][by+1] == tile)) {
        return true;
    }
    
    // left
    if ((bx-1 >= 0) && (board[bx-1][by] == tile)) {
        return true;
    }
    
    // right
    if ((bx+1 < d) && (board[bx+1][by] == tile)) {
        return true;
    }
    
    return false;
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // blank is at bx, by

    int to_x = -1;
    int to_y = -1;

    // TODO
    // find the x and y of targated tile
    if(find_tile_position(tile, &to_x, &to_y)) {
        printf("DEBUG: move to row: %d, col: %d\n", to_x, to_y);
        
        if(is_neighbor(tile)) {
            // swap
            board[bx][by] = board[to_x][to_y];
            board[to_x][to_y] = 0;
            
            bx = to_x;
            by = to_y;
            
            return true;
        }
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    int expected_val = 1;
    
    for(int r = 0; r < d; ++r) {
        for(int c = 0; c < d; ++c) {
            if (board[r][c] == 0) {
                
                if (expected_val == d*d - 1) {
                    if((r == d - 1) && (c == d-1)) {
                        return true;
                    }
                } else {
                    return false;
                }
            }
            
            if (board[r][c] == expected_val) {
                if (expected_val != d*d -1) {
                    ++expected_val;
                }
            }
        }
    }

    return false;
}
