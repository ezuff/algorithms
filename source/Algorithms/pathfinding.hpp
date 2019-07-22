<<<<<<< HEAD
#include <iostream>

=======
>>>>>>> upstream/master
/** solve_maze(int** maze, int n)
 * Recursively decides whether the maze is solvable from the given position
 * using backtracking.
 * A maze is solvable if position (n - 1, n - 1)  may be reached from the
 * given position by only moving downward and to the right, but not both at
 * once (i.e. not diagonally). A position in the maze is valid to move to
 * only if it contains a 1.
 */
<<<<<<< HEAD
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
=======
bool solve_maze(int** maze, int n, int position[2]) {
  if (position[0] == n - 1 && position[1] == n - 1)
    return true;

  bool result;
  ++(position[1]);
  if (position[1] < n && maze[position[0]][position[1]] == 1) {
    result = solve_maze(maze, n, position);
    if (result)
      return true;
  }
  --(position[1]);
  ++(position[0]);
  if (position[0] < n && maze[position[0]][position[1]] == 1) {
    result = solve_maze(maze, n, position);
    if (result)
      return true;
  }
  --(position[0]);
  return false;
>>>>>>> upstream/master
}

/** solve_maze(int** maze, int n)
 * Decides whether the maze is solvable from position (0, 0) by making a call
 * to the recursive function by the same name.
 */
<<<<<<< HEAD
bool solve_maze(int** maze, int n){
    int start[] = {0, 0};
    return solve_maze(maze, n, start);
}
=======
bool solve_maze(int** maze, int n) {
  int start[2] = {0, 0};
  return solve_maze(maze, n, start);
}
>>>>>>> upstream/master
