#include <GL/glut.h>
#include <cstdio>

GLfloat arraysQuadVertices[] = {
    -0.8f, -0.3f,   -0.2f, -0.3f,   -0.2f,  0.3f,
    -0.8f, -0.3f,   -0.2f,  0.3f,   -0.8f,  0.3f
};

GLfloat elementsQuadVertices[] = {
    0.2f, -0.3f,   0.8f, -0.3f,   0.8f,  0.3f,   0.2f,  0.3f
};
GLubyte elementsQuadIndices[] = { 0, 1, 2,   0, 2, 3 };

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColor3f(1.0f, 0.5f, 0.2f);
    glVertexPointer(2, GL_FLOAT, 0, arraysQuadVertices);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glColor3f(0.2f, 0.7f, 1.0f);
    glVertexPointer(2, GL_FLOAT, 0, elementsQuadVertices);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, elementsQuadIndices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    printf("glDrawArrays : 6 vertices stored (12 floats)\n");
    printf("glDrawElements: 4 vertices stored (8 floats) + 6 indices\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("Q16 - glDrawArrays (left) vs glDrawElements (right)");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
