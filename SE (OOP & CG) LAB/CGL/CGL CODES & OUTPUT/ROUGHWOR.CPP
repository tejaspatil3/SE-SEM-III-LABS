#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

void man(float x1,float y1,float x2,float y2);
 float x1,y1,x2,y2,Dx,Dy,p,x,y;
 Dx=x2-x1;
 Dy=y2-y1;
 x=x1;
 y=y1;
 p=2*Dy-Dx;
 while(x<x1){
  if (p>=0){
   putpixel(x,y,7);
   y=y+1;
   p=p+2*Dy-2*Dx;
   }
   else
   {
   putpixel(x,y,7);
   p=p+2*Dy;}
   x=x+1;
  }
}
int main(){
 int gd=DETECT,gm=0,error,x1,y1,x2,y2;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 x1=100,y1=100,x2=400,y2=400;
 man(x1,y1,x2,y2);
 return 0;
}