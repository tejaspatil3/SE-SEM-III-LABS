#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

int man(float x1,float y1,float x2,float y2){

 float Dx,Dy,delx,dely,x,y,len,i;
 //Calcuation
 Dx=x2-x1;
 Dy=y2-y1;
 if(Dx>Dy){len=Dx;}
 else{len=Dy;}

 delx=Dx/len;
 dely=Dy/len;

 x=x1+0.5;
 y=y1+0.5;

 for(i=1;i<=len;i++){
  x=x+delx;
  y=y+dely;
  putpixel(x,y,5);
  delay(5);}

  return 0;
}
int main(){
 int gd=DETECT,gm=0;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 float Dx,Dy,delx,dely,x,y,len,i;
 man(150,150,450,150);
 man(150,150,300,300);
 man(450,150,300,300);
 man(300,150,450,300);
 man(300,150,150,300);
 man(150,300,450,300);
 delay(3000);
 return 0;
}