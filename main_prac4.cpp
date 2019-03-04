/*
Flores Molina Miguel de Jesús
Version 2017
PRACTICA #04
INTRUCCIONES:
Q --->La camara se mueve hacia arriba
E --->La camara se mueve hacia abajo
W --->La camara se mueve hacia enfrente
S --->La camara se mueve hacia atras
A --->La camara se mueve hacia la izquierda
D --->La camara se mueve hacia la derecha
Flecha arriba ------> Rotacion hacia arriba
Flecha abajo ------> Rotacion hacia abaj
Flecha derecha  ------> Rotacion hacia la derecha 
Flecha izquierda ------> Rotacion hacia la izquierda
*/
#include "Main.h"

float transZ = -5.0f;
float transY = 0.0f;
float transX = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angY = 0.0; //declaracion de variable del angulo que se utiliza en el la rotacion
float angX = 0.0;

void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(1.0,1.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,0.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	
	//Poner Código Aquí.
		glLoadIdentity();
		glTranslatef(transX, transY, transZ);
		glRotatef(angY,0,1,0);
		glRotatef(angX, 1, 0, 0);
									//cara morada
		glTranslatef(-3,0,0);
		glRotatef(-90,1,0,0);//se refiere a que se esta rotando en el eje y
		glScalef(3,3,3);//aumento el tamaño del cubo
		prisma();			
		//primero las herramientas de transformacion, despues se pone a la figura a la cual se le va a aplicar
		glLoadIdentity();
		glTranslatef(transX, transY, transZ);
		glRotatef(angY, 0, 1, 0);
		glRotatef(angX, 1, 0, 0);
								//cara rosa
		glTranslatef(0,0,0);
		glRotatef(90,0,1,0);
		glScalef(3,3,3);
		prisma();
		//
		glLoadIdentity();
		glTranslatef(transX, transY, transZ);
		glRotatef(angY, 0, 1, 0);
		glRotatef(angX, 1, 0, 0);
										//cara verde
		glTranslatef(3, 0, 0);
		glRotatef(180,0,1, 0);
		glScalef(3, 3, 3);
		prisma();

		glLoadIdentity();
		glTranslatef(transX, transY, transZ);
		glRotatef(angY, 0, 1, 0);
		glRotatef(angX, 1, 0, 0);
							//cara amarilla
		glTranslatef(-1, 2.5, 0);
		glRotatef(-90, 0, 1, 0);
		glScalef(2, 2, 2);
		prisma();

		glLoadIdentity();
		glTranslatef(transX, transY, transZ);
		glRotatef(angY, 0, 1, 0);
		glRotatef(angX, 1, 0, 0);
								//cara roja
		glTranslatef(1, 2.5, 0);
		glRotatef(180, 0, 0, 1);
		glScalef(2, 2, 2);
		prisma();

		glLoadIdentity();
		glTranslatef(transX, transY, transZ);
		glRotatef(angY, 0, 1, 0);
		glRotatef(angX, 1, 0, 0);
							//cara Azul
		glTranslatef(0, 4.0, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(1, 1, 1);
		prisma();

  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			transX += 0.3f;
			break;
		case 'd':
		case 'D':
			transX -= 0.3f;
			break;
		case 'q':
		case 'Q':
			transY -= 0.3f;
			break;
		case 'e':
		case 'E':
			transY += 0.3f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angX += 3.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angX -= 3.0f;
		break;
	case GLUT_KEY_LEFT:
		angY += 3.0f;//el numkero es la velocidad con la cual rotara la figura en tre mayor sea el numero mas rapido rotara la figura
		break;
	case GLUT_KEY_RIGHT:
		angY -= 3.0f;//rotacion haca la derecha
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



