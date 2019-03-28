/*
Flores Molina Miguel de Jesús
PRACTICA #07
VS 2017
INTRUCCIONES:
W = Hacia dentro
S = Hacia Afuera
A = Izquierda
D = Derecha
Flecha arriba = rota en angulo X positivo
Flecha abajo = rota en angulo X negativo
Flecha derecha = rota en angulo Y positivo
Flecha izquierda= rota en angulo Y negativo
*/

#include "Main.h"
//Variables used to create movement

int sol = 0.0f;
int mercurio = 0.0f;
int venus = 0.0f;
int tierra = 0.0f;
int lunatierra = 0.0f;
int marte = 0.0f;
int lunamarte = 0.0f;
int jupiter = 0.0f;
int lunajupiter = 0.0f;
int saturno = 0.0f;
int urano = 0.0f;
int lunaurano = 0.0f;
int neptuno = 0.0f;
int lunaneptuno = 0.0f;

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

float angZ = -5.0f;
float angX = 0.0f;
float rotY = 0.0f;
float rotX = 0.0f;


GLfloat SunDiffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat SunShininess[] = { 50.0f };

GLfloat MercurioDiffuse[] = { 0.976f, 0.572f, 0.101f, 1.0f };			// MERCURIO
GLfloat MercurioSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat MercurioShininess[] = { 50.0f };

GLfloat VenDiffuse[] = { 0.992f, 0.913f, 0.568f, 1.0f };			// VENUS
GLfloat VenSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat VenShininess[] = { 50.0f };

GLfloat EarthDiffuse[] = { 0.462f, 0.839f, 0.956f, 1.0f };		// TIERRA
GLfloat EarthSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat EarthShininess[] = { 50.0f };

GLfloat MoonDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// LUNA
GLfloat MoonSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat MoonShininess[] = { 50.0f };

GLfloat MarDiffuse[] = { 0.898f, 0.560f, 0.431f, 1.0f };			// MARTE
GLfloat MarSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat MarShininess[] = { 50.0f };

GLfloat JupDiffuse[] = { 0.976f, 0.572f, 0.101f, 1.0f };			// JUPITER
GLfloat JupSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat JupShininess[] = { 50.0f };

GLfloat SatDiffuse[] = { 0.847f, 0.764f, 0.474f, 1.0f };			// SATURNO
GLfloat SatSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat SatShininess[] = { 50.0f };

GLfloat UraDiffuse[] = { 0.764f, 0.913f, 0.925f, 1.0f };			// URANO
GLfloat UraSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat UraShininess[] = { 50.0f };

GLfloat NepDiffuse[] = { 0.764f, 0.913f, 0.925f, 1.0f };			// NEPTUNO
GLfloat NepSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat NepShininess[] = { 50.0f };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();



	glTranslatef(angX, 0.0f, angZ);			
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);

	glPushMatrix();//sistema solar

	glPushMatrix();//inicia sol
		glRotatef(sol, 0.0f, 1.0f, 0.0f);	//El Sol gira sobre su eje
		glColor3f(1.0f, 1.0f, 0.0f);	//Sol amarillo
		
		
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SunDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SunSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SunShininess);
	glutSolidSphere(4.0f, 12.0f, 12.0f);  //Dibuja jupiter

		glEnable(GL_LIGHTING);
	glPopMatrix();//termina sol

	glPushMatrix();//inicia mercurio
		glRotatef(mercurio, 0.0f, 1.0f, 0.0f); //rotacion para mercurio alrededor del sol
		glTranslatef(8.0f, 0.0f, 0.0f); //traslacion para dibujar mercurio
		glColor3f(0.976f, 0.572f, 0.101f);	// color de mercurio
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
		glutSolidSphere(0.5f, 12.0f, 12.0f);  //Dibujo sol
	glPopMatrix();//termina mercurio

	glPushMatrix();//inicia venus
		glRotatef(venus, 0.0f, 1.0f, 0.0f); //rotacion para venus alrededor del sol
		glTranslatef(11.0f, 0.0f, 0.0f); //traslacion para dibujar venus
		glColor3f(0.992f, 0.913f, 0.568f);	//color de venus
		glMaterialfv(GL_FRONT, GL_DIFFUSE, VenDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, VenSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, VenShininess);
		glutSolidSphere(0.8f, 12.0f, 12.0f);  //Dibujando venus
	glPopMatrix();//termina venus

	glPushMatrix();//inicia tierra
		glRotatef(tierra, 0.0f, 1.0f, 0.0f); //rotacion para tierra alrededor del sol
		glTranslatef(13.0f, 0.0f, 0.0f); //traslacion para dibujar tierra
		glColor3f(0.462f, 0.839f, 0.956f);	//color tierra
		glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
		glutSolidSphere(0.9f, 12.0f, 12.0f);  //Dibuja tierra
	
	glPushMatrix();//inicia luna tierra
		glRotatef(lunatierra, 0.0f, 1.0f, 0.0f); //rotacion de la luna alrededor de la tierra
		glTranslatef(1.9f, 0.0f, 0.0f); //traslacion para dibujar tierra
		glColor3f(0.662f, 0.694f, 0.694f);	//color de la luna
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(0.3f, 12.0f, 12.0f);  //Dibuja luna
	glPopMatrix();//termina luna tierra
	
	glPopMatrix();//termina tierra

	glPushMatrix();//inicia marte
		glRotatef(marte, 0.0f, 1.0f, 0.0f); //rotacion de marte sobre el sol
		glTranslatef(15.0f, 0.0f, 0.0f); //traslacion para dibujar el sol
		glColor3f(0.898f, 0.560f, 0.431f);	//color de marte
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MarDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MarSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MarShininess);
		glutSolidSphere(0.4f, 12.0f, 12.0f);  //Draw Sun (radio,H,V);
	
	glPushMatrix();//inicia luna 1 marte
		glRotatef(lunamarte, 0.0f, 1.0f, 0.0f); //rotacion de luna sobre marte
		glTranslatef(1.5f, 0.0f, 0.0f); //traslacion para dibujar luna marte
		glColor3f(0.662f, 0.694f, 0.694f);	//color luna
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(0.2f, 12.0f, 12.0f);  //Dibuja luna marte
	glPopMatrix();//termina luna marte

	glPopMatrix();//termina marte

	glPushMatrix();//inicia jupiter
		glRotatef(jupiter, 0.0f, 1.0f, 0.0f); //rotacion de jupiter alrededor del sol
		glTranslatef(17.0f, 0.0f, 0.0f); //traslacion para dibujar jupiter
		glColor3f(0.968f, 0.956f, 0.811f);	//color jupiter
		glMaterialfv(GL_FRONT, GL_DIFFUSE, JupDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, JupSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, JupShininess);
		glutSolidSphere(4.5f, 25.0f, 25.0f);  //Dibuja jupiter
	
	glPushMatrix();//inicia luna 1 jupiter
		glRotatef(lunajupiter, 0.0f, 1.0f, 0.0f); //rotacion de luna 1 al rededor de jupiter
		glTranslatef(6.0f, 0.0f, 0.0f);//traslacion para dibujar luna 1
		glColor3f(0.662f, 0.694f, 0.694f);	//color de luna
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(1.0f, 12.0f, 12.0f);  //Dibuja luna 1 de jupiter
	glPopMatrix();//termina luna 1 jupiter

	glPushMatrix();//inicia luna 2 jupiter
		glRotatef(lunajupiter, 0.0f, 1.0f, 0.0f); //rotacion de luna 2 alrededor de jupiter
		glTranslatef(0.0f, 0.0f, 6.0f); //traslacion para dibujar luna 2 
		glColor3f(0.662f, 0.694f, 0.694f);	//color luna 2
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(1.0f, 12.0f, 12.0f);  //Dibuja luna 2
	glPopMatrix();//termina luna 2 jupiter

	glPopMatrix();//termina jupiter

	glPushMatrix();//inicia saturno
		glRotatef(saturno, 0.0f, 1.0f, 0.0f); //rotacion de saturno alrededor del sol
		glTranslatef(19.0f, 0.0f, 0.0f);//traslacion para dibujar saturno
		glColor3f(0.847f, 0.764f, 0.474f);	//color saturno
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SatDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, SatSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, SatShininess);
		glutSolidSphere(3.5f, 12.0f, 12.0f);  //Dibuja saturno

	glPushMatrix();//inicia anillo saturno
		glRotatef(45, 1.0f, 0.0f, 0.0f); //rotacion de anillo en saturno
		glColor3f(1.0f, 0.0f, 0.0f);	//color anillo
		glutSolidTorus(0.5f, 4.0f, 2.0f, 25.0f);  //Dibuja anillo
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glTranslatef(0.0f, 0.0f, 0.5f); //traslada para dibujar el segundo anillo de saturno
		glColor3f(0.0f, 0.0f, 1.0f);//color anillo
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidTorus(0.5f, 4.0f, 2.0f, 25.0f);  //Dibuja el segundo anillo
	glPopMatrix();//termina anillo saturno

	glPopMatrix();//termina saturno

	glPushMatrix();//inicia urano
		glRotatef(urano, 0.0f, 1.0f, 0.0f); //rotacion de urano alrededor del sol
		glTranslatef(21.0f, 0.0f, 0.0f); //traslacion para dibujar urano
		glColor3f(0.764f, 0.913f, 0.925f);	//color urano
		glMaterialfv(GL_FRONT, GL_DIFFUSE, UraDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, UraSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, UraShininess);
		glutSolidSphere(1.2f, 12.0f, 12.0f);  //Dibuja urano
	
	glPushMatrix();//inicia luna urano
		glRotatef(lunaurano, 0.0f, 1.0f, 0.0f); //rotacion de luna sobre urano
		glTranslatef(1.9f, 0.0f, 0.0f); //traslacion para dibujar luna urano
		glColor3f(0.662f, 0.694f, 0.694f);	//color de luna 
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(0.5f, 12.0f, 12.0f);  //Dibuja luna 
	glPopMatrix();//termina luna urano

	glPopMatrix();//termina urano

	glPushMatrix();//inicia neptuno
		glRotatef(neptuno, 0.0f, 1.0f, 0.0f); //rotacion de neptuno con el sol
		glTranslatef(21.0f, 0.0f, 0.0f); //traslacion para dibujar a neptuno
		glColor3f(0.764f, 0.913f, 0.925f);	//color de neptuno
		glMaterialfv(GL_FRONT, GL_DIFFUSE, NepDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, NepSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, NepShininess);
		glutSolidSphere(1.2f, 12.0f, 12.0f);  //Dibuja neptuno
	
	glPushMatrix();//inicia luna 1 neptuno
		glRotatef(lunaneptuno, 0.0f, 1.0f, 0.0f); //rotacion de luna 1 al rededor de neptuno
		glTranslatef(1.9f, 0.0f, 0.0f); //traslacion para dibujar luna 1
		glColor3f(0.662f, 0.694f, 0.694f);	//color luna 1
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(0.4f, 12.0f, 12.0f);  //Dibuja luna 1
	glPopMatrix();//termina luna 1 neptuno

	glPushMatrix();//inicia luna 2 neptuno
		glRotatef(lunaneptuno, 0.0f, 1.0f, 0.0f); //rotacion de luna 2 al rededor de neptuno
		glTranslatef(1.0f, 0.0f, 2.0f); //traslacion para dibujar luna 2
		glColor3f(0.662f, 0.694f, 0.694f);	//color luna 2
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
		glutSolidSphere(0.4f, 12.0f, 12.0f);  //Dibuja luna 2
	glPopMatrix();//termina luna 2 neptuno

	glPopMatrix();//termina neptuno

	glPopMatrix();//termina sistema solar


	glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		mercurio = (mercurio - 8) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		venus = (venus - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		tierra = (tierra - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		lunatierra = (lunatierra - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		marte = (marte - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		lunamarte = (lunamarte - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}


	if (dwElapsedTime >= 30)
	{
		jupiter = (jupiter - 4) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		lunajupiter = (lunajupiter - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		saturno = (saturno - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		urano = (urano - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}
	if (dwElapsedTime >= 30)
	{
		lunaurano = (lunaurano - 2) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		neptuno = (neptuno - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}


	if (dwElapsedTime >= 30)
	{
		lunaneptuno = (lunaneptuno - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}


	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		angZ += 0.5f;
		break;
	case 's':
	case 'S':
		angZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		angX -= 0.5f;
		break;
	case 'd':
	case 'D':
		angX += 0.5f;
		break;


		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		rotX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		rotX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		rotY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		rotY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Sistema Solar"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}