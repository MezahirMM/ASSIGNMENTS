#include <stdio.h>
#include <stdbool.h>

bool solveMaze(char** maze, const int HT, const int WD, int x, int y); 		// draws a path to the exit on the maze string
void printMaze(char** maze, const int HT, const int WD); 					// prints the maze

int main(){
    char mazeStr[] =
			"  ##############"
		    "#     #     ####"
		    "# ####* ### ####"
		    "#    ###### ####"
		    "#### # #### ####"
		    "#    # #### ####"
		    "#### # #### ####"
		    "####        ####"
		    "################";
    const int HT = 9;
    const int WD = 16;
    char* maze[HT];

    for (int i=0; i<HT ; i++)												 // filling the 2D char array
		maze[i]=&mazeStr[i*WD];

    solveMaze(maze, HT, WD, 0, 0);
    
    printMaze(maze, HT, WD);

return 0;
}

bool solveMaze(char** maze, const int HT, const int WD, int x, int y)
{
    if(x < 0 || y < 0 || x >= WD || y >= HT) return false;
	if(maze[y][x] == '*') return true;
	if(maze[y][x] == '#' || maze[y][x] == '.') return false; 				 

	maze[y][x] = '.';

    if(solveMaze(maze, HT, WD, x, y - 1) == true) return true;
    
    if(solveMaze(maze, HT, WD, x + 1, y) == true) return true;
    
    if(solveMaze(maze, HT, WD, x, y + 1) == true) return true; 
    
    if(solveMaze(maze, HT, WD, x - 1, y) == true) return true;     			 
	
	maze[y][x] = ' ';
  
return false;
}

void printMaze(char** maze, const int HT, const int WD)
{
    for (int i=0; i<HT ; i++){
		for(int j=0; j<WD-1; j++)
			printf("%c",maze[i][j]);
	printf("%c\n",maze[i][WD-1]);
	}
}
