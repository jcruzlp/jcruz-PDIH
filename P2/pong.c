// gcc pong.c -o pong -lncurses

#include <stdlib.h>
#include <ncurses.h>

#define DELAY 30000

void instrucciones(){
  int rows, cols;

  initscr();

  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
}

  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_GREEN);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  init_pair(3,COLOR_WHITE,COLOR_BLUE);
  clear();

  refresh();
  getmaxyx(stdscr, rows, cols); 

  WINDOW *window = newwin(rows,cols,0,0);
  wbkgd(window, COLOR_PAIR(3));
  box(window, '|', '-'); 

  mvprintw(4,0,"\t           oooooooooo                                        \n"
               "\t           888    888  ooooooo    ooooooo    oooooooo8       \n"
               "\t           888oooo88 888     888 888   888  888    88o       \n"
               "\t           888       888     888 888   888   888oo888o       \n"
               "\t          o888o        88ooo88  o888o o888o 888     888      \n"
               "\t                                             888ooo888     \n\n");

  mvwprintw(window, 17, 10, "Bienvenido a mi intento de hacer el Pong!");
  mvwprintw(window, 18, 10, "Las instrucciones son simples, estas son:");
  mvwprintw(window, 19, 10, "Jugador 1, tus controles son las teclas W para moverta a arriba y S para abajo.");
  mvwprintw(window, 20, 10, "Jugador 2, tus controles son las flechas hacia arriba y hacia abajo para tener esos movimientos respectivamente.");
  mvwprintw(window, 21, 10, "Pulsa cualquier tecla para empezar!");
  wrefresh(window);

  getch(); 
  endwin();
}


int main(void) {
  instrucciones();

  int x = 0, y = 0;
  int max_y = 20, max_x = 20;
  int next_x = 0;
  int direction = 1;

  initscr();
  noecho();
  curs_set(FALSE);

  while(1) {
  clear();
  mvprintw(y, x, "o");
  refresh();

  usleep(DELAY);

  next_x = x + direction;

  if (next_x >= max_x || next_x < 0) {
    direction*= -1;
  } else {
    x+= direction;
  }
  }

  endwin();


}
