/*
Flores Molina Miguel de Jesús
Version 2017
PRACTICA #06
INTRUCCIONES:
Q --->La camara se mueve hacia arriba
E --->La camara se mueve hacia abajo
W --->La camara se mueve hacia enfrente
S --->La camara se mueve hacia atras
A --->La camara se mueve hacia la izquierda
D --->La camara se mueve hacia la derecha
Flecha arriba ------> Rotacion hacia arriba
Flecha abajo ------> Rotacion hacia abajo
Flecha derecha  ------> Rotacion hacia la derecha
Flecha izquierda ------> Rotacion hacia la izquierda
*/

#include "Main.h"
// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables used to create movement
int sol = 0.0f;
int mer = 0.0f;
int ven = 0.0f;
int tier = 0.0f;
int luntier = 0.0f;
int mar = 0.0f;
int lunmar = 0.0f;
int jup = 0.0f;
int lunjup = 0.0f;
int sat = 0.0f;
int ura = 0.0f;
int lunura = 0.0f;
int nep = 0.0f;
int lunnep = 0.0f;
float angZ = -5.0f;
float angX = 0.0f;
float rotY = 0.0f;
float rotX = 0.0f;


GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat EarthShininess[] = { 50.0f };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat MoonShininess[] = { 50.0f };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0f, 0.5f, 0.0f, 1.0f };
GLfloat MarsShininess[] = { 50.0f };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// ventana

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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
			glRotatef(sol, 0.0f, 1.0f, 0.0f);	
			glColor3f(1.0f, 1.0f, 0.0f);	
			glutSolidSphere(4.0f, 12.0f, 12.0f);  
		glPopMatrix();//termina sol

		glPushMatrix();//inicia mercurio
			glRotatef(mer, 0.0f, 1.0f, 0.0f); //Rotacion
			glTranslatef(8.0f, 0.0f, 0.0f); //Translacion
			glColor3f(1.0f, 0.6f, 0.6f);	//Color
			glutSolidSphere(0.5f, 12.0f, 12.0f);  //Dibujo
		glPopMatrix();//fin mercurio

		glPushMatrix();//inicia venus
			glRotatef(ven, 0.0f, 1.0f, 0.0f);//Rotacion 
			glTranslatef(11.0f, 0.0f, 0.0f); //Traslación
			glColor3f(0.905f, 0.298f, 0.235f);//Color
			glutSolidSphere(0.8f, 12.0f, 12.0f);//Dibujo
		glPopMatrix();//termina venus

		glPushMatrix();//inicia tierra
			glRotatef(tier, 0.0f, 1.0f, 0.0f); //Rotacion 
			glTranslatef(13.0f, 0.0f, 0.0f); //Traslacion 
			glColor3f(0.011f, 0.662f, 0.956f);	//Color 
		glutSolidSphere(0.9f, 12.0f, 12.0f);  //Dibuja 

			glPushMatrix();//inicia luna tierra
				glRotatef(luntier, 0.0f, 1.0f, 0.0f); //Rotacion
				glTranslatef(1.9f, 0.0f, 0.0f); //Traslacion 
				glColor3f(1.0f, 1.0f, 1.0f);	//Color
				glutSolidSphere(0.3f, 12.0f, 12.0f);  //Dibuja 
			glPopMatrix();//termina luna tierra
		glPopMatrix();//termina tierra

		glPushMatrix();//inicia marte
			glRotatef(mar, 0.0f, 1.0f, 0.0f); //Rotacion 
			glTranslatef(15.0f, 0.0f, 0.0f); //Traslacion
			glColor3f(1.0f, 0.0f, 0.431f);	//Color
			glutSolidSphere(0.4f, 12.0f, 12.0f);  //Dibujo

			glPushMatrix();//inicia luna 1 marte
				glRotatef(lunmar, 0.0f, 1.0f, 0.0f); //Rotacion
				glTranslatef(1.5f, 0.0f, 0.0f); //Traslacion
				glColor3f(1.0f, 1.0f, 1.0f);	//Color 
				glutSolidSphere(0.2f, 12.0f, 12.0f);  //Dibuja 
			glPopMatrix();//termina luna marte
		glPopMatrix();//termina marte

		glPushMatrix();//inicia jupiter
			glRotatef(jup, 0.0f, 1.0f, 0.0f); //Rotacion 
			glTranslatef(17.0f, 0.0f, 0.0f); //Traslacion
			glColor3f(0.6f, 0.4f, 0.0f);	//Color
			glutSolidSphere(4.5f, 25.0f, 25.0f);  //Dibuja 

			glPushMatrix();//inicia luna 1 jupiter
				glRotatef(lunjup, 0.0f, 1.0f, 0.0f); //Rotacion
				glTranslatef(6.0f, 0.0f, 0.0f);//Traslacion
				glColor3f(0.662f, 0.694f, 0.694f);	//Color
				glutSolidSphere(1.0f, 12.0f, 12.0f);  //Dibuja
			glPopMatrix();//termina luna 1 jupiter

			glPushMatrix();//inicia luna 2 jupiter
				glRotatef(lunjup, 0.0f, 1.0f, 0.0f); //Rotacion
				glTranslatef(0.0f, 0.0f, 6.0f); //Traslacion 
				glColor3f(0.662f, 0.694f, 0.694f);	//Color
				glutSolidSphere(1.0f, 12.0f, 12.0f);  //Dibuja
			glPopMatrix();//termina luna 2 jupiter
		glPopMatrix();//termina jupiter

		glPushMatrix();//inicia saturno
			glRotatef(sat, 0.0f, 1.0f, 0.0f); //Rotacion 
			glTranslatef(19.0f, 0.0f, 0.0f);//Traslacion
			glColor3f(0.647f, 0.411f, 0.741f);	//Color 
			glutSolidSphere(3.5f, 12.0f, 12.0f);  //Dibuja 

			glPushMatrix();//inicia anillo saturno
				glRotatef(45, 1.0f, 0.0f, 0.0f); //Rotacion
				glColor3f(0.815f, 0.827f, 0.831f);	//Colo
				glutSolidTorus(0.5f, 4.0f, 2.0f, 25.0f);  //Dibuja anillo
				glTranslatef(0.0f, 0.0f, 0.5f); //Rraslada para dibujar el segundo anillo de saturno
				glColor3f(1.0f, 1.0f, 1.0f);//Color anillo
				glutSolidTorus(0.5f, 4.0f, 2.0f, 25.0f);  //Dibuja
			glPopMatrix();//termina anillo saturno
		glPopMatrix();//termina saturno

		glPushMatrix();//inicia urano
			glRotatef(ura, 0.0f, 1.0f, 0.0f); //Rotacion 
			glTranslatef(21.0f, 0.0f, 0.0f); //Traslacion 
			glColor3f(0.764f, 0.913f, 0.925f);	//Color 
			glutSolidSphere(1.2f, 12.0f, 12.0f);  //Dibuja

			glPushMatrix();//inicia luna urano
				glRotatef(lunura, 0.0f, 1.0f, 0.0f); //Rotacion 
				glTranslatef(1.9f, 0.0f, 0.0f); //Traslacion
				glColor3f(0.662f, 0.694f, 0.694f);	//Color 
				glutSolidSphere(0.5f, 12.0f, 12.0f);  //Dibuja 
			glPopMatrix();//termina luna urano
		glPopMatrix();//termina urano

		glPushMatrix();//inicia neptuno
			glRotatef(nep, 0.0f, 1.0f, 0.0f); //Rotacion
			glTranslatef(21.0f, 0.0f, 0.0f); //Traslacion
			glColor3f(0.0f, 0.0f, 1.0f);	//Color
			glutSolidSphere(1.2f, 12.0f, 12.0f);  //Dibuja

			glPushMatrix();//inicia luna 1 neptuno
				glRotatef(lunnep, 0.0f, 1.0f, 0.0f); //Rotacion
				glTranslatef(1.9f, 0.0f, 0.0f); //Traslacion 
				glColor3f(1.0f, 1.0f, 1.0f);	//Color
				glutSolidSphere(0.4f, 12.0f, 12.0f);  //Dibuja
			glPopMatrix();//termina luna 1 neptuno
			
			glPushMatrix();//inicia luna 2 neptuno
				glRotatef(lunnep, 0.0f, 1.0f, 0.0f); //Rotacion
				glTranslatef(1.0f, 0.0f, 2.0f); //Traslacion
				glColor3f(1.0f, 1.0f, 1.0f);	//Color 
				glutSolidSphere(0.4f, 12.0f, 12.0f);  //Dibuja 
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
		mer = (mer - 8) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		ven = (ven - 7) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		tier = (tier - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		luntier = (luntier - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		mar = (mar - 5) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		lunmar = (lunmar - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		jup = (jup - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		lunjup = (lunjup - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		sat = (sat - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		ura = (ura - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}
	if (dwElapsedTime >= 30)
	{
		lunura = (lunura - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		nep = (nep - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		lunnep = (lunnep - 1) % 360;
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