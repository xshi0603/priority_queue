//#include <iostream>
#include <fstream>
//#include <string>
#include <unistd.h>
#include <stack>
#include <queue>
#include "List.cpp"

std::string maze[30];
char me='Z';
char visited='.';
char wall=' ';
char goal='$';

void load_maze(std::string filename, std::string *maze){
  std::ifstream infile(filename);
  int i=0;
  while (std::getline(infile,maze[i])){
    i++;
  }
}

void print_maze(std::string maze[25]){
  std::cout << "[0;0H\n";
  for (int i = 0; i < 30; ++i) {
    std::cout << maze[i] << "\n";
  }

}
/*
struct loc {
  int r,c;
};
*/

/*
struct loc findEndpoint(std::string maze[30]) {
  for (i = 0; i < ; i++) {
    for (j = 0; j < ; j++) {

    }
  }
}
*/

void solve(std::string maze[30], int row, int col){
  //std::stack<struct loc> s;
  //std::queue<struct loc> s;
  List s = List({2, 2, -1});
  int r,c;
  struct loc l = {row,col, -1};
  //s.push(l);
  s.insert(l);

  while (!s.empty()){
    // l = s.top();
    l = s.front();
    //s.pop();
    s.remove();
    r = l.r;
    c = l.c;
    if (maze[r][c]=='$'){
      std::cout << "SOLVED!!!!!\n";
      return;
    }

    maze[r][c]='z';
    usleep(40000);
    print_maze(maze);

    if (maze[r+1][c]=='#' || maze[r+1][c]=='$') {
      maze[r+1][c] = '.';
      //s.push({r:r+1,c:c});
      struct loc temp = {r+1, c, -1};
      s.insert(temp);
    }
    if (maze[r-1][c]=='#'||  maze[r-1][c]=='$') {
      maze[r-1][c] = '.';
      //s.push({r:r-1,c:c});
      struct loc temp = {r-1, c, -1};
      s.insert(temp);
    }
    if (maze[r][c+1]=='#' || maze[r][c+1]=='$') {
      maze[r][c+1] = '.';
      //s.push({r:r,c:c+1});
      struct loc temp = {r, c+1, -1};
      s.insert(temp);
    }
    if (maze[r][c-1]=='#' ||  maze[r][c-1]=='$') {
      maze[r][c-1] = '.';
      //s.push({r:r,c:c-1});
      struct loc temp = {r, c-1, -1};
      s.insert(temp);
    }
    
  }
}
  
  

int main()
{
  int solved=0;
  
  //load_maze("maze.dat",maze);
  //solve(maze,1,2);
  load_maze("maze.dat",maze);
  solve(maze,28,26);
  return 0;
}
