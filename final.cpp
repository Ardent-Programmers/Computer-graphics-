#include<GL/glut.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.141592653589
using namespace std;
int flag = 0;
int count = 0,c1 = 0;
float nmo = 7,nmo1 = 7;
bool p_face = false;
void man(int, int);
void displaytext();
//clear the screen
void clearscreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

//draw an arc
void drawArc(GLfloat tx, GLfloat ty,
	GLfloat sx, GLfloat sy,
	GLfloat r, GLfloat g, GLfloat b) {
	glPushMatrix();

	glTranslatef(tx, ty, 0);
	glScalef(sx, sy, 0);

	glPointSize(1);
	glBegin(GL_POINTS);
	glColor3ub(r, g, b);
  	for ( GLfloat i = 90; i < 270; i++)
    		glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
  	glEnd();
	glPointSize(1);

	glPopMatrix();
}

//draw lines
void drawLine(GLfloat x1,GLfloat x2,GLfloat y1,GLfloat y2,GLfloat r,GLfloat g,GLfloat b)
{
	glColor3f(r,g,b);
	glBegin(GL_LINES);
	glVertex3f(x1,y1,0);
	glVertex3f(x2,y2,0);
	glEnd();
}

//rectangles
void drawRectangle(GLfloat x1,GLfloat x2,GLfloat y1,GLfloat y2,GLfloat r,GLfloat g,GLfloat b)
{
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	glVertex3f(x1,y1,0.0);
	glVertex3f(x1,y2,0.0);
	glVertex3f(x2,y2,0.0);
	glVertex3f(x2,y1,0.0);
	glEnd();
}

//for drawing triangles
void drawTriangle(GLfloat x1,GLfloat x2,GLfloat x3,GLfloat y1,GLfloat y2,GLfloat y3,GLfloat r,GLfloat g,GLfloat b)
{
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	glVertex3f(x1,y1,0.0);
	glVertex3f(x2,y2,0.0);
	glVertex3f(x3,y3,0.0);
	glEnd();
}

//for drawing circles
void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx,GLfloat sy,
	GLfloat radius) {
		glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(sx, sy, 0);
   		glBegin(GL_POLYGON);
		if(!p_face) glColor3f(r, g, b);
		else  glColor3ub(255, 191, 128);
    		for (GLfloat i = 0; i < 360; i += 5)
        		glVertex3f(radius * sin(i * PI / 180), radius * cos(i * PI / 180),0.0);
    		glEnd();

		glPopMatrix();
}

//draw people on stage
void people_on_stage()
{
	float R=0.8,G=0.6,B=0.5,yval = 520.0,k=0,j=0,o=0;
	float sum = 17.0,temp=0.0,body_x1 = 5.0,body_x2=30.0,body_y1=495.0,body_y2=510.0,body_temp_x1 = 5.0;
	float body_temp_x2 = 30.0,eyes_yval = 525.0,eyes_x1,eyes_x2,mouth_yval;
	//draw people body
	for(k=0;k<4;k++) {
		body_y1 = 495.0;
		body_y2 = 510.0;
		//people on three rows 
		for(j=0;j<3;j++) {
			for(o=0;o<10;o++) {
				drawRectangle(body_x1,body_x2,body_y1,body_y2,1.0,0.5,0.5);
				drawLine((body_x1+5),(body_x1+5),body_y1,body_y2,0.0,0.0,0.0);
				drawLine((body_x2-5),(body_x2-5),body_y1,body_y2,0.0,0.0,0.0);
				body_x1 += 34.0;
				body_x2 += 34.0;
			}
			body_x1 = body_temp_x1,body_x2=body_temp_x2;
			body_y1 += 70.0;
			body_y2 = body_y1 + 15.0;
		}
		body_temp_x1 = body_temp_x1+400.0;
		body_temp_x2 = body_temp_x1 + 25.0;
		body_x1 = body_temp_x1;
		body_x2 = body_temp_x2;
	}
	//draw people face
	for(int k=0;k<4;k++) {
		for(int j=0;j<3;j++) {
			temp = sum;
			eyes_x1 = temp - 5.0;	
			eyes_x2 = temp + 5.0;
			mouth_yval = yval - 5.0;
			for(int i=0;i<10;i++) {
				p_face = true;
				drawCircle(temp,yval,R,G,B,1,1,16.0);
				p_face = false;
				drawCircle(eyes_x1,eyes_yval,0.0,0.0,0.0,1,1,2.6);
				drawCircle(eyes_x2,eyes_yval,0.0,0.0,0.0,1,1,2.6);
				drawArc(temp,mouth_yval,0.5,0.5,0.0,0.0,0.0);
				drawTriangle((temp-5.0),(temp+2.0),(temp-1.0),(yval+10.0),(yval+7.0),(yval+18.0),0.0,0.0,0.0);
				drawTriangle((temp+2.0),(temp+6.0),(temp-1.0),(yval+12.0),(yval+8.0),(yval+18.0),0.0,0.0,0.0);
				drawTriangle((temp-9.0),(temp-5.0),(temp-1.0),(yval+14.0),(yval+8.0),(yval+18.0),0.0,0.0,0.0);
				temp+=34.0;				
				eyes_x1+=34.0;
				eyes_x2+=34.0;
				}


				yval +=70.0;
				mouth_yval = yval - 5.0;
				eyes_yval = yval + 5.0;
			}
			eyes_yval = 525.0;
			yval = 520.0;
			sum +=400.0;
	}
	
}

//draw stadium
void stadium()
{
	float x1=0,x2=366.0,y1=475.0,y2=495.0,sx1=0.0,sx2=366.0,sy1=470.0,sy2=700.0;
	float st_top_x1 = 0.0,st_top_x2 = 366.0,st_top_x3 = 386.0,st_top_x4 = 20.0,st_top_y1 = 700.0,st_top_y2 = 760.0;
	float st_side_y1 = 470.0,st_side_y2 = 760.0,st_side_x1 = 366.0,st_side_x2 = 386.0;
	for(int k=0;k<4;k++) {
		for(int j=0;j<3;j++) {
			glColor3f(0.5,0.4,0.4);
			glBegin(GL_POLYGON);
			glVertex3f(st_top_x1, st_top_y1, 0.0);
			glVertex3f(st_top_x2, st_top_y1, 0.0);
			glVertex3f(st_top_x3, st_top_y2, 0.0);
			glVertex3f(st_top_x4, st_top_y2, 0.0);
			glEnd();
			glBegin(GL_POLYGON);
			glVertex3f(st_side_x1, st_side_y2, 0.0);
			glVertex3f(st_side_x1, st_side_y1, 0.0);
			glVertex3f(st_side_x2, st_side_y1, 0.0);
			glVertex3f(st_side_x2, st_side_y2, 0.0);
			glEnd();
			drawLine(st_top_x2,st_top_x3,st_top_y1,st_top_y2,0.0,0.0,0.0);
		}
		st_top_x1  = st_top_x2 + 34.0;
		st_top_x2  = st_top_x1 + 366.0;
		st_top_x3  = st_top_x2 + 20.0;
		st_top_x4  = st_top_x1 + 20.0;
		st_side_x1 = st_side_x2 + 34.0;
		st_side_x2 = st_side_x1 + 366.0;
	}
	//Green background for stages
	glColor3f(0.1,0.2,0.4);
	for(int i=0;i<4;i++) {
		glBegin(GL_POLYGON);
		glVertex3f(sx1,sy1,0.5);
		glVertex3f(sx1,sy2,0.5);
		glVertex3f(sx2,sy2,0.5);
		glVertex3f(sx2,sy1,0.5);
		glEnd();
		sx1 = sx2 + 34.0;
		sx2 = sx1 + 366.0;
		
	}
	
	//stage design
	glColor3f(0.5,0.5,0.4);
	for(int k=0;k<4;k++) {
		for(int j=0;j<3;j++) {
			glBegin(GL_POLYGON);
			glVertex3f(x1,y1,0.5);
			glVertex3f(x1,y2,0.5);
			glVertex3f(x2,y2,0.5);
			glVertex3f(x2,y1,0.5);
			glEnd();
			y1 = y2 + 50;
			y2 = y1 + 20;
			}
		y1 = 475.0, y2 = 495.0;
		x1 = x2 + 34.0;
		x2 = x1 + 366.0;
	}
	x1= 386.0,x2= 400.0,y1= 470.0,y2 = 768.0;
	//dummy rectangle
	for(int i=0;i<3;i++) {
		drawRectangle(x1,x2,y1,y2,0.8,1.0,1.0);
		x1 = x2+386.0;
		x2 = x1+ 14.0;
	}
}

//Draw the text on screen using Bitmap
void drawText(const char *text, int length, int x,int y,int z) 
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0,1366,0,768,500,-500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();	
	glRasterPos3i(x, y, z);
	for(int i=0;i<length;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int) text[i]);
	}	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	//glMatrixMode(GL_MODELVIEW);
}


void display_start_end(int flag)
{
	glColor3f(1.0,1.0,1.0);
	string start[] = {"S","T","A","R","T"}; 
	int start_pos[][3] = {{50,440,-1},{50,410,-1},{50,380,-1},{50,350,-1},{50,320,-1}};
	string end[] = {"E","N","D"};
	for(int i=0;i<5;i++)
	{
		drawText(start[i].data(),start[i].size(),start_pos[i][0],start_pos[i][1],start_pos[i][2]);
	}
	
	if(flag == 2) {
		int end_pos[][3] = {{1006,410,-1},{1006,380,-1},{1006,350,-1}};
		for(int i=0;i<3;i++) {
			drawText(end[i].data(),end[i].size(),end_pos[i][0],end_pos[i][1],end_pos[i][2]);
	}
	}
	else {
		int end_pos[][3] = {{1316,410,-1},{1316,380,-1},{1316,350,-1}};
		for(int i=0;i<3;i++) {
			drawText(end[i].data(),end[i].size(),end_pos[i][0],end_pos[i][1],end_pos[i][2]);
		}
	}
	
}

//display jump distance in meters -- for long jump
void display_meters()
{
	string meters[] = {"3M","6M","9M"};
	int meters_pos[][3] = {{1056,400,-1},{1156,400,-1},{1256,400,-1}};
	for(int i=0;i<3;i++) {
			drawText(meters[i].data(),meters[i].size(),meters_pos[i][0],meters_pos[i][1],meters_pos[i][2]);
	}
	
}

//draw a racetrack
void racetrack(void)
{
	drawRectangle(0.0,1366.0,290.0,470.0,0.4,0.3,0.0);	//Mud path
	drawRectangle(0.0,1366.0,300.0,310.0,1.0,1.0,1.0);	//white patch
	drawRectangle(0.0,1366.0,450.0,460.0,1.0,1.0,1.0);	//white patch
	drawRectangle(100.0,110.0,300.0,450.0,1.0,1.0,1.0);	//start line						
	if(flag==2) {
		drawRectangle(966.0,956.0,300.0,450.0,1.0,1.0,1.0);     //end line
		drawRectangle(1066,1056,300,375,1,1,1);
		drawRectangle(1166,1156,300,375,1,1,1);
		drawRectangle(1266,1256,300,375,1,1,1);
		display_meters();
	} else drawRectangle(1266.0,1256.0,300.0,450.0,1.0,1.0,1.0);	//end line
	if(flag == 1) {
		drawRectangle(1286,1266,590.0,460.0,1,0,0); //vertical
		drawRectangle(1266,1256,520,430,1,0,0);      //horizontal
		drawRectangle(1266,1256,390.0,320.0,1,0,0); //vertical
		drawRectangle(1286,1256,400,390,1,0,0);      //horizontal
		drawLine(1284,1284,480,400,0,0,1);	//x1 = x2
	}
	display_start_end(flag);
}


//draw grass
void grass(void)
{
	float R = 0.1,G = 0.4,B = 0.0;
	drawRectangle(0.0,1366.0,0.0,290.0,0.0,0.8,0.4);	//grass
	//draw plants
	drawTriangle(40.0,70.0,55.0,150.0,180.0,150.0,R,G,B);
	drawTriangle(40.0,10.0,25.0,150.0,180.0,150.0,R,G,B);
	drawTriangle(140.0,170.0,155.0,150.0,180.0,150.0,R,G,B);
	drawTriangle(140.0,110.0,125.0,150.0,180.0,150.0,R,G,B);
	drawTriangle(240.0,270.0,255.0,150.0,180.0,150.0,R,G,B);
	drawTriangle(240.0,210.0,225.0,150.0,180.0,150.0,R,G,B);	
	drawTriangle(640.0,670.0,655.0,90.0,120.0,90.0,R,G,B);
	drawTriangle(640.0,610.0,625.0,90.0,120.0,90.0,R,G,B);
	drawTriangle(740.0,770.0,755.0,90.0,120.0,90.0,R,G,B);
	drawTriangle(740.0,710.0,725.0,90.0,120.0,90.0,R,G,B);
	drawTriangle(840.0,870.0,855.0,90.0,120.0,90.0,R,G,B);
	drawTriangle(840.0,810.0,825.0,90.0,120.0,90.0,R,G,B);	

}



//Handle keyboard input
void processkeys(unsigned char key, int x,int y)
{
	switch(key)
	{
		case '1': flag = 1;		//high jump
			  clearscreen();
			  break;
		case '2': flag = 2;		//long jump
			  clearscreen();
			  break;
		case '3': flag = 3;		//race
			  clearscreen();
			  break;
		case '4': exit(0);
			  break;
	}
}


//Rectangles that cover menu names
void first_scene_rectangles(void)
{
	glColor3f(0.2,0.2,0.1);
	glBegin(GL_POLYGON);	
	glVertex3f(240.0,380.0,0.2);
	glVertex3f(240.0,320.0,0.2);
	glVertex3f(430.0,320.0,0.2);
	glVertex3f(430.0,380.0,0.2);
	glEnd();
	glBegin(GL_POLYGON);	
	glVertex3f(580.0,230.0,0.2);
	glVertex3f(580.0,170.0,0.2);
	glVertex3f(770.0,170.0,0.2);
	glVertex3f(770.0,230.0,0.2);
	glEnd();
	glBegin(GL_POLYGON);	
	glVertex3f(970.0,380.0,0.2);
	glVertex3f(970.0,320.0,0.2);
	glVertex3f(1160.0,320.0,0.2);
	glVertex3f(1160.0,380.0,0.2);
	glEnd();
}
//Draw the text on screen using Bitmap
void drawTitle(const char *text, int length, int x,int y,int z) 
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0,1366,0,768,500,-500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();	
	glRasterPos3i(x, y, z);
	for(int i=0;i<length;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int) text[i]);
	}	
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}


//Initialize mode
void init()
{
	
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0,1366.0,0.0,768.0,502.0,-502.0);
	glClearColor(0.8,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
}

//Set the text to be displayed
void displaytext(void)
{
	glColor3f(1.0,1.0,1.0);
	string title = "Olympics game simulation";
	string text[] = {"1. High jump","2. Long jump","3. Running race"};
	int pos[][3] = {{270,350,-1},{610,200,-1},{1000,350,-1}};
	for(int i=0;i<3;i++)
	{
		drawText(text[i].data(),text[i].size(),pos[i][0],pos[i][1],pos[i][2]);
	}
	glPointSize(5.0);
	glColor3f(0.5,0.7,0.9);
	drawTitle(title.data(),title.size(),550.0,700.0,-1);
}


//Main menu
void mainmenu(void)
{
	
	
	first_scene_rectangles();
	displaytext();
	glFlush();
	glutSwapBuffers();
	
}

//display 1st game
void displaystadium(void)
{
	glLoadIdentity();
	glOrtho(0.0,1366.0,0.0,768.0,-500.0,500.0);
	racetrack();
	grass();
	stadium();
	people_on_stage();
	//glFlush();
	glutSwapBuffers();
}

void display()
{	
	
	if(flag==0) mainmenu();				//display Main menu
	if(flag==1) { 					//display 1st game
		c1++;
		//for smoother animation
		if(c1%100 == 0) {  
			displaystadium(); 
			nmo +=70;
			count = count+1;
			
		}
		
		glPushMatrix();
		if(nmo<1100  )
			glTranslatef(nmo,0,0);
		else if(nmo<1200)	glTranslatef(nmo,150,0);
		else	glTranslatef(nmo,0,0);
		man(30,98); 
		glPopMatrix();
	}
	if(flag == 2) {					//display second game
		c1++;
		//for smoother animation
		if(c1%100 == 0) {  
			displaystadium(); 
			nmo +=70;
			count = count+1;
			
		}
		
		glPushMatrix();
		if(nmo<900 )
			glTranslatef(nmo,0,0);
		else if(nmo<1040)	glTranslatef(nmo,110,0);
		else	glTranslatef(nmo,0,0);
		man(30,98); 
		glPopMatrix();
	}
	if(flag==3) {				      //display third game
		c1++;
		//for smoother animation
		if(c1%100 == 0) {  
			displaystadium(); 
			nmo +=70;
			nmo1 +=60;
			count = count+1;
			
		}
		glPushMatrix();
		glTranslatef(nmo1,0,0);
		man(-47,108);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(nmo,0,0);
		man(-47,98); 
		glPopMatrix();
		
	}			
	glutSwapBuffers();
	
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1366,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Olympics");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(processkeys);
	glutMainLoop();
	return 0;
}

//man

void man(int man_tx,int man_ty) {
	glColor3ub(0, 0, 0);
	glTranslatef(man_tx,man_ty,0.0);
	glScalef(0.8,0.8,0);
	glColor3ub(0, 0, 0);
	//left hand -- from the character perspective
	if (count % 2 == 0) {
		glBegin(GL_POLYGON);
		glColor3ub(124, 24, 230);
		glVertex2i(42, 498-40);
		glVertex2i(29, 498-40);
		glVertex2i(22, 498-90);
		glVertex2i(27, 498-90);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2i(27, 498-85);
		glVertex2i(22, 498-90);
		glVertex2i(55, 498-90);
		glVertex2i(56, 498-85);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(37+18 , 498-90);
		glVertex2i(37+19 , 498-80);
		glVertex2i(37+24 , 498-80);
		glVertex2i(37+25 , 498-90);
		glEnd();
	}
	
	//shirt
	glBegin(GL_POLYGON);
	glColor3ub(124, 180, 230);
	glVertex3f(37+15, 498-113,-0.5);
	glVertex3f(37-15, 498-113,-0.5);
	glVertex3f(37-20, 498-40,-0.5);
	glVertex3f(37+20, 498-40,-0.5);
	glVertex3f(37+5, 498-10,-0.5);
	glVertex3f(37-5, 498-10,-0.5);
	glVertex3f(37-20, 498-40,-0.5);
	glEnd();
	
	//pant
	if (count % 2 != 0) {

		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 230);
		glVertex3i(37+15, 498-113, -1);
		glVertex3i(37-15, 498-113, -1);

		glVertex3i(37+10, 498-169, -1);
		glVertex3i(37+20, 498-169, -1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(80, 100, 230);
		glVertex3i(37+15, 498-113, 1);
		glVertex3i(37-15, 498-113, 1);
		glVertex3i(37-20, 498-169, 1);
		glVertex3i(37-10, 498-169, 1);
		glEnd();
		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(100, 10,10);
		glVertex3i(37+10, 498-169, -1);
		glVertex3i(37+32, 498-163, -1);
		glVertex3i(37+30, 498-178, -1);
		glVertex3i(37+10, 498-178, -1);
		glEnd();
		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(100, 30, 10);
		glVertex3i(37-20, 498-169, 1);
		glVertex3i(37+2, 498-163, 1);
		glVertex3i(37+0, 498-178, 1);
		glVertex3i(37-20, 498-178, 1);
		glEnd();
	}
	if (count % 2 == 0) {

		glBegin(GL_POLYGON);
		glColor3ub(80, 80, 230);
		glVertex3i(37+15-1, 498-113, 1);
		glVertex3i(37-15-1, 498-113, 1);

		glVertex3i(37+10-1, 498-169, 1);
		glVertex3i(37+20-1, 498-169, 1);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 230);
		glVertex3i(37+15, 498-113, -1);
		glVertex3i(37-15, 498-113, -1);
		glVertex3i(37-20, 498-169, -1);
		glVertex3i(37-10, 498-169, -1);
		glEnd();
		//shoe left
		glBegin(GL_POLYGON);
		glColor3ub(100, 10, 10);
		glVertex3i(37+10, 498-169, 1);
		glVertex3i(37+32, 498-163, 1);
		glVertex3i(37+30, 498-178, 1);
		glVertex3i(37+10, 498-178, 1);
		glEnd();
		//shoe right
		glBegin(GL_POLYGON);
		glColor3ub(100, 30, 10);
		glVertex3i(37-20-1, 498-169, -1);
		glVertex3i(37+2-1, 498-163, -1);
		glVertex3i(37+0-1, 498-178, -1);
		glVertex3i(37-20-1, 498-178, -1);
		glEnd();
	}
	
	glPushMatrix();
	glTranslatef(37 , 498, 0);
	glutSolidTorus(10, 10, 100, 90);
	glPopMatrix();
	glColor3ub(255, 191, 128);
	glPushMatrix();
	glTranslatef(37 , 498, 0);
	glutSolidTorus(17, 7, 100, 90);
	glPopMatrix();
	//eyebrow
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3i(37+07 , 498+10, 50);
	glVertex3i(37+23 , 498+4, 50);
	glVertex3i(37+17 , 498+4, 50);
	glVertex3i(37+13 , 498+10, 50);
	glEnd();
	//eye
	glPointSize(3.0);
	
	glBegin(GL_POINTS);
	glVertex3f(37+17, 498-2, 50);
	glEnd();
	//nose
	glBegin(GL_POLYGON);
	glColor3ub(255, 191, 128);
	glVertex3i(37+23, 498+3, 50);
	glVertex3i(37+23, 498-4, 50);
	glVertex3i(37+30, 498-2, 50);
	
	glEnd();
	//hair
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3i(37-25, 498-18, 50);
	glVertex3i(37-23, 498+28, 50);
	glVertex3i(37+20, 498+28, 50);
	glVertex3i(37+20, 498+19, 50);
	glEnd();
	// right hand
	if (count % 2 != 0 ) {
		glBegin(GL_POLYGON);
		glColor3ub(124, 24, 230);
		glVertex2i(37+5, 498-40);
		glVertex2i(37-8, 498-40);
		glVertex2i(37-15, 498-90);
		glVertex2i(37-10, 498-90);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2i(37-10, 498-85);
		glVertex2i(37-15, 498-90);
		glVertex2i(37+18, 498-90);
		glVertex2i(37+19, 498-85);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(37+18, 498-90);
		glVertex2i(37+19, 498-80);
		glVertex2i(37+24, 498-80);
		glVertex2i(37+25, 498-90);
		glEnd();
	} else {
		glBegin(GL_POLYGON);
		glColor3ub(124, 24, 230);
		glVertex2i(37+5, 498-40);
		glVertex2i(37-8, 498-40);
		glVertex2i(37-27, 498-90);
		glVertex2i(37-20, 498-90);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2i(37-22, 498-85);
		glVertex2i(37-27, 498-90);
		glVertex2i(37+6, 498-90);
		glVertex2i(37+7, 498-85);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3ub(255, 191, 128);
		glVertex2i(37+6, 498-90);
		glVertex2i(37+7, 498-80);
		glVertex2i(37+12, 498-80);
		glVertex2i(37+13, 498-90);
		glEnd();
	}
	
	
}
