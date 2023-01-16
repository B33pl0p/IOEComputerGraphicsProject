#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
//struct  time t;
int main(){
	struct time t;
	int gd = DETECT,gm,i,color,pendulum=0;
	int x=300,y=180,r=100;
	float h_a,m_a,s_a,hour,min,sec;
	char tempstr[2];
	float angle,xcor1,ycor1;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(!kbhit()){

	//clock outline
	ellipse(300,50,0,180,110,50);
	rectangle(190,50,410,420);
	line(410,50,410,420);
	line(190,300,410,300);
	line(215,300,215,409);
	line(385,300,385,409);
	line(190,42,410,42);
	if(pendulum == 0) {
	//pendulum  hand -rt
	line(303,300,380,400);
	line(295,300,375,400);
	fillellipse(377,400,5,5);
	}
	if(pendulum ==1) {
	//pendulum hand -lft
	line(303,300,223,400);
	line(295,300,218,400);
	fillellipse(220,400,5,5);
	}

	//bottom

	ellipse(300,420,180,0,110,50);
	circle(x,y,10);
	circle(x,y,50);
	circle(x,y,r+8);

	//Clock Numbers
	for(i = 1 ;i<=12;i++){
		angle = ((i)*30 * 3.1415/180);
		xcor1 = x+r*sin(angle);
		ycor1 = y-r*cos(angle);
		itoa(i,tempstr,10);
		outtextxy(xcor1,ycor1,tempstr);
		setcolor(RED);
		outtextxy(215,411,"made by:- Biplop Giri");
		setcolor(WHITE);
		line(190,409,410,409);
				}
	//get time from system and store in variables
	gettime(&t);
		hour = t.ti_hour%12;
		if(hour ==0 ){hour = 12;}
		min = t.ti_min;
		sec = t.ti_sec;

	//calculate angles for 3 hands
	h_a =((hour)+(min/60.0))*30*3.1415/180;
	m_a = (min+(sec/60.0)) * 6*3.1415/180;
	s_a = sec*6*3.1415/180;
	//display the hands
	line(x,y,x+r*0.3*sin(h_a),y-r*0.5*cos(h_a));
	line(x,y,x+r*0.6*sin(m_a),y-r*0.7*cos(m_a));
	line(x,y,x+r*0.8*sin(s_a),y-r*0.9*cos(s_a));
	delay(1000);
	pendulum ++;
	if(pendulum ==2){pendulum =0;}
	cleardevice();
	}
 return 0;
}