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
    drawText(-0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "800 x 500 at (150, 150)");
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("My Custom Window");

    glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
