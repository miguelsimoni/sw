#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include"c:\misdoc~1\prg\grafica.h"


#define TECLADO  0
#define RATON    1

/* niveles de dificultad. */
#define FACIL    2      /* aprendiz. */
#define MEDIO    3      /* caballero. */
#define DIFICIL  4      /* maestro. */

#define MAXS    25      /* maximo de estrellas. */
#define MAXE    4       /* maximo de enemigos. */


/* Puntaje actual y puntaje mas alto. */
int modo=VGA13h, nivel=MEDIO, score=0, hiscore=0;

/* limite de pantalla para las naves. */
int xmax=320, ymax=200;


/* Funciones del programa. */

/* Universo */
void universo(int n, int fin)
 {
  int i,x,y,color;
  for(i=0;i<n;i++)
    {
     x=rand()%xmax;
     y=rand()%ymax;
     color=rand()%3;
     if(!fin)
       switch(color)
         {
          case 0: color=WHITE;
                  break;
          case 1: color=LIGHTGRAY;
                  break;
          case 2: color=DARKGRAY;
                  break;
         }
     else
       switch(color)
         {
          case 0: color=LIGHTRED;
                  break;
          case 1: color=RED;
                  break;
          case 2: color=BROWN;
                  break;
         }
     pixel(x,y,color);
    }
 }


void logo(int i)
 {
  if(i) universo(75,0);
 /* lineas horizonales de STAR */
  line( 83, 40,150, 40,YELLOW); /*  1 */
  line(155, 40,175, 40,YELLOW); /*  2 */
  line(188, 40,228, 40,YELLOW); /*  3 */
  line( 98, 56,120, 56,YELLOW); /*  4 */
  line(135, 56,150, 56,YELLOW); /*  5 */
  line(205, 52,220, 52,YELLOW); /*  6 */
  line(160, 69,170, 69,YELLOW); /*  7 */
  line(205, 58,220, 58,YELLOW); /*  8 */
/*line(225, 70,230, 72,YELLOW); /*  9 */
  line( 60, 75, 95, 75,YELLOW); /* 10 */
  line(160, 76,170, 76,YELLOW); /* 11 */
  line(235, 75,260, 75,YELLOW); /* 12 */
  line( 60, 88,105, 88,YELLOW); /* 13 */
  line(120, 88,135, 88,YELLOW); /* 14 */
  line(140, 88,156, 88,YELLOW); /* 15 */
  line(173, 88,205, 88,YELLOW); /* 16 */
  line(225, 88,260, 88,YELLOW); /* 17 */
 /* lineas verticales de STAR */
  line( 60, 75, 60, 88,YELLOW); /* 18 */
  line(120, 56,120, 88,YELLOW); /* 19 */
  line(135, 56,135, 88,YELLOW); /* 20 */
  line(150, 40,150, 56,YELLOW); /* 21 */
  line(188, 40,188, 88,YELLOW); /* 22 */
  line(205, 52,205, 58,YELLOW); /* 23 */
  line(205, 75,205, 88,YELLOW); /* 24 */
  line(260, 75,260, 88,YELLOW); /* 25 */
 /* lineas oblicuas de STAR */
  line( 77, 60, 95, 75,YELLOW); /* 26 */
  line( 98, 56,118, 74,YELLOW); /* 27 */
  line(155, 40,140, 88,YELLOW); /* 28 */
  line(165, 53,160, 69,YELLOW); /* 29 */
  line(160, 77,156, 88,YELLOW); /* 30 */
  line(165, 53,170, 69,YELLOW); /* 31 */
  line(170, 76,173, 88,YELLOW); /* 32 */
  line(175, 40,188, 88,YELLOW); /* 33 */
  line(205, 75,225, 88,YELLOW); /* 34 */
  line(225, 70,235, 75,YELLOW); /* 35 */
 /* lineas horizontales de WARS */
  line( 60, 92, 78, 92,YELLOW); /*  1 */
  line( 85, 92, 95, 92,YELLOW); /*  2 */
  line(102, 92,120, 92,YELLOW); /*  3 */
  line(122, 92,146, 92,YELLOW); /*  4 */
  line(158, 92,192, 92,YELLOW); /*  5 */
  line(219, 92,260, 92,YELLOW); /*  6 */
  line(174,104,190,104,YELLOW); /*  7 */
  line(232,105,260,105,YELLOW); /*  8 */
  line(174,110,190,110,YELLOW); /*  9 */
  line(130,120,140,120,YELLOW); /* 10 */
  line(188,120,198,120,YELLOW); /* 11 */
  line(129,127,140,127,YELLOW); /* 12 */
  line(200,127,230,127,YELLOW); /* 13 */
  line( 72,140, 86,140,YELLOW); /* 14 */
  line( 97,140,110,140,YELLOW); /* 15 */
  line(112,140,127,140,YELLOW); /* 16 */
  line(144,140,175,140,YELLOW); /* 17 */
  line(195,140,240,140,YELLOW); /* 18 */
 /* lineas verticales de WARS */
  line(158, 92,158,140,YELLOW); /* 19 */
  line(174,104,174,110,YELLOW); /* 20 */
  line(260, 92,260,105,YELLOW); /* 21 */
  line(175,127,175,140,YELLOW); /* 22 */
 /* lineas oblicuas de WARS */
  line( 60, 92, 72,140,YELLOW); /* 23 */
  line( 78, 92, 82,110,YELLOW); /* 24 */
  line( 85, 92, 82,110,YELLOW); /* 25 */
  line( 91,126, 86,140,YELLOW); /* 26 */
  line( 91,126, 98,140,YELLOW); /* 27 */
  line( 95, 92, 98,110,YELLOW); /* 28 */
  line(102, 92, 98,110,YELLOW); /* 29 */
  line(120, 92,110,140,YELLOW); /* 30 */
  line(122, 92,112,140,YELLOW); /* 31 */
  line(135,104,130,120,YELLOW); /* 32 */
  line(129,127,127,140,YELLOW); /* 33 */
  line(135,104,140,120,YELLOW); /* 34 */
  line(140,127,144,140,YELLOW); /* 35 */
  line(146, 92,158,140,YELLOW); /* 36 */
  line(175,127,195,140,YELLOW); /* 37 */
  line(188,120,200,127,YELLOW); /* 38 */
  line(214,112,231,127,YELLOW); /* 39 */
  line(232,105,252,126,YELLOW); /* 40 */
 /* lineas curvas. */
  arco( 83, 51, 10, 90,245,YELLOW); /* a */
  arco(103, 74, 15,-90, -3,YELLOW); /* b */
  arco(220, 56,  2,-90, 90,YELLOW); /* c */
  arco(225, 56, 15,-90, 90,YELLOW); /* d */
  arco(190,108,  2,-90, 90,YELLOW); /* e */
  arco(193,107, 14,-90, 90,YELLOW); /* f */
  arco(219,102, 10, 90,245,YELLOW); /* g */
  arco(238,126, 15,-90, -3,YELLOW); /* h */
 }


/* Esperar. */
void esperar(double n)
 {
  double i;
  char key=0;
  for(i=0; i<n || key<1 ;i++)
     key=inport(0x60);
 }


/* Introduccion del juego. */
void intro(void)
 {
  clear(modo);

  gotoxy(4,12);
  printf("Hace mucho tiempo, en una galaxia");
  gotoxy(4,13);
  printf("muy lejana...");
/*
  gotoxy(4,12);
  printf("A long time ago in a galaxy far,");
  gotoxy(4,13);
  printf("far away...");
*/
  sleep(4);
  clear(modo);
  logo(1);
  sound(440);
  sleep(6);
  nosound();
  clear(modo);
  universo(75,0);
  sleep(2);
  gotoxy(15,2);
  printf("EPISODIO @");
  sleep(2);
  gotoxy(11,4);
  printf("Escape Del Imperio");
  sleep(2);
  gotoxy(4,7);
  printf("    ...una nave caza rebelde del    ");
  sleep(2);
  gotoxy(4,9);
  printf("tipo X-Wing se ha adentrado en el   ");
  sleep(2);
  gotoxy(4,11);
  printf("espacio con rumbo al punto de       ");
  sleep(2);
  gotoxy(4,13);
  printf("reunion.                            ");
  sleep(2);
  gotoxy(4,15);
  printf("    En el viaje, nuestro piloto se  ");
  sleep(2);
  gotoxy(4,17);
  printf("encuentra con un escuadron de naves ");
  sleep(2);
  gotoxy(4,19);
  printf("imperiales TIE-Fighter del cual debe");
  sleep(2);
  gotoxy(4,21);
  printf("librarse antes de llegar a dicho    ");
  sleep(2);
  gotoxy(4,23);
  printf("punto en el planeta Tatooine.       ");
  sleep(4);
 }


/* Dibujar nave X-Wing. */
void xwing(int x, int y)
 {
 /* punta. */
  pixel(x,y-9,WHITE);
 /* chasis. */
  fillrectangle(x-1,y-8,x+1,y-1,WHITE);
 /* alas. */
  fillrectangle(x-7,y+2,x+7,y+5,WHITE);
 /* turbina izquierda. */
  fillrectangle(x-3,y-1,x-2,y+5,LIGHTRED);
 /* turbina derecha. */
  fillrectangle(x+2,y-1,x+3,y+5,LIGHTRED);
 /* deflector izquierdo. */
  fillrectangle(x-3,y+6,x-2,y+7,YELLOW);
 /* deflector derecho. */
  fillrectangle(x+2,y+6,x+3,y+7,YELLOW);
 /* cabina. */
  fillrectangle(x-1,y,x+1,y+3,LIGHTBLUE);
 /* canon izquierdo. */
  fillrectangle(x-7,y-2,x-7,y+1,WHITE);
 /* canon izquierdo. */
  fillrectangle(x+7,y-2,x+7,y+1,WHITE);
 }


/* Borrar nave X-Wing. */
void delxwing(int x, int y)
 {
 /* punta. */
  pixel(x,y-9,BLACK);
 /* chasis. */
  fillrectangle(x-1,y-8,x+1,y-1,BLACK);
 /* alas. */
  fillrectangle(x-7,y+2,x+7,y+5,BLACK);
 /* turbina izquierda. */
  fillrectangle(x-3,y-1,x-2,y+5,BLACK);
 /* turbina derecha. */
  fillrectangle(x+2,y-1,x+3,y+5,BLACK);
 /* deflector izquierdo. */
  fillrectangle(x-3,y+6,x-2,y+7,BLACK);
 /* deflector derecho. */
  fillrectangle(x+2,y+6,x+3,y+7,BLACK);
 /* cabina. */
  fillrectangle(x-1,y,x+1,y+3,BLACK);
 /* canon izquierdo. */
  fillrectangle(x-7,y-2,x-7,y+1,BLACK);
 /* canon derecho. */
  fillrectangle(x+7,y-2,x+7,y+1,BLACK);
 }


/* Dibujar nave TIE-Fighter. */
void tie(int x, int y, int color)
 {
 /* chasis central. */
  fillrectangle(x-2,y-2,x+2,y+2,color);
 /* chasis superior. */
  fillrectangle(x-1,y-3,x+1,y-3,color);
 /* chasis inferior. */
  fillrectangle(x-1,y+3,x+1,y+3,color);
 /* chasis izquierdo. */
  fillrectangle(x-3,y-1,x-3,y+1,color);
 /* chasis derecho. */
  fillrectangle(x+3,y-1,x+3,y+1,color);
 /* cabina. */
  fillrectangle(x-1,y-1,x+1,y+1,BLUE);
 /* ala izquierda. */
  fillrectangle(x-6,y,x-4,y,color);
 /* ala derecha. */
  fillrectangle(x+4,y,x+6,y,color);
 /* aleron izquierdo. */
  fillrectangle(x-7,y-4,x-7,y+4,color);
 /* aleron derecho. */
  fillrectangle(x+7,y-4,x+7,y+4,color);
 /* aleron superior izquierdo. */
  pixel(x-5,y-8,color);
  pixel(x-5,y-7,color);
  pixel(x-6,y-6,color);
  pixel(x-6,y-5,color);
 /* aleron superior derecho. */
  pixel(x-5,y+8,color);
  pixel(x-5,y+7,color);
  pixel(x-6,y+6,color);
  pixel(x-6,y+5,color);
 /* aleron inferior izquierdo. */
  pixel(x+5,y-8,color);
  pixel(x+5,y-7,color);
  pixel(x+6,y-6,color);
  pixel(x+6,y-5,color);
 /* aleron inferior derecho. */
  pixel(x+5,y+8,color);
  pixel(x+5,y+7,color);
  pixel(x+6,y+6,color);
  pixel(x+6,y+5,color);
 }


/* Borrar nave TIE-Fighter. */
void deltie(int x, int y, int color)
 {
 /* chasis central. */
  fillrectangle(x-2,y-2,x+2,y+2,color);
 /* chasis superior. */
  fillrectangle(x-1,y-3,x+1,y-3,color);
 /* chasis inferior. */
  fillrectangle(x-1,y+3,x+1,y+3,color);
 /* chasis izquierdo. */
  fillrectangle(x-3,y-1,x-3,y+1,color);
 /* chasis derecho. */
  fillrectangle(x+3,y-1,x+3,y+1,color);
 /* cabina. */
  fillrectangle(x-1,y-1,x+1,y+1,color);
 /* ala izquierda. */
  fillrectangle(x-6,y,x-4,y,color);
 /* ala derecha. */
  fillrectangle(x+4,y,x+6,y,color);
 /* aleron izquierdo. */
  fillrectangle(x-7,y-4,x-7,y+4,color);
 /* aleron derecho. */
  fillrectangle(x+7,y-4,x+7,y+4,color);
 /* aleron superior izquierdo. */
  pixel(x-5,y-8,color);
  pixel(x-5,y-7,color);
  pixel(x-6,y-6,color);
  pixel(x-6,y-5,color);
 /* aleron superior derecho. */
  pixel(x-5,y+8,color);
  pixel(x-5,y+7,color);
  pixel(x-6,y+6,color);
  pixel(x-6,y+5,color);
 /* aleron inferior izquierdo. */
  pixel(x+5,y-8,color);
  pixel(x+5,y-7,color);
  pixel(x+6,y-6,color);
  pixel(x+6,y-5,color);
 /* aleron inferior derecho. */
  pixel(x+5,y+8,color);
  pixel(x+5,y+7,color);
  pixel(x+6,y+6,color);
  pixel(x+6,y+5,color);
 }


/* Disparo laser. */
void laser(int x, int y, int color)
 {
  line(x,10,x,y-10,color);
  line(x,10,x,y-10,BLACK);
 }


/* Disparo laser doble. */
void laserdouble(int x, int y, int color)
 {
 /* dibujar laser izquierdo. */
  line(x-7,10,x-7,y-2,color);
 /* dibujar laser derecho. */
  line(x+7,10,x+7,y-2,color);
 /* borrar laser izquierdo. */
  line(x-7,10,x-7,y-2,BLACK);
 /* borrar laser derecho. */
  line(x+7,10,x+7,y-2,BLACK);
 }


/* Explosion. */
void explosion(int x, int y, int del)
 {
  int i,color,rayos,radioext,radioint;
  for(i=0;i<5;i++)
    {
     radioext=rand()%4+16;
     radioint=rand()%4+3;
     rayos=rand()%3+6;
     if(rand()%2)
       color=YELLOW;
     else
       color=LIGHTRED;
     star(x,y,radioext,radioint,rayos,color);
     if(del) star(x,y,radioext,radioint,rayos,BLACK);
     if(i%2)
       {
        sound(300);
        delay(5);
       }
     else
       {
        sound(100);
        delay(5);
       }
    }
  nosound();
 }


/* Salto al hiper-espacio. */
void hiperespacio(int x, int y)
 {
  int n,i,xs[50],ys[50],cs[50];     /* coordenadas de las estrellas. */
 /* generar coordenadas de las estrellas. */
  for(i=0;i<50;i++)
    {
     xs[i]=rand()%xmax;
     ys[i]=rand()%ymax;
     cs[i]=rand()%3;
     switch(cs[i])
       {
        case 0: cs[i]=WHITE;
                break;
        case 1: cs[i]=LIGHTGRAY;
                break;
        case 2: cs[i]=DARKGRAY;
                break;
       }
    }
  for(n=0;n<400;n++)
    {
     for(i=0;i<50;i++)
        pixel(xs[i],ys[i]++,cs[i]);
     if(y>-8)
      {
       xwing(x,y);
       y-=2;
      }
     sound(n+200);
    }
  nosound();
 }


/* Pausar el juego. */
void pause(void)
 {
  gotoxy(18,12);
  printf("pausa");
  getch();
  gotoxy(18,12);
  printf("     ");
 }


/* Destruccion del enemigo. */
int destruir(int x, int y, int *xe, int *ye)
 {
  int i,destruidos=0;
  for(i=0;i<nivel;i++)
    {
     if(x>=xe[i]-5 && x<=xe[i]+5 && ye[i]<y)
       {
        explosion(xe[i],ye[i],1);
        ye[i]=ymax;
        score+=5*(i+1);
        if(score>hiscore)
           hiscore=score;
        destruidos++;
       }
    }
  return destruidos;
 }


/* Juego. */
void juego(int mando)
 {
  char key;
  int i,j,
      win=0,
      generados=0,  /* contador de enemigos generados. */
      destruidos=0, /* contador de enemigos destruidos. */
      x=xmax/2,     /* coordenada x del x-wing. (valor asignado = X inicial) */
      y=ymax-20,    /* coordenada y del x-wing. (valor asignado = y inicial) */
      xs[MAXS],     /* coordenada x de las estrellas. */
      ys[MAXS],     /* coordenada y de las estrellas. */
      cs[MAXS],     /* colores de las estrellas. */
      xe[MAXE],     /* coordenada x del tie-fighter. */
      ye[MAXE],     /* coordenada y del tie-fighter. */
      ce[MAXE],     /* color del tie-fighter. */
      xea[MAXE],    /* coordenada x anterior del tie-fighter. */
      yea[MAXE];    /* coordenada y anterior del tie-fighter. */

  /* inicializar coordenadas de las naves enemigas. */
  for(i=0;i<MAXE;i++)
     {
      xe[i]=0;
      ye[i]=ymax;
      ce[i]=0;
      xea[i]=0;
      yea[i]=0;
     }

  clear(modo);
  if(mtest && mando)
    {
     mlimit(10,10,xmax-10,ymax-10);
     msituar(x,y);
    }
 /* generar coordenadas de las estrellas. */
  for(i=0;i<MAXS;i++)
    {
     xs[i]=rand()%xmax;
     ys[i]=rand()%ymax;
     cs[i]=rand()%3;
     switch(cs[i])
       {
        case 0: cs[i]=WHITE;
                break;
        case 1: cs[i]=LIGHTGRAY;
                break;
        case 2: cs[i]=DARKGRAY;
                break;
       }
    }
  score=0;
 /* bucle indefinido del juego, hasta que se presione escape. */
  do{
     gotoxy(1,1);
     printf("Puntaje= %d",score);
     gotoxy(20,1);
     printf("Mas alto= %d",hiscore);
     gotoxy(1,24);
     printf("%d/%d",destruidos,generados);
     for(i=0;i<MAXS;i++)
       {
        pixel(xs[i],ys[i],cs[i]);
        ys[i]+=3;
        pixel(xs[i],ys[i],cs[i]);
        pixel(xs[i],ys[i]-3,BLACK);
       }
     key=inport(0x60);  /* Leer entrada del teclado. */
     switch(key)
       {
        case 25: /* P */
             pause();
             break;
        case SPACE:
             laser(x,y,LIGHTRED);
            /* destruccion de la nave enemiga */
             destruidos+=destruir(x,y,xe,ye);
             break;
        case UP:    /* Cursor arriba */
             if(y>10)
               y-=3;
             break;
        case LEFT:  /* Cursor izquierda */
             if(x>10)
               x-=3;
             break;
        case RIGHT: /* Cursor derecha */
             if(x<xmax-10)
               x+=3;
             break;
        case DOWN:  /* Cursor abajo */
             if(y<ymax-10)
               y+=3;
             break;
       }

    /* si el mando es el raton, colocar la nave en las coordenadas del puntero. */
     if(mtest && mando)
       {
        x=mxpos();
        y=mypos();
       /* destruccion de la nave enemiga */
        if(mclick())
          {
           if(mclick()==MLEFT)
             laser(x,y,LIGHTGREEN);
           if(mclick()==MRIGHT)
             laserdouble(x,y,LIGHTRED);
           destruidos+=destruir(x,y,xe,ye);
          }
       }

    /* dibujar nave. */
     xwing(x,y);

    /* generar y dibujar naves enemigas. */
     for(i=0;i<nivel;i++)
       {
       /* generar nave enemiga. */
        if(ye[i]>=ymax)
          {
           xe[i]=rand()%(xmax-10)+5;
           ye[i]=10;
           ce[i]=rand()%8+8;
           if(ce[i]==DARKGRAY) ce[i]=LIGHTGRAY;
           generados++;
          }
       /* dibujar nave enemiga. */
        tie(xe[i],ye[i],ce[i]);
        yea[i]=ye[i];
        ye[i]+=1+i;
        xea[i]=xe[i];
        switch(rand()%3)
          {
           case 0: break;
           case 1: if(xe[i]<xmax-15)
                     xe[i]+=2+i;
                   break;
           case 2: if(xe[i]>15)
                     xe[i]-=2-i;
                   break;
          }
       }

    /* borrar nave. */
     delxwing(x,y);

    /* borrar naves enemigas. */
     for(i=0;i<nivel;i++)
       deltie(xea[i],yea[i],BLACK);

    /* choque y muerte con nave enemiga. */
     for(i=0;i<nivel;i++)
        if(x>xe[i]-15 && x<xe[i]+15 && y>ye[i]-15 && y<ye[i]+15)
          {
           for(j=0;j<3;j++)
             {
              explosion(xe[i],ye[i],0);
              explosion(x,y,0);
             }
           key=ESC;
          }

    /* ganar la partida. */
     if(destruidos==nivel*25)
       {
        hiperespacio(x,y);
        win=1;
        key=ESC;
       }

    }while(key!=ESC);  /* mientras no se pulse ESC. */

  if(win)
    {
     sleep(2);
     gotoxy(13,10);
     printf("­FELICITACIONES!");
     gotoxy(10,12);
     printf("LLEGASTE A TATOOINE...");
     gotoxy(14,14);
     printf("puntaje = %d",score);
    }
  else
    {
     universo(200,1);
     sleep(2);
     gotoxy(4,11);
     printf("NO LLEGASTE AL PUNTO DE REUNION...");
     gotoxy(14,13);
     printf("puntaje = %d",score);
    }
  getch();
  clear(modo);
  logo(0);
  gotoxy(15,12);
  printf("FIN DE JUEGO");
  getch();
 }


/* Nivel de dificultad. */
int dificultad(void)
 {
  char opcion[2]="0";
  clear(modo);
  logo(0);
  gotoxy(11,10);
  printf("nivel de dificultad:");
  gotoxy(14,12);
  printf("<1> aprendiz.");
  gotoxy(14,13);
  printf("<2> caballero.");
  gotoxy(14,14);
  printf("<3> maestro.");
  do{
     opcion[0]=getch();
    }while(strpbrk(opcion,"123")==NULL);
  switch(opcion[0])
    {
     case '1': return FACIL;
     case '2': return MEDIO;
     case '3': return DIFICIL;
    }
 }


/* Controlador o mando. */
int control(void)
 {
  char opcion[2]="0";
  clear(modo);
  logo(0);
  gotoxy(17,10);
  printf("control:");
  gotoxy(15,12);
  printf("<1> teclado.");
  gotoxy(15,13);
  printf("<2> raton.");
  do{
     opcion[0]=getch();
     if(opcion[0]=='2' && !mtest())
       {
        gotoxy(10,20);
        printf("raton no instalado.");
        opcion[0]='1';
        getch();
       }
    }while(strpbrk(opcion,"12")==NULL);
  return(atoi(opcion)-1);
 }


/* Resolucion de la pantalla. */
int resolucion(void)
 {
  char opcion[2]="0";
  clear(modo);
  logo(0);
  gotoxy(16,10);
  printf("opciones:");
  gotoxy(11,12);
  printf("<1> 320x200 pixels.");
  gotoxy(11,13);
  printf("<2> 640x480 pixels.");
  do{
     opcion[0]=getch();
    }while(strpbrk(opcion,"12")==NULL);
  if(opcion[0]=='1')
    {
     xmax=320;
     ymax=200;
     return VGA13h;
    }
  else
    {
     xmax=640;
     ymax=480;
     return VGA12h;
    }
 }


/* Opciones. */
int opciones(void)
 {
  char opcion[2]="0";
  clear(modo);
  logo(0);
  gotoxy(16,10);
  printf("opciones:");
  gotoxy(9,12);
  printf("<1> nivel de dificultad.");
  gotoxy(9,13);
  printf("<2> controlador/mando.");
  gotoxy(9,14);
  printf("<3> resolucion.");
  do{
     opcion[0]=getch();
    }while(strpbrk(opcion,"123")==NULL);
  return(atoi(opcion));
 }


/* Ayuda. */
void ayuda(void)
 {
  clear(modo);
  logo(0);
  gotoxy(18,3);
  printf("ayuda:");
  gotoxy(3,6);
  printf("teclado:");
  gotoxy(5,8);
  printf("teclas de flechas = movimientos.");
  gotoxy(5,10);
  printf("barra espaciadora = laser rojo.");
  gotoxy(5,12);
  printf("Esc = abandonar partida.");
  gotoxy(5,14);
  printf("P = pausa.");
  gotoxy(5,16);
  printf("otra tecla = continuar.");
  gotoxy(3,18);
  printf("raton:");
  gotoxy(5,20);
  printf("boton izquierdo = laser verde.");
  gotoxy(5,22);
  printf("boton derecho = laser rojo doble.");
  getch();
 }


/* Creditos. */
void creditos(void)
 {
  clear(modo);
  logo(0);
  gotoxy(15,10);
  printf("creado por:");
  gotoxy(14,13);
  printf("Miguel Simoni");
  gotoxy(15,15);
  printf("Tomas Gomez");
  getch();
 }


/* Menu principal. */
int menu(void)
 {
  char opcion[2]="0";
  clear(modo);
  logo(0);
  gotoxy(14,11);
  printf("<1> comenzar.");
  gotoxy(14,12);
  printf("<2> opciones.");
  gotoxy(14,13);
  printf("<3> ayuda.");
  gotoxy(14,14);
  printf("<4> creditos.");
  gotoxy(14,15);
  printf("<0> salir.");
  gotoxy(10,22);
  printf("Puntaje mas alto = %d",hiscore);
  do{
     opcion[0]=getch();
    }while(strpbrk(opcion,"01234")==NULL);
  return(atoi(opcion));
 }


void main(void)
 {
  int opcion,mando=RATON;
  videomode(modo);
  nosound();
  intro();
  do{
     clear(modo);
	 opcion=menu();
     switch(opcion)
       {
        case 1: juego(mando);
                break;
        case 2: switch(opciones())
                  {
                   case 1: nivel=dificultad();
                           break;
                   case 2: mando=control();
                           break;
                   case 3: modo=resolucion();
                           videomode(modo);
                           break;
                  }
                break;
        case 3: ayuda();
                break;
        case 4: creditos();
                break;
        case 0: break;
        default: break;
       }
    }while(opcion);
  videomode(TEXT);
  nosound();
  printf("\nGracias por jugar STAR WARS Episode @...\n\n");
 }


/*
void main(void)
 {
  videomode(VGA13h);
  nosound();
  juego(RATON);
  videomode(TEXT);
  nosound();
 }
*/
