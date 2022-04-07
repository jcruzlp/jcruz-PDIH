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


Y una imagen de la ejecuión es:
![image](https://user-images.githubusercontent.com/23319307/162235641-55dbe29a-d38b-4c54-a758-5bc503948d02.png)


Para `Pelotita.c` la compilación ha sido:
![image](https://user-images.githubusercontent.com/23319307/162235934-fe866061-8ea9-4080-9a94-e3222bf53ea3.png)


Y una imagen de la ejecuión es:
![image](https://user-images.githubusercontent.com/23319307/162235775-289e1ffe-e7cb-4185-baad-b1ff2618248b.png)
Este hay que salir de él haciendo `ctrl+c`.

Para `pruncurses.c` la compilación ha sido:
![image](https://user-images.githubusercontent.com/23319307/162236187-e2c88943-72c1-47e9-9f9d-fa696b8bfca1.png)
Este ha dado un warning, que no parece afectar al comportamiento y como buen warning es ignorado.

Y una imagen de la ejecuión es:
![image](https://user-images.githubusercontent.com/23319307/162236350-64e81637-33dc-4103-9b6e-187a78268bf4.png)


Para `ventana.c` la compilación ha sido:
![image](https://user-images.githubusercontent.com/23319307/162236458-0faa5c64-9b59-4531-bf19-85f56d0e3e46.png)


Y una imagen de la ejecuión es:
![image](https://user-images.githubusercontent.com/23319307/162236520-a8e007c0-feee-4f55-a352-a4236fa9b6a4.png)

