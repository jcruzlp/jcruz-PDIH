# Práctica 1

## Instalación de ncurses

He ejecutado los siguientes comandos desde la terminal:

`sudo su`: Realmente no es recomendable estar siempre como root porque como ya dijo el tío Ben, un gran poder conlleva una gran responsabilidad. Pero como estamos en local y ya tengo la manía, me ahorro poner `sudo` en cada comando.

`apt-get install libncurses5-dev libncursesw5-dev`: esto nos instala las librerías que nos hacen falta.
`apt-get update` y `apt-get upgrade`: esto realmente puede que no sea necesario, pero siempre es recomendable hacerlo cuando instalas algo por si tiene alguna dependencia imprevista.

En mi caso habían bastantes cosas que actualizar:
![image](https://user-images.githubusercontent.com/23319307/162232771-573d3f02-2ac2-4d69-b21c-7be48b11eaea.png)

Una vez hecho esto, deberíamos tener listo nuestra librería.

## Ejecución de programas de ejemplo

He añadido los programas de ejemplo del zip de *SWAD*.

Los he compilado de la forma indicada en el guión:
`gcc <archivo.c> -o <ejecutable> -lncurses`

Para `Hello.c` la compilación ha sido:
![image](https://user-images.githubusercontent.com/23319307/162235572-3b8d1453-614c-44a1-ac50-2b92c639943f.png)


Y una imagen de la ejecución es:  
![image](https://user-images.githubusercontent.com/23319307/162235641-55dbe29a-d38b-4c54-a758-5bc503948d02.png)


Para `Pelotita.c` la compilación ha sido:  
![image](https://user-images.githubusercontent.com/23319307/162235934-fe866061-8ea9-4080-9a94-e3222bf53ea3.png)


Y una imagen de la ejecución es:  
![image](https://user-images.githubusercontent.com/23319307/162235775-289e1ffe-e7cb-4185-baad-b1ff2618248b.png)
Este hay que salir de él haciendo `ctrl+c`.

Para `pruncurses.c` la compilación ha sido:  
![image](https://user-images.githubusercontent.com/23319307/162236187-e2c88943-72c1-47e9-9f9d-fa696b8bfca1.png)  
Este ha dado un warning, que no parece afectar al comportamiento y como buen warning es ignorado.

Y una imagen de la ejecución es:  
![image](https://user-images.githubusercontent.com/23319307/162236350-64e81637-33dc-4103-9b6e-187a78268bf4.png)


Para `ventana.c` la compilación ha sido:  
![image](https://user-images.githubusercontent.com/23319307/162236458-0faa5c64-9b59-4531-bf19-85f56d0e3e46.png)


Y una imagen de la ejecución es:  
![image](https://user-images.githubusercontent.com/23319307/162236520-a8e007c0-feee-4f55-a352-a4236fa9b6a4.png)

## Pong

Aquí empieza lo bueno, he seguido estas guías de cómo hacer un pong, ya que no soy muy bueno programando en C (Ni en nada que no sean scripts o XML e YML):  
- [Curso de daniweb](https://www.daniweb.com/programming/software-development/threads/75544/ncurses-and-pong)
- [Github de Donqustix](https://github.com/donqustix/pong)
- [Github de VicenteBolea](https://github.com/vicentebolea/Pong-curses)
- [Y este video de youtube](https://www.youtube.com/watch?v=_pH5xVN73VQ)
- Así como el ejemplo de la aventura.

A grandes rasgos he dopado el ejemplo de la ventana para que muestre todas las instrucciones que tiene nuestro juego y lo he metido en una función que es lo primero que tiene nuestro main:  
![image](https://user-images.githubusercontent.com/23319307/162411900-b9fdd092-259c-463d-bc86-2d89b965b1ac.png)

Y una ves que corremos el juego se ve así:  
![image](https://user-images.githubusercontent.com/23319307/162412068-db66e755-ac0f-46a4-bdea-dae70a1872aa.png)


Luego viene el grueso del programa como tal, donde utilizo las funciones que se han visto en los ejemplos y otras que he visto en las fuentes que he consultado, lo más reseñable del código es lo siguiente:  
```c++
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
    
```

La captura de teclado como se hace en el ejemplo de la aventura:
```c++
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
```  
Aquí cabe reseñar la pausa como en la práctica 1 que hace una interrupción por teclado y que si pulsas escape sale del juego, el fin lo puse porque si no solo te cierra la ventana, pero sigue corriendo.


Y el cómo pinta las cosas en pantalla:
```c++
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
```

Aquí cabe reseñar que según la dificultad que escojamos en el paso anterior te cambia el tamaño de la barra (Esto lo he hecho porque soy muy malo) también probé bajando la velocidad, pero llega un momento que es muy aburrido si lo juegas en pantalla completa porque tarda mucho en llegar.

Aquí algunas capturas de pantalla con la ejecución en distintos niveles de dificultad:  
![image](https://user-images.githubusercontent.com/23319307/162413672-3c6d2428-1025-413e-8b86-4c1bc8ad6fe3.png)

![image](https://user-images.githubusercontent.com/23319307/162413756-120c6e68-f934-4fcc-82f1-27d4acce5eea.png)


También he añadido un pequeño fragmento de código para llegar al final de la partida:  
```c+++
    //Comprobar puntuaciones y terminar juego
    if(jugador1.puntos == 7){
      fin++;
      endwin();
    }

    if(jugador2.puntos == 7){
      fin++;
      endwin();
    }
  }
```  
En su momento quería hacer que cada jugador tuviera un mensaje personalizado por eso están en dos funciones en vez de una, pero tuve un problema con el mensaje, así que de momento solo te congela la pantalla.

Y hasta aquí mi intento de hacer esto, hay muchas cosas a las que se pueden meter mano aún, como los mensajes o que cada jugador tenga un tamaño distinto de barra.
