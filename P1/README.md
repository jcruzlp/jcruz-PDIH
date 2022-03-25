# Práctica 1

## Documentación

He usado [esta documentación](https://github.com/johangardhage/dos-bcdemos) para instalar `DOSBOX` de forma correcta, junto con el manual de los seminarios.
También he usado [este PDF](http://www2.ift.ulaval.ca/~marchand/ift17583/dosints.pdf) para validar dudas sobre las funciones.

## Pruebas

Para las funciones `gotoxy()`:
```c
void gotoxy(int x, int y){
	union REGS inregs, outregs;
	inregs.h.ah = 2;
	inregs.h.dh = x;
	inregs.h.dl = y;
	inregs.h.bh = 0;
	int86(0x10, &inregs, &outregs);
}
```

`getche()`:
```c
int mi_getchar(){
	union REGS inregs, outregs;
	int caracter;
	inregs.h.ah = 1;
	int86(0x21, &inregs, &outregs);
	caracter = outregs.h.al;
	return caracter;
}

void cputchar(char c){
	union REGS inregs, outregs;
	inregs.h.ah = 9;
	inregs.h.al = c;
	inregs.h.bl = 4;
	inregs.h.bh = 0;
	inregs.x.cx = 1;
	int86(0x10, &inregs, &outregs);
}

void getche(){
	int tmp;
	tmp = mi_getchar();
	cputchar((char)tmp);
}
```

`setvideomode()`:
```c
void setvideomode(unsigned char modo){
	union REGS inregs, outregs; 
	inregs.h.ah = 0x00; 
	inregs.h.al = modo; 
	int86(0x10,&inregs,&outregs); 
}
```


Y `setcursortype(int size)`:
```c
void setcursortype(int size){
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(size){
		case 0: //invisible
			inregs.h.ch = 010;	
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
		break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
		break;
	}
	
	int86(0x10, &inregs, &outregs);
}
```
He realizado la siguiente prueba (es la que viene por defecto en el código subido):
![image](https://user-images.githubusercontent.com/23319307/160134627-faa01d36-699c-4ff5-92f5-a794f15fa91e.png)

Para modificar los colores de texto, he usado las siguientes funciones:
```c
void textcolor(char color){
	union REGS inregs, outregs;
	inregs.h.ah = 9;
	inregs.h.bl = color;
	inregs.x.cx = 1;
	int86(0x10, &inregs, &outregs);
}

void backgroundcolor(char color){
	union REGS inregs, outregs;
	inregs.h.ah = 9;
	inregs.h.bh = color;
	inregs.x.cx = 1;
	int86(0x10, &inregs, &outregs);
}

void cputchar(char c){
	union REGS inregs, outregs;
	inregs.h.ah = 9;
	inregs.h.al = c;
	inregs.h.bl = 4;
	inregs.h.bh = 0;
	inregs.x.cx = 1;
	int86(0x10, &inregs, &outregs);
}
```

La función cputchar del ejemplo los lleva hardcodeados, porque cuando la probé de la forma:
```c
void cputchar(char c){
	union REGS inregs, outregs;
	inregs.h.ah = 9;
	inregs.h.al = c;
	textcolor(4);
	backgroundcolor(0);
	inregs.x.cx = 1;
	int86(0x10, &inregs, &outregs);
}
```
Producía el siguiente efecto extraño en la salida:
![image](https://user-images.githubusercontent.com/23319307/160137059-c86a1ae7-739c-4e18-bb62-143e3a526c2b.png)

Para la función de `getvideomode()` he hecho lo siguiente:
```c
void getvideomode(){
	int modo;
	union REGS inregs, outregs; 
	inregs.h.ah = 0xF; 
	int86(0x10,&inregs,&outregs); 
	modo = outregs.h.al;
	return modo;
}
```

A modo curioso, no deja asignar las variables a la vez que las declaras, por lo que no se si es un peculiaridad de BorlandC o del propio lenguaje C.

La función `clrscr()` que ha sido la que he intentado hacer más por mi cuenta mirando documentación más allá del guón de la práctica ha salido así:
```c
void clrscr(){
	union REGS inregs, outregs;
	inregs.x.ax = 0;
	int86(0x10,&inregs,&outregs);  // INT 10 - AH = 00h VIDEO - SET VIDEO MODE
}
```
Aunque he de admitir que he tenido que usar muchas nomenclaturas y estructuras similares al resto, puesto que lo que he podido encontrar online es un poco difuso.


También he de pedir perdón porque muchas de las cosas que empecé haciendo en el repositorio (commits, PR...) están inglés, no me di cuenta hasta ahora que he empezado a añadirlo todo.
Perdón.
