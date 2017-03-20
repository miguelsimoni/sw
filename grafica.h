/* Libreria de funciones graficas. */

#include<dos.h>
#include<math.h>


/* Interrupciones. */
#define VIDEO_INT    0x10       /* Interrupcion del video. */
#define KEYB_INT     0x09       /* Interrupcion del teclado. */
#define MOUSE_INT    0x33       /* Interrupcion del raton. */
#define JOY_INT      0x27       /* Interrupcion del joystick. */


/* Modo texto. */
#define TEXT 0x03           /* 25 lineas x 80 columnas x 16 colores */


/* Modos de video. */
#define VGA13h 0x13         /* 320x200x256 */
#define VGA12h 0x12         /* 640x480x16 */


/* Constantes matematicas. */
#define pi 3.141592654
#define e  2.718281828


/* Definicion de constantes para las teclas. */
#define ESC     1
#define BKSPC  14
#define TAB    15
#define ENTER  28
#define CTRL   29
#define LSHIFT 42
#define RSHIFT 54
#define ALT    56
#define SPACE  57

#define UP     72
#define LEFT   75
#define RIGHT  77
#define DOWN   80

#define INSERT 82
#define DELETE 83
#define HOME   71
#define END    79
#define PGUP   73
#define PGDOWN 81


/* Botones del raton. */
#define MNONE  0
#define MLEFT  1
#define MRIGHT 2


/* FUNCIONES DE VIDEO. */

/* Inicializar modo de video. */
void videomode(int mode)
 {
  union REGS in,out;
  in.h.ah = 0x00;
  in.h.al = mode;
  int86(VIDEO_INT,&in,&out);     /* modo de video por defecto: 3h. */
 }


/* Activar pixel. */
void pixel(int x, int y, int color)
 {
  union REGS in,out;
  in.h.ah = 0x0C;
  in.h.al = color;      /* 0h-Fh (16 colores) o 00h-FFh (256 colores). */
  in.x.bx = 0x00;
  in.x.cx = x;
  in.x.dx = y;
  int86(VIDEO_INT,&in,&out);
 }


/* Tomar un pixel. */
int getpixel(int x, int y)
 {
  union REGS in,out;
  in.h.ah = 0x00;
  in.x.cx = x;
  in.x.dx = y;
  int86(VIDEO_INT,&in,&out);
  return(out.h.al);
 }


/* Rectangulo. */
void rectangle(int x1, int y1, int x2, int y2, int color)
 {
  int i;
  for(i=0; i<=abs(x2-x1) ;i++)
    {/* dibujar los lados horizontales. */
     pixel(x1+i,y1,color);
     pixel(x1+i,y2,color);
    }
  for(i=0; i<=abs(y2-y1) ;i++)
    {/* dibujar los lados verticales. */
     pixel(x1,y1+i,color);
     pixel(x2,y1+i,color);
    }
 }


/* Rectangulo relleno. */
void fillrectangle(int x1, int y1, int x2, int y2, int color)
 {
  int i,j;
  for(j=0; j<=abs(y2-y1) ;j++)
    for(i=0; i<=abs(x2-x1) ;i++)
      pixel(x1+i,y1+j,color);
 }


/* Linea recta. */
void line(int x1, int y1, int x2, int y2, int color)
 {
  int dx,dy,i,s=1;
  float m;      /* pendiente de la recta. */
  dx=x2-x1;     /* distancia horizontal. */
  dy=y2-y1;     /* distancia vertical. */
  if( x1!=x2 && y1!=y2 )
    if( abs(dx) >= abs(dy) )
      {/* la linea es mas horizontal que vertical. */
       if(dx<0)  s=-1;
       m=(float)dy/dx;
       for(i=0; i != dx ;i+=s)
         pixel(i+x1,m*i+y1,color);
      }
    else
      {/* la linea es mas vertical que horizontal. */
       if(dy<0)  s=-1;
       m=(float)dx/dy;
       for(i=0; i != dy ;i+=s)
         pixel(m*i+x1,i+y1,color);
      }
  else
    if(y1==y2)  /* la linea es horizontal. */
      for(i=0; i<dx ;i++)
        pixel(i+x1,y1,color);
    else
      if(x1==x2)  /* la linea es vertical. */
        for(i=0; i<dy ;i++)
          pixel(x1,i+y1,color);
 }


/* Circunferencia. */
void circle(int xc, int yc, int r, int color)
 {
  float da,ca,sa,x,y,xp,yp;
  da=0.0005;
  ca=cos(da);
  sa=sin(da);
  x=r;
  y=0;
  while(xc<(x+xc))
    {
     xp= x*ca - y*sa;
     yp= y*ca + x*sa;
     pixel( xp+xc, yp+yc,color);
     pixel(-xp+xc, yp+yc,color);
     pixel(-xp+xc,-yp+yc,color);
     pixel( xp+xc,-yp+yc,color);
     x= xp;
     y= yp;
    }
 }


/* Circulo. */
void fillcircle(int xc, int yc, int r, int color)
 {
  float da,ca,sa,x,y,xp,yp;
  da=0.05;
  ca=cos(da);
  sa=sin(da);
  x=r;
  y=0;
  while(xc<(x+xc))
    {
     xp= x*ca - y*sa;
     yp= y*ca + x*sa;
     line(xc,yc, xp+xc, yp+yc,color);
     line(xc,yc,-xp+xc, yp+yc,color);
     line(xc,yc,-xp+xc,-yp+yc,color);
     line(xc,yc, xp+xc,-yp+yc,color);
     x= xp;
     y= yp;
    }
 }


/* Arco de circunferencia. */
void arco(int xc, int yc, int r, float ai, float af, int color)
 {
  float a,da,ca,sa,x,y,xp,yp;
  ai=ai*pi/180;
  af=af*pi/180;
  da=0.0005;
  ca=cos(da);
  sa=sin(da);
  x=r*cos(ai);
  y=r*sin(ai);
  a=ai;
  while(a<af)
    {
     xp= x*ca - y*sa;
     yp= y*ca + x*sa;
     pixel(xp+xc,-yp+yc,color);
     a+=da;
     x= xp;
     y= yp;
    }
 }


/* Estrella. */
void star(int xc, int yc, int rext, int rint, int p, int color)
 {
  float a=-pi/2,daext,daint,x,y,xp,yp;
  int i;
  daext=(2*pi)/p;
  daint=daext/2;
  for(i=1; i<=p ;i++)
    {
     x = rext*cos(a);
     y = rext*sin(a);
     xp= rint*cos(a-daint);
     yp= rint*sin(a-daint);
     line(x+xc,y+yc,xp+xc,yp+yc,color);
     xp= rint*cos(a+daint);
     yp= rint*sin(a+daint);
     line(x+xc,y+yc,xp+xc,yp+yc,color);
     a=a+daext;
    }
 }


/* Limpiar pantalla. */
void clear(int mode)
 {
  int i,j;
  if(mode==VGA13h)
    for(j=0; j<=25 ;j++)
      for(i=0; i<=320 ;i++)
        {
         pixel(i,j,BLACK);
         pixel(i,j+25,BLACK);
         pixel(i,j+50,BLACK);
         pixel(i,j+75,BLACK);
         pixel(i,j+100,BLACK);
         pixel(i,j+125,BLACK);
         pixel(i,j+150,BLACK);
         pixel(i,j+175,BLACK);
        }
  else
    for(j=0; j<=25 ;j++)
      for(i=0; i<=640 ;i++)
        {
         pixel(i,j,BLACK);
         pixel(i,j+25,BLACK);
         pixel(i,j+50,BLACK);
         pixel(i,j+75,BLACK);
         pixel(i,j+100,BLACK);
         pixel(i,j+125,BLACK);
         pixel(i,j+150,BLACK);
         pixel(i,j+175,BLACK);
         pixel(i,j+200,BLACK);
         pixel(i,j+225,BLACK);
         pixel(i,j+250,BLACK);
         pixel(i,j+275,BLACK);
         pixel(i,j+300,BLACK);
         pixel(i,j+325,BLACK);
         pixel(i,j+350,BLACK);
         pixel(i,j+375,BLACK);
         pixel(i,j+400,BLACK);
         pixel(i,j+425,BLACK);
         pixel(i,j+450,BLACK);
         pixel(i,j+475,BLACK);
        }
 }


/* FUNCIONES DEL MOUSE. */

/* Testear el raton. */
int mtest(void)
 {
  union REGS in,out;
  in.x.ax = 0x0;
  int86(MOUSE_INT,&in,&out);
  if(out.x.ax > 0)
    return out.x.bx;  /* numero de botones. */
  else
    return 0;  /* no hay raton instalado. */
 }


/* Mostrar el puntero del raton. */
void mver(void)
 {
  union REGS in,out;
  in.x.ax = 0x1;
  int86(MOUSE_INT,&in,&out);
 }


/* Ocultar el puntero del raton. */
void mocultar(void)
 {
  union REGS in,out;
  in.x.ax = 0x2;
  int86(MOUSE_INT,&in,&out);
 }


/* Retorna la coordenada x (horizontal) de la posicion del raton. */
int mxpos(void)
 {
  union REGS in,out;
  in.x.ax = 0x3;
  int86(MOUSE_INT,&in,&out);
  return out.x.cx;
 }


/* Retorna la coordenada y (vertical) de la posicion del raton. */
int mypos(void)
 {
  union REGS in,out;
  in.x.ax = 0x3;
  int86(MOUSE_INT,&in,&out);
  return out.x.dx;
 }


/* Situar el raton en las coordenadas (x,y) deseadas. */
void msituar(int x, int y)
 {
  union REGS in,out;
  in.x.ax = 0x4;
  in.x.cx = x;
  in.x.dx = y;
  int86(MOUSE_INT,&in,&out);
 }


/* Boton presionado. */
int mclick(void)
 {
  union REGS in,out;
  in.x.ax = 0x3;
  in.x.bx = 0;
  int86(MOUSE_INT,&in,&out);
  return out.x.bx;  /* 0:ninguno. / 1:izquierdo. / 2:derecho. */
 }


/* Limitamos el espacio de movilidad del rat¢n.  */
void mlimit(int sup, int izq, int inf, int der)
 {
  union REGS in,out;
  in.x.ax = 0x7;
  in.x.cx = sup;
  in.x.dx = inf;
  int86(0x33,&in,&out);
  in.x.ax = 0x8;
  in.x.cx = izq;
  in.x.dx = der;
  int86(0x33,&in,&out);
 }
