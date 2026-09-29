#include <GL/freeglut.h>

void drawStrokeText(float positionX, float positionY, float scale, const char* text)
{
    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);

    glScalef(scale, scale, 1.0f);

    for (const char* character = text; *character != '\0'; ++character) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *character);
    }
    glPopMatrix();
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(3.0f);
    drawStrokeText(-0.35f, -0.15f, 0.003f, "HI");
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q07 - Stroke Font Practice");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
