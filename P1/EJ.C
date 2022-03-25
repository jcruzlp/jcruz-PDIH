#include <stdio.h>
#include <dos.h>

void gotoxy(int x, int y){
	union REGS inregs, outregs;
	inregs.h.ah = 2;
	inregs.h.dh = x;
	inregs.h.dl = y;
	inregs.h.bh = 0;
	int86(0x10, &inregs, &outregs);
}


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

void mi_pausa(){
	union REGS inregs, outregs;
	inregs.h.ah = 8;
	int86(0x21, &inregs, &outregs);
}

void setvideomode(unsigned char modo){
	union REGS inregs, outregs; 
	inregs.h.ah = 0x00; 
	inregs.h.al = modo; 
	int86(0x10,&inregs,&outregs); 
}

void getvideomode(){
	int modo;
	union REGS inregs, outregs; 
	inregs.h.ah = 0xF; 
	int86(0x10,&inregs,&outregs); 
	modo = outregs.h.al;
	return modo;
}

void clrscr(){
	union REGS inregs, outregs;
	inregs.x.ax = 0;
	int86(0x10,&inregs,&outregs);  // INT 10 - AH = 00h VIDEO - SET VIDEO MODE
}

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

int main(){

	setvideomode(1);  // modo 1 -> 40x25 (letras grandes)

	printf("\nEn C. Pulsa una tecla...  ");

  mi_pausa();

	clrscr();

	setvideomode(3);

	printf("\n Hemos limpiado la pantalla, escribe un valor para que se te devuelva en la posicion 6,9 en color rojo. ");

	gotoxy(6,9);

	getche();

	setcursortype(0);

	printf("\n Hemos puesto el cursor en la tercera linea y hecho el cursor invisible ");

	mi_pausa();

	setvideomode(3);  // modo 3 -> 80x25 (letras pequeñas)

	return 0;
}
