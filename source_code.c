#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
   int pendulum = 0;
	int x=350,y=100,r=35;
	float h_a,m_a,s_a;
	int hour,min,sec,temphr=0;
	char tempstr[1],hstring[2];
	float angle,xcor1,ycor1;
void drawpendulum(){
	setcolor(YELLOW);
	setfillstyle(1,WHITE);
	if(pendulum == 0) {
	//pendulum  hand -rt
	line(x,135,x+20,200);
	line(x+5,135,x+25,200);
	fillellipse(x+23,200,8,8);
	}
	if(pendulum ==1) {
	//pendulum hand -lft
	line(x,135,x-20,200);
	line(x+5,135,x-15,200);
	fillellipse(x-18,200,8,8);
	}
	setcolor(WHITE);

}
void drawclock(){
		int i;
		circle(x,y,r+20);
		setfillstyle(1,3);
		  fillellipse(x,y,r+10,r+10);
		  setfillstyle(0,0);
		  fillellipse(x,y,3,3);
		for(i = 1 ;i<=12;i++){
			angle = ((i)*30 * 3.1415/180);
		//coordinates to print the numbers
			xcor1 = x+r*sin(angle);
			ycor1 = y-r*cos(angle);
			itoa(i,tempstr,10);
			settextstyle(2,0,2);
			outtextxy(xcor1,ycor1,tempstr);
		}
		settextstyle(0,0,0);
		setcolor(WHITE);

}
void drawtable(){
setcolor(15);setfillstyle(1,LIGHTGRAY);
//table body
		bar3d(300,460,650,470,80,1);
		setcolor(WHITE);
		setfillstyle(1,15);
    //legs
	 bar3d(300,470,330,490,0,3);
	  bar3d(630,470,650,490,80,80);
	 setfillstyle(0,0);
	  setlinestyle(0,0,2);
    //screen
	  bar3d(350,250,550,380,4,4);
	  settextstyle(2,0,0);
	  outtextxy(355,253,"________________________________");
	  outtextxy(355,270,"MADE BY BIPLOP GIRI");
	  outtextxy(355,290,"________________________________");
	  setfillstyle(3,15);
	  rectangle(355,310,450,370);
	  bar(355,310,450,370);
	  bar(455,310,545,370);
	  setfillstyle(0,0);
    //cpu
    setfillstyle(1,0);
    bar3d(560,250,620,440,30,1);
    setfillstyle(5,15);
    bar(560,300,620,350);
    setfillstyle(1,15);
    bar(560,350,620,370);
    //top
    bar(560,250,620,270);
    //bottom
    bar(560,420,620,440);
    fillellipse(570,390,9,9);
    setfillstyle(1,15);
    //legs
    bar(430,380,460,410);
    bar(400,410,490,413);
    //keyboard
    bar3d(355,430,500,435,20,3);
    }
void drawphotos(){
//coordinates for the hills
int poly[]= {490,200,550,150,600,200};
int poly1[]={600,200,650,150,690,200};
//skybackground
 setfillstyle(1,LIGHTBLUE);
 bar(490,100,650,200);
       setfillstyle(0,0);
//frame
 rectangle(480,90,660,210);
 //sun
 setfillstyle(1,YELLOW);
 fillellipse(600,180,10,10);
 setfillstyle(1,GREEN);
 //hills
 fillpoly(3,poly);
 fillpoly(3,poly1);

 setfillstyle(0,0);
}
void extras(){

//windows
	setfillstyle(1,WHITE);
//boundary
	bar(5,105,195,345);
	setfillstyle(1,LIGHTBLUE);
//four boxes
	bar(10,110,95,220);
	bar(105,110,190,220);
	bar(10,230,95,340);
	bar(105,230,190,340);
setfillstyle(0,15);
//WINDOW TABLE
	setfillstyle(1,15);
	bar(0,450,220,460);
	bar(5,460,15,490);
	bar(205,460,215,490);
//digital clock
	setfillstyle(1,LIGHTRED);
	bar(40,390,160,450);
	setfillstyle(1,BROWN);
	bar(45,395,155,445);
	setfillstyle(1,15);
	settextstyle(3,0,0);
	setcolor(15);
		itoa(hour,hstring,10);
		outtextxy(50,400,hstring);
		itoa(min,hstring,10);
		outtextxy(80,395,":");
		if(min<10){outtextxy(85,400,"0");  }
		outtextxy(100,400,hstring);
		settextstyle(0,0,0);
			if(temphr>=12)
				{outtextxy(140,430,"PM");}
			else
				{outtextxy(140,430,"AM"); }
		setcolor(WHITE);
}
int main(){
	struct time t;
	int gd = DETECT,gm,i;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(!kbhit()){

	setbkcolor(8) ;
	//get time from system and store in variables
		gettime(&t);
		hour = t.ti_hour;
		temphr = hour;
		hour%=12;
		if(hour==0 ){hour = 12;}
		min = t.ti_min;
		sec = t.ti_sec;

	//calculate angles for 3 hands
		h_a =((hour)+(min/60.0))*((30*M_PI)/180);
		m_a = (min+(sec/60.0)) *((6*M_PI)/180);
		s_a = (sec*6*M_PI)/180;

	 //draw functions

	 drawpendulum();
	 drawclock();
	 drawtable();
	drawphotos();
	extras();
	//display the hands of the clock
	setlinestyle(3,5,1);
		line(x,y,x+r*0.4*sin(h_a),y-r*0.4*cos(h_a));
		line(x,y,x+r*0.6*sin(m_a),y-r*0.6*cos(m_a));
		line(x,y,x+r*0.8*sin(s_a),y-r*0.8*cos(s_a));
		setlinestyle(0,0,0);
		pendulum ++;
		if(pendulum==2){pendulum=0;}
		delay(1000);
		cleardevice();

	}
 return 0;
}
