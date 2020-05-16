#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
void main()
{
	clrscr();
	int i,a,b,j;
	char ch;
	int gdriver=DETECT;
	int gmode;
	int x,y,z=1;
	int cx=6,cy=-6;
	int speed=10;
	int score=0;
	char sc[50]="0",dc[50];
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	setcolor(15);
	x=getmaxx()/2;
	y=getmaxy();
	a=x;
	b=20;
	int hs=0,d,e;

	moveto(getmaxx()/2,getmaxy()/2);
	cout<<"RULES:"<<endl;
	cout<<"->Press 'z' to move left"<<endl;
	cout<<"->Press 'm' to move right"<<endl;
	cout<<"->Press 'e' to exit game anytime"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"PLAY:"<<endl;
	cout<<"1.Easy"<<endl;
	cout<<"2.Medium"<<endl;
	cout<<"3.Hard"<<endl;
	cin>>e;
	if(e==1)
	{
		cx=4;
		cy=-4;
	}
	else if(e==2)
	{
		cx=6;
		cy=-6;
	}
	else if(e==3)
	{
		cx=8;
		cy=-8;
	}
	cleardevice();
	while(z!=0)
	{
		delay(100);
		setcolor(0);
		rectangle(x-20,y-20,x+20,y-10);

		if(kbhit())
			{
			       ch=getch();
				if(ch=='z')
					x-=speed;
				if(ch=='m')
					x+=speed;
				if(ch=='e')
				     {
						cleardevice();
						cout<<"Do you want to quit?";
						cin>>ch;
						if(ch=='y'||ch=='Y')
						break;
				      }
			}

		setcolor(1);
		for(i=0;i<11;i++)
			line(0,i,getmaxx(),i);
		for(i=0;i<11;i++)
			line(i,0,i,getmaxy());
		for(i=0;i<11;i++)
			line(getmaxx()-i,0,getmaxx()-i,getmaxy());

			setcolor(3);
			rectangle(x-20,y-20,x+20,y-10);



			setcolor(0);
			circle(a,b,4);
			a+=cx;
			b+=cy;
			setcolor(15);
			circle(a,b,4);

			if(a<10)
			{
				setcolor(0);
				circle(a,b,4);
				a=10;
				cx=0-cx;
			}
			if(a>getmaxx()-10)
			{
				setcolor(0);
				circle(a,b,4);
				a=getmaxx()-10;
				cx=0-cx;
			}
			if(b<10)
			{
				setcolor(0);
				circle(a,b,4);
				b=10;
				cy=0-cy;
			}
			if((b==(y-25))&&(a>=(x-20))&&(a<=(x+20)))
			{
				setcolor(0);
				circle(a,b,4);
				b=getmaxy()-20;
				cy=0-cy;
				score++;
			}

		if(b>getmaxy()-1)
		{
			setcolor(13);
			settextstyle(8,0,6);
			outtextxy(getmaxx()/2-120,getmaxy()/2-50,"You Lose!");
			getch();
			cleardevice();
			cout<<"Do you want to continue (y/n)";
			cin>>ch;
			if(ch=='n'||ch=='N')
			z=0;
			else
			{
				a=x;
				b=20;
			}
			d=score;
			if(d>hs)
			hs=d;
		}
		setcolor(0);
		outtextxy(100,15,sc);
		setcolor(4);
		sprintf(sc,"%d",score);
		settextstyle(8,0,2);
		outtextxy(15,15,"SCORE:");
		outtextxy(100,15,sc);

		sprintf(dc,"%d",hs);
		outtextxy(getmaxx()-200,15,"HIGH SCORE:");
		outtextxy(getmaxx()-30,15,dc);

	}
	getch();

}
