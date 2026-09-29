#include <GL/freeglut.h> 

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);


    drawText(-0.4f, 0.4f, GLUT_BITMAP_HELVETICA_10, "Hello OpenGL");
    drawText(-0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Hello OpenGL");
    drawText(-0.4f, -0.4f, GLUT_BITMAP_TIMES_ROMAN_24, "Hello OpenGL");

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q02 - Font Size Comparison");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
