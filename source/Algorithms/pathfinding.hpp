#include <iostream>

/** solve_maze(int** maze, int n)
 * Recursively decides whether the maze is solvable from the given position
 * using backtracking.
 * A maze is solvable if position (n - 1, n - 1)  may be reached from the
 * given position by only moving downward and to the right, but not both at
 * once (i.e. not diagonally). A position in the maze is valid to move to
 * only if it contains a 1.
 */
bool solve_maze(int** maze, int n, int position[2]){
    int x = position[0], y = position[1];
    if(maze[x][y] == 0 || x > n - 1 || y > n - 1){
        return 0;
    }else if(maze[x][y] == 1 && x == n - 1 && y == n - 1){
        return 1;
    }else{
        int go_right[] = {x, y + 1};
        int go_down[] = {x + 1, y};
        bool right = solve_maze(maze, n, go_right);
        bool down = solve_maze(maze, n, go_down);
        maze[x][y] = 0;
        return right || down;
    }
    return false;
}

/** solve_maze(int** maze, int n)
 * Decides whether the maze is solvable from position (0, 0) by making a call
 * to the recursive function by the same name.
 */
bool solve_maze(int** maze, int n){
    int start[] = {0, 0};
    return solve_maze(maze, n, start);
}