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


Y una imagen de la ejeción es:


Para `Pelotita.c` la compilación ha sido:


Y una imagen de la ejeción es:


Para `pruncurses.c` la compilación ha sido:


Y una imagen de la ejeción es:


Para `ventana.c` la compilación ha sido:


Y una imagen de la ejeción es:
