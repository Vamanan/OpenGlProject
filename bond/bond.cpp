#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

float cx = -10; float d = 0.1; int flag = 0; float r = 30; float d1 = 0.05;
int flag1 = 0; int flag2; int flag3 = 0, bloodflag = 0; int climaxflag = 0;
float xmin = 0, xmax = 750, yy = 500, yy1 = 500;

const float DEG2RAD = 3.14159 / 180;

void myinit()
{

	glClearColor(0.0, 0.0, 0.0, 1.0);//colour of the screen
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 750.0, 0.0, 500.0, 0, 300);
	glMatrixMode(GL_MODELVIEW);
}

void circle(float r, int cx, int cy)
{
	float x, y;
	/*for(int i=0;i<50;i++)
	for(int j=0;j<1000;j++)*/  //use in case of slow machines
	glBegin(GL_POLYGON);


	for (int i = 0; i <360; i++)
	{
		float degInRad = i*DEG2RAD;
		x = cx + cos(degInRad)*r;
		y = cy + sin(degInRad)*r;
		glVertex2f(x, y);
	}
	glEnd();
}


void gun(int x, int y)
{
	glColor3f(0.521, 0.521, 0.521);
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x, y - 7.5);
	glVertex2f(x + 3.75, y - 7.5);
	glVertex2f(x + 3.75, y);
	glEnd();
	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x + 7.5, y);
	glVertex2f(x + 7.5, y - 3.75);
	glVertex2f(x, y - 3.75);
	glEnd();
	glColor3f(0, 0, 0);

}
void gun2(int x, int y)
{
	glColor3f(0.521, 0.521, 0.521);
	glBegin(GL_POLYGON);

	glVertex2f(x - 1.875, y + 1.875);
	glVertex2f(x - 1.875, y - 1.875);
	glVertex2f(x + 1.875, y - 1.875);
	glVertex2f(x + 1.875, y + 1.875);
	glEnd();
	glPointSize(2);
	glColor3f(1, 1, 0);


	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glColor3f(0.521, 0.521, 0.521);
	glBegin(GL_POLYGON);

	glVertex2f(x - 1.5, y);
	glVertex2f(x - 1.5, y - 3.75);
	glVertex2f(x + 1.5, y - 3.75);
	glVertex2f(x + 1.5, y);

	glEnd();
	glColor3f(0, 0, 0);

	//glColor3f(0,0,0);
}

void blood(float bottom)
{
	for (int i = 0; i<2000; i++)
	{
		for (int j = 0; j<1000; j++)
		{

		}
	}
	glColor3f(0.7, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2f(xmin, yy);
	glVertex2f(xmax, yy);
	glVertex2f(xmax, bottom);
	glVertex2f(xmin, bottom);
	glEnd();
}

void man(int hcx, int hcy)
{
	glColor3f(0, 0, 0);
	circle(15, hcx, hcy);
	glLineWidth(1.5);

	glBegin(GL_LINES);//torso
	glVertex2f(hcx, hcy);
	glVertex2f(hcx, hcy - 46.87);
	glEnd();
	glBegin(GL_LINES);//right leg(far)
	glVertex2f(hcx, hcy - 46.87);
	glVertex2f(hcx - 15, hcy - 82.015);
	//glVertex2f(60,30);
	glEnd();
	glBegin(GL_LINES);//left leg(near)
	glVertex2f(hcx, hcy - 46.87);
	//glvertex2f(20,10);
	glVertex2f(hcx + 15, hcy - 82.015);
	glEnd();
	glBegin(GL_LINES);//right arm(far)
	glVertex2f(hcx, hcy - 18.75);
	glVertex2f(hcx - 15, hcy - 46.87);
	glEnd();

	gun(hcx - 18.75, hcy - 46.87);

	glBegin(GL_LINES);//left arm(near)
	glVertex2f(hcx, hcy - 18.75);
	glVertex2f(hcx + 15, hcy - 46.87);
	glEnd();
	glColor3f(1, 1, 1);
}


void man2(int hcx, int hcy)
{
	glColor3f(0, 0, 0);
	circle(15, hcx, hcy);
	glLineWidth(1.5);

	glBegin(GL_LINES);//torso
	glVertex2f(hcx, hcy);
	glVertex2f(hcx, hcy - 46.87);
	glEnd();
	glBegin(GL_LINES);//right leg(far)
	glVertex2f(hcx, hcy - 46.87);
	glVertex2f(hcx, hcy - 82.015);
	//glVertex2f(60,30);
	glEnd();
	glBegin(GL_LINES);//left leg(NEAR)
	glVertex2f(hcx, hcy - 46.87);
	//glvertex2f(20,10);
	glVertex2f(hcx, hcy - 82.015);
	glEnd();

	glBegin(GL_LINES);//right ARM(far)
	glVertex2f(hcx, hcy - 18.75);
	glVertex2f(hcx - 3.75, hcy - 46.87);
	glEnd();

	//gun(hcx-30,hcy-125);

	glBegin(GL_LINES);//left arm(near)
	glVertex2f(hcx, hcy - 18.75);
	glVertex2f(hcx + 3.75, hcy - 46.87);
	glEnd();

	//gun(hcx,hcy-125);

	glColor3f(1, 1, 1);
}

void climax(int hcx, int hcy)
{
	climaxflag++;
	glColor3f(0, 0, 0);
	circle(15, hcx, hcy);
	glLineWidth(1.5);
	glBegin(GL_LINES);//torso
	glVertex2f(hcx, hcy);
	glVertex2f(hcx, hcy - 46.87);
	glEnd();
	glBegin(GL_LINES);//left leg
	glVertex2f(hcx, hcy - 46.87);
	glVertex2f(hcx - 7.5, hcy - 82.015);
	//glVertex2f(60,30);
	glEnd();
	glBegin(GL_LINES);//right leg
	glVertex2f(hcx, hcy - 46.87);
	//glvertex2f(20,10);
	glVertex2f(hcx + 7.5, hcy - 82.015);
	glEnd();
	glBegin(GL_LINES);//right arm(far)
	glVertex2f(hcx, hcy - 18.75);
	glVertex2f(hcx - 7.5, hcy - 31.875);
	glEnd();

	gun2(hcx - 7.5, hcy - 31.875);

	glBegin(GL_LINES);//left arm(near)
	glVertex2f(hcx, hcy - 18.75);
	glVertex2f(hcx + 7.5, hcy - 46.87);
	glEnd();


	glColor3f(1, 1, 1);




}


void circle2(float r, int cx, int cy)
{
	int x, y;
	flag1++;
	if (flag1 % 350 == 0)
		flag2++;
	/*for(int i=0;i<50;i++)
	for(int j=0;j<1000;j++)*/	//use in case of slow machines
	glBegin(GL_POLYGON);


	for (int i = 0; i <360; i++)
	{
		float degInRad = i*DEG2RAD;

		x = cx + cos(degInRad)*r;
		y = cy + sin(degInRad)*r;
		glVertex2f(x, y);
	}
	glEnd();


	if (flag2 % 2 != 0 && flag3 == 0)
	{
		man(cx, cy + 30);

	}


	else if (flag2 % 2 == 0 && flag3 == 0)
	{
		man2(cx, cy + 30);
	}
	if (cx <= 400)
	{
		flag3 = 1;
		climax(cx, cy + 30);

		if (climaxflag == 1000)
			bloodflag = 1;


	}

}


void display()
{

	glColor3f(1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//	glTranslatef(2,0,0);
	if (flag == 0)
	{
		circle(r, cx, 250);
		if (int(cx) >= 100 && int(cx) <= 150)
			circle(30, 100, 250);
		if (int(cx) >= 200 && int(cx) <= 250)
			circle(30, 200, 250);
		if (int(cx) >= 300 && int(cx) <= 350)
			circle(30, 300, 250);
		if (int(cx) >= 400 && int(cx) <= 450)
			circle(30, 400, 250);
	}
	if (flag == 1)
		circle2(60, cx, 250);
	if (bloodflag == 1)
	{
		blood(yy1--);
	}
	glFlush();
	cx += d;

	if (cx >= 700)
	{
		d = -d1;
		flag = 1;
	}
	if (cx <= 400 && flag == 1)
	{

		d = 0;

	}

	glutPostRedisplay();

}


void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(750, 500);//size of window
	glutInitWindowPosition(0, 0);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glutCreateWindow("bond2");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();

}
