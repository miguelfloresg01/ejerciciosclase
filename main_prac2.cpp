/*Flores Molina Miguel de Jesús
Practica 2
Version 2017
*/
//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	//La letra M
	glBegin(GL_QUADS);
	glColor3f(.12, 0, 0);
	glVertex3f(-9.5f, -9.5f, 0.0f);
	glVertex3f(-8.5f, -8.0f, 0.0f);
	glColor3f(.8, 0, 0);
	glVertex3f(-8.5f, -5.0f, 0.0f);
	glVertex3f(-9.5f, -3.0f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(.8, 0, 0);
	glVertex3f(-6.0f, -6.5f, 0.0f);
	glVertex3f(-6.0f, -5.5f, 0.0f);
	glColor3f(.6, 0, 0);
	glVertex3f(-9.5f, -3.0f, 0.0f);
	glVertex3f(-8.5f, -5.0f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(.6, 0, 0);
	glVertex3f(-6.0f, -5.5f, 0.0f);
	glVertex3f(-6.0f, -6.5f, 0.0f);
	glColor3f(.8, 0, 0);
	glVertex3f(-3.5f, -5.0f, 0.0f);
	glVertex3f(-2.5f, -3.0f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(.12, 0, 0);
	glVertex3f(-3.5f, -8.0f, 0.0f);
	glVertex3f(-2.5f, -9.5f, 0.0f);
	glColor3f(.8, 0, 0);
	glVertex3f(-2.5f, -3.0f, 0.0f);
	glVertex3f(-3.5f, -5.0f, 0.0f);

	// La Letra F
	glBegin(GL_QUADS);
	glColor3f(.1, .36, .2);  // es el color para la figura y se encarga de decolorar una parte de la figura 
	glVertex3f(1.0f, -9.8f, 0.0f);
	glColor3f(.5, .1, .8);
	glVertex3f(2.5f, -9.8f, 0.0f);
	glColor3f(.1, .36, .2);// es el color para otra parte de la figura y se encarga de decolorar una parte de la figura 
	glVertex3f(2.5f, -4.5f, 0.0f);
	glColor3f(.1, .36, .2);
	glVertex3f(1.0f, -3.0f, 0.0f);

	glBegin(GL_QUADS); //parte de arriba de la F
	glColor3f(.1, .36, .2);
	glVertex3f(2.5f, -4.5f, 0.0f);
	glColor3f(.5, .1, .8);
	glVertex3f(6.5f, -3.9f, 0.0f);
	glVertex3f(7.0f, -3.0f, 0.0f);
	glColor3f(.1, .36, .2);
	glVertex3f(1.0f, -3.0f, 0.0f);

	glBegin(GL_QUADS); // la segunda parte de la F
	glColor3f(.5, .1, .8);
	glVertex3f(2.5f, -7.0f, 0.0f);
	glVertex3f(5.0f, -6.5f, 0.0f);
	glVertex3f(5.5f, -5.5f, 0.0f);
	glColor3f(.1, .36, .2);
	glVertex3f(2.5f, -5.5f, 0.0f);

	//La letra C
	glBegin(GL_QUADS); // 
	glColor3f(.4152, .0828, .458);
	glVertex3f(-9.5f, 8.5f, 0.0f);
	glColor3f(.743, .663, .458);
	glVertex3f(-8.0f, 7.0f, 0.0f);
	glVertex3f(-8.0f, 1.5f, 0.0f);
	glVertex3f(-9.5f, 0.0f, 0.0f);

	glBegin(GL_QUADS); //
	glColor3f(.743, .643, .458); 
	glVertex3f(-8.0f, 1.5f, 0.0f);
	glColor3f(.260, .770, .1158);
	glVertex3f(-4.0f, 1.5f, 0.0f);
	
	glVertex3f(-2.5f, 0.0f, 0.0f);
	glColor3f(.743, .643, .358);
	glVertex3f(-9.5f, 0.0f, 0.0f);

	glBegin(GL_QUADS); //
	glColor3f(.4152, .0828, .458);
	glVertex3f(-9.5f, 8.5f, 0.0f);
	glColor3f(.260, .770, .1158);
	glVertex3f(-2.5f, 8.5f, 0.0f);
	glVertex3f(-4.0f, 7.0f, 0.0f);
	glColor3f(.743, .663, .458);
	glVertex3f(-8.0f, 7.0f, 0.0f);

	//La Letra G

	glBegin(GL_QUADS); // 
	glVertex3f(0.0f, 8.5f, 0.0f);	
	glColor3f(.7, .3, .6789);
	glVertex3f(1.5f, 7.0f, 0.0f);
	glColor3f(.5253, .7, .4352);
	glVertex3f(1.5f, 1.5f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS); // 
	
	glVertex3f(6.0f, 1.5f, 0.0f);
	glColor3f(.5253, .6578, .4738);
	glVertex3f(1.5f, 1.5f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(.742, .445872, .4572);
	glVertex3f(7.5f, 0.0f, 0.0f);

	glBegin(GL_QUADS); // 
	glColor3f(.5, .35, 0);
	glVertex3f(7.5f, 8.5f, 0.0f);
	glVertex3f(0.0f, 8.5f, 0.0f);
	glColor3f(.203098, .73987, 0);
	glVertex3f(1.5f, 7.0f, 0.5f);
	glVertex3f(6.5f, 7.0f, 1.5f);

	glBegin(GL_QUADS); // 
	glColor3f(.1152, .568, .0258);
	glVertex3f(6.0f, 3.5f, 0.0f);
	glVertex3f(7.5f, 5.0f, 0.0f);
	glColor3f(.68, .1152, .0280);
	glVertex3f(7.5f, 0.0f, 0.0f);
	glVertex3f(6.0f, 1.5f, 0.0f);

	glBegin(GL_QUADS); // 
	glColor3f(.568, .1152, .298);
	glVertex3f(6.0f, 3.5f, 0.0f);
	glVertex3f(3.5f, 3.5f, 0.0f);
	
	glVertex3f(3.0f, 5.0f, 0.0f);
glColor3f(.7838, .8652, .465);
	glVertex3f(7.5f, 5.0f, 0.0f);

	glEnd();
	glFlush();
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

	// Ortogonal
	glOrtho(-10, 10, -10, 10, -1.0, 2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 2"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutMainLoop();          // 

	return 0;
}



