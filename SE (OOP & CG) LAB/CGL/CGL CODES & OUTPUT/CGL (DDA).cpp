#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
int main(){
clrscr();
int gd=DETECT,gm=0;
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

 float x1,x2,y1,y2,Dx,Dy,delx,dely,x,y,len,i;
 //cout<<"Enter The values of (x1,y1),(x2,y2)";
 //cin>>x1>>y1>>x2>>y2;
x1=100;
y1=100;
x2=400;
y2=400;

 //cal
 Dx=x2-x1;
 Dy=y2-y1;
 if(Dx>Dy){len=Dx;}
 else{len=Dy;}

 delx=Dx/len;
 dely=Dy/len;

 x=x1+0.5;
 y=y1+0.5;

 for(i=1;i<=len;i++)
 {x=x+delx;
 y=y+dely;
 //cout<<x<<" , "<<y<<endl;
 putpixel(x,y,9);
 delay(50);
 }
 closegraph();
 return 0;
}



