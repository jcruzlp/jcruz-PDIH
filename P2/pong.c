// gcc pong.puntos -o pong -lncurses

#include <stdlib.h>
#include <ncurses.h>

#define DELAY 6000
typedef struct{short int x, y, puntos; bool horizontal, vertical;} object;
int i = 0;

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
  mvwprintw(window, 21, 10, "Pulsa P para pausa.");
  mvwprintw(window, 21, 10, "Pulsa 1, 2 o 3 durante la partida para escoger la dificultad (de menor a mayor).");
  mvwprintw(window, 22, 10, "Pulsa ESC para salir.");
  mvwprintw(window, 23, 10, "Pulsa cualquier tecla para empezar!");
  wrefresh(window);

  getch(); 
  endwin();
}


int main(void) {
  instrucciones();

  object pantalla; 
  int cont = 0;
  int dificultad = 1;
  bool fin = 0;
  initscr();
  start_color();
  init_pair(1,COLOR_BLUE,COLOR_BLACK);
  keypad(stdscr,true);
  noecho();
  curs_set(0);
  getmaxyx(stdscr,pantalla.y,pantalla.x);
  object jugador1={pantalla.x-2,pantalla.y/2,0,false,false};
  object jugador2={1,pantalla.y/2,0,false,false};
  object pelotita={pantalla.x/2,pantalla.y/2,0,false,false};

  //Movimientos de pelotita y barras
  for (nodelay(stdscr,1); !fin; usleep(DELAY)){
    if (++cont%16==0){
      if ((pelotita.y==pantalla.y-1)||(pelotita.y==1))
        pelotita.vertical=!pelotita.vertical;
      if ((pelotita.x>=pantalla.x-2)||(pelotita.x<=2)){
        pelotita.horizontal=!pelotita.horizontal;
        if ((pelotita.y==jugador1.y-1)||(pelotita.y==jugador2.y-1)) {
          pelotita.vertical=false;
        } else if ((pelotita.y==jugador1.y+1)||(pelotita.y==jugador2.y+1)) {
          pelotita.vertical=true;
        } else if ((pelotita.y != jugador1.y) && (pelotita.y != jugador2.y)) {
          (pelotita.x>=pantalla.x-2) ? jugador1.puntos++: jugador2.puntos++;
          pelotita.x=pantalla.x/2;
          pelotita.y=pantalla.y/2;
        }
      }

      pelotita.x=pelotita.horizontal ? pelotita.x+1 : pelotita.x-1;
      pelotita.y=pelotita.vertical ? pelotita.y+1 : pelotita.y-1;

      if (jugador1.y<=1)
        jugador1.y=pantalla.y-2;
      if (jugador1.y>=pantalla.y-1)
        jugador1.y=2;
      if (jugador2.y<=1)
        jugador2.y=pantalla.y-2;
      if (jugador2.y>=pantalla.y-1)
        jugador2.y=2;
    }

    //Capturar de teclado
    switch (getch()) {
      case KEY_DOWN: jugador1.y++; break;
      case KEY_UP:   jugador1.y--; break;
      case 'w':      jugador2.y--; break;
      case 's':      jugador2.y++; break;
      case '1':      dificultad = 3; break;
      case '2':      dificultad = 2; break;
      case '3':      dificultad = 1; break;
      case 'p':      getchar(); break;
      case 0x1B:     endwin(); fin++; break;
    }

    erase();

    //Pintar puntutaciones
    mvprintw(2,pantalla.x/2-2,"%i | %i",jugador1.puntos,jugador2.puntos);
    mvvline(0,pantalla.x/2,ACS_VLINE,pantalla.y);
    attron(COLOR_PAIR(1));

    //Pintar la pelotita
    mvprintw(pelotita.y,pelotita.x,"o");

    //Pintar las barras
    for(i=-1;i<2*dificultad;i++){
      mvprintw(jugador1.y+i,jugador1.x,"#");
      mvprintw(jugador2.y+i,jugador2.x,"#");}
    attroff(COLOR_PAIR(1));
  }

}
