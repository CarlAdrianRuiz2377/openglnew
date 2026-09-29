#include <GL/glut.h>

GLfloat triangleVertices[] = {
    -0.5f, -0.5f,
     0.5f, -0.5f,
     0.0f,  0.6f
};


GLubyte triangleIndices[] = { 2, 0, 1 };

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.4f, 0.4f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, triangleVertices);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, triangleIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q06 - glDrawElements Index Order");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
