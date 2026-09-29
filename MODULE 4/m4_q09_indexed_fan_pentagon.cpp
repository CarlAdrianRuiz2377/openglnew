#include <GL/glut.h>

GLfloat pentagonVertices[] = {
     0.000f,  0.000f,
     0.000f,  0.700f,
    -0.666f,  0.216f,
    -0.411f, -0.566f,
     0.411f, -0.566f,
     0.666f,  0.216f
};


GLubyte fanIndices[] = { 0, 1, 2, 3, 4, 5, 1 };

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.6f, 0.4f, 1.0f);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, pentagonVertices);
    glDrawElements(GL_TRIANGLE_FAN, 7, GL_UNSIGNED_BYTE, fanIndices);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q09 - Indexed Triangle Fan Pentagon");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
