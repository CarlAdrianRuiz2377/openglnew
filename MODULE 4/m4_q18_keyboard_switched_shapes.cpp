#include <GL/glut.h>

GLfloat triangleVertices[] = {
    -0.6f, -0.5f,   0.6f, -0.5f,   0.0f,  0.6f
};
GLfloat quadVertices[] = {
    -0.5f, -0.5f,   0.5f, -0.5f,   0.5f,  0.5f,  -0.5f,  0.5f
};
GLfloat pentagonVertices[] = {
     0.000f,  0.700f,  -0.666f,  0.216f,  -0.411f, -0.566f,
     0.411f, -0.566f,   0.666f,  0.216f
};

int selectedShape = 1;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    const GLfloat* vertices = triangleVertices;
    GLenum drawMode = GL_TRIANGLES;
    GLsizei vertexCount = 3;

    if (selectedShape == 2) {
        vertices = quadVertices;
        drawMode = GL_QUADS;
        vertexCount = 4;
        glColor3f(0.3f, 0.9f, 0.4f);
    }
    else if (selectedShape == 3) {
        vertices = pentagonVertices;
        drawMode = GL_POLYGON;
        vertexCount = 5;
        glColor3f(0.8f, 0.4f, 1.0f);
    }
    else {
        glColor3f(1.0f, 0.6f, 0.2f);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(drawMode, 0, vertexCount);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (key == '1') {
        selectedShape = 1;
        glutSetWindowTitle("Q18 - Triangle (press 1, 2 or 3)");
    }
    else if (key == '2') {
        selectedShape = 2;
        glutSetWindowTitle("Q18 - Quad (press 1, 2 or 3)");
    }
    else if (key == '3') {
        selectedShape = 3;
        glutSetWindowTitle("Q18 - Pentagon (press 1, 2 or 3)");
    }
    else {
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q18 - Triangle (press 1, 2 or 3)");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyboard);
    glutMainLoop();
    return 0;
}
