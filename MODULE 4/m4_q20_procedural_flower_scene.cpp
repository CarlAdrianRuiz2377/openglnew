#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const float FLOWER_CENTER_X = 0.0f;
const float FLOWER_CENTER_Y = 0.1f;

const int PETAL_COUNT = 8;
const int PETAL_VERTEX_COUNT = PETAL_COUNT * 3;
const float PETAL_RADIUS = 0.5f;
const float PETAL_HALF_ANGLE = 0.3f;

const int DISC_SEGMENT_COUNT = 24;
const int DISC_VERTEX_COUNT = DISC_SEGMENT_COUNT + 1;
const int DISC_INDEX_COUNT = DISC_SEGMENT_COUNT + 2;
const float DISC_RADIUS = 0.15f;

GLfloat petalVertices[PETAL_VERTEX_COUNT * 2];
GLfloat petalColors[PETAL_VERTEX_COUNT * 3];
GLfloat discVertices[DISC_VERTEX_COUNT * 2];
GLubyte discIndices[DISC_INDEX_COUNT];


GLfloat groundVertices[] = {
    -1.00f, -1.00f,   1.00f, -1.00f,   1.00f, -0.60f,  -1.00f, -0.60f,
    -0.02f, -0.60f,   0.02f, -0.60f,   0.02f,  0.10f,  -0.02f,  0.10f
};
GLfloat groundColors[] = {
    0.2f, 0.6f, 0.2f,  0.2f, 0.6f, 0.2f,  0.2f, 0.6f, 0.2f,  0.2f, 0.6f, 0.2f,
    0.1f, 0.4f, 0.1f,  0.1f, 0.4f, 0.1f,  0.1f, 0.4f, 0.1f,  0.1f, 0.4f, 0.1f
};

void buildPetalArrays()
{
    for (int petal = 0; petal < PETAL_COUNT; ++petal) {
        const float centerAngle = 2.0f * PI * petal / PETAL_COUNT;
        const float angles[3] = { 0.0f, centerAngle - PETAL_HALF_ANGLE, centerAngle + PETAL_HALF_ANGLE };

        for (int corner = 0; corner < 3; ++corner) {
            const int vertexIndex = petal * 3 + corner;
            const float radius = (corner == 0) ? 0.0f : PETAL_RADIUS;
            petalVertices[vertexIndex * 2] = FLOWER_CENTER_X + radius * std::cos(angles[corner]);
            petalVertices[vertexIndex * 2 + 1] = FLOWER_CENTER_Y + radius * std::sin(angles[corner]);

            const bool isPinkPetal = (petal % 2 == 0);
            const float red = 1.0f;
            const float green = isPinkPetal ? 0.3f : 0.6f;
            const float blue = isPinkPetal ? 0.6f : 0.9f;
            const float paleness = (corner == 0) ? 0.5f : 0.0f;
            petalColors[vertexIndex * 3] = red;
            petalColors[vertexIndex * 3 + 1] = green + paleness * (1.0f - green);
            petalColors[vertexIndex * 3 + 2] = blue + paleness * (1.0f - blue);
        }
    }
}

void buildDiscArrays()
{
    discVertices[0] = FLOWER_CENTER_X;
    discVertices[1] = FLOWER_CENTER_Y;
    discIndices[0] = 0;

    for (int segment = 0; segment < DISC_SEGMENT_COUNT; ++segment) {
        const float angle = 2.0f * PI * segment / DISC_SEGMENT_COUNT;
        discVertices[(segment + 1) * 2] = FLOWER_CENTER_X + DISC_RADIUS * std::cos(angle);
        discVertices[(segment + 1) * 2 + 1] = FLOWER_CENTER_Y + DISC_RADIUS * std::sin(angle);
        discIndices[segment + 1] = (GLubyte)(segment + 1);
    }
    discIndices[DISC_INDEX_COUNT - 1] = 1;
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);

    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, groundVertices);
    glColorPointer(3, GL_FLOAT, 0, groundColors);
    glDrawArrays(GL_QUADS, 0, 8);

    glVertexPointer(2, GL_FLOAT, 0, petalVertices);
    glColorPointer(3, GL_FLOAT, 0, petalColors);
    glDrawArrays(GL_TRIANGLES, 0, PETAL_VERTEX_COUNT);
    glDisableClientState(GL_COLOR_ARRAY);

    glColor3f(1.0f, 0.8f, 0.1f);
    glVertexPointer(2, GL_FLOAT, 0, discVertices);
    glDrawElements(GL_TRIANGLE_FAN, DISC_INDEX_COUNT, GL_UNSIGNED_BYTE, discIndices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q20 - Procedural Flower Scene");
    glClearColor(0.55f, 0.8f, 1.0f, 1.0f);
    buildPetalArrays();
    buildDiscArrays();
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
