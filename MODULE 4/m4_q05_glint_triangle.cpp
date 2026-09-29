#include <GL/glut.h>

GLint triangleVertices[] = {
    -100, -100,
     100, -100,
       0,  100
};

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.4f, 1.0f, 0.6f);

    glPushMatrix();

    glScalef(0.008f, 0.008f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_INT, 0, triangleVertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q05 - GLint Vertex Array");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
