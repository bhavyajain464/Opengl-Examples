#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
#define pi 3.142857
const GLfloat factor =0.1f;
using namespace std;
void init(){
    glClearColor(0.2,1,1,1);
}
void reshape(int h,int w){
    glViewport(0,0,(GLsizei)h,(GLsizei)w);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);
}

void sun(){
    glBegin(GL_POLYGON); 
    glColor3f(255,255,0);
    float x, y, i; 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        x = 30 * cos(i); 
        y = 30 * sin(i); 
          
        glVertex2i(x-400, y+400); 
    } 
    glEnd(); 

    // glBegin(GL_POLYGON); 
    // glColor3f(255,255,0); 
    // for ( i = 0; i < (2 * pi); i += 0.001) 
    // { 
    //     x = 30 * cos(i); 
    //     y = 30 * sin(i); 
    //     glBegin(GL_LINES); 
    //     glVertex2f(x-400, y+400);
    //     glVertex2f(x-400+5*cos(i),y+400+5*sin(i)); 
    //     glEnd(); 
    // } 
    
}

void cloud(int sx,int sy){
    glBegin(GL_POLYGON); 
    glColor3f(0.9,0.9,0.9);
    float x, y, i; 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        x = 20 * cos(i); 
        y = 20 * sin(i); 
          
        glVertex2i(x+sx, y+sy); 
    } 
    glEnd(); 
}

void bird(){

}

void leaves(int sx,int sy){
    glBegin(GL_POLYGON); 
    glColor3f(0,0.153,0);
    float x, y, i; 
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        x = 50 * cos(i); 
        y = 50 * sin(i); 
          
        glVertex2i(x+sx, y+sy); 
    } 
    glEnd(); 
}
void river(){
    glPointSize(50);
    
			glBegin(GL_POINTS);
            glColor3f(0,0.5,1);
			for (int x = -500; x < 500; x +=4)
			{
				glVertex2f((x),40*(sin(x))-450);
			}
			glEnd();
}



void hutoutsideborder(int x,int y){
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0+y);
    glVertex2f(-100+x,0+y);
    glVertex2f(-150+x,-50+y);
    glVertex2f(-130+x,-50+y);
    glVertex2f(-130+x,-100+y);
    glVertex2f(-60+x,-104+y);
    // glVertex2f(-50,-100);
    glVertex2f(50+x,-100+y);
    glVertex2f(50+x,-50+y);
    glVertex2f(0+x,0+y);
    glEnd();
}

void hutinsideborder(int x,int y){
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(-100+x,0+y);
    glVertex2f(-50+x,-50+y);
    glVertex2f(50+x,-50+y);
    glVertex2f(0+x,0+y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(-100+x,0+y);
    glVertex2f(-150+x,-50+y);
    glVertex2f(-130+x,-50+y);
    glVertex2f(-90+x,-10+y);
    // glVertex2f(-50,-50);
    // glVertex2f(50,-50);
    // glVertex2f(0,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(-60+x,-40+y);
    glVertex2f(-60+x,-104+y);
    // glVertex2f(-130,-50);
    // glVertex2f(-90,-10);
    // glVertex2f(-50,-50);
    // glVertex2f(50,-50);
    // glVertex2f(0,0);
    glEnd();
}

void hutwindowgate(int x,int y){
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.5,0);
    glVertex2f(-115+x,-55+y);
    glVertex2f(-115+x,-85+y);
    glVertex2f(-75+x,-85+y);
    glVertex2f(-75+x,-55+y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex2f(-115+x,-55+y);
    glVertex2f(-115+x,-85+y);
    glVertex2f(-75+x,-85+y);
    glVertex2f(-75+x,-55+y);
    glEnd();
}

void hut(int x,int y){
    glBegin(GL_POLYGON);
    glColor3f(0.6,0.298,0);
    glVertex2f(-100+x,0+y);
    glVertex2f(-150+x,-50+y);
    glVertex2f(-130+x,-50+y);
    glVertex2f(-130+x,-100+y);
    glVertex2f(-60+x,-104+y);
    // glVertex2f(-50,-100);
    glVertex2f(50+x,-100+y);
    glVertex2f(50+x,-50+y);
    glVertex2f(0+x,0+y);
    glEnd();

    hutoutsideborder(x,y);
    hutinsideborder(x,y);
    hutwindowgate(x,y);

}

void tree(int h,int w,int x,int y){
    glBegin(GL_POLYGON);
    glColor3f(255,0,0);
    glVertex2f(0+x,0+y);
    glVertex2f(w+x,0+y);
    glVertex2f(w+x,h+y);
    glVertex2f(0+x,h+y);
    glEnd();

    leaves(x-10,h+y);
    leaves(x+w+10,h+y);
    leaves(x+(w/2),h+y+30);
}
void background(){
    // glBegin(GL_POLYGON);
    // glColor3f(0,0.128,0.255);
    // glVertex2f(-500,-400);
    // glVertex2f(-500,-500);
    // glVertex2f(500,-500);
    // glVertex2f(500,-400);
    // glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    glVertex2f(-500,100);
    glVertex2f(-500,-400);
    glVertex2f(500,-400);
    glVertex2f(500,100);
    glEnd();
}

void boat(){
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex2f(-50,-400);
    glVertex2f(50,-400);
    glVertex2f(100,-350);
    glVertex2f(-100,-350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(-5,-345);
    glVertex2f(-100,-400);
    glVertex2f(-90,-400);
    glVertex2f(5,-345);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    // glPointSize(10.0);
    background();
    
    river();
    sun();
    tree(200,50,-130,-80);
    hut(0,0);
    hut(100,-50);
    
    tree(200,50,300,-200);
    tree(200,50,-300,-250);
    
    for(int i=-100;i<100;i+=30){
        
        
        for(int j=400;j>=350;j-=25){
            if((i==-100&&j==400) || (i==-100 && j==350) || (i==80)&&j==400 || i==80&&j==350){
            
            }
            else{
                cloud(i,j);
            }
        }
    }
    boat();
    glFlush();
}
 
int main(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("First One");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
}