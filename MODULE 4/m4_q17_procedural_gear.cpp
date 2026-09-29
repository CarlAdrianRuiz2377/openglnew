#include <GL/glut.h>
#include <cmath>

const int TOOTH_COUNT = 8;
const int RING_VERTEX_COUNT = TOOTH_COUNT * 4;
const int POOL_VERTEX_COUNT = RING_VERTEX_COUNT + 1;
const int SLICES_PER_COLOR = RING_VERTEX_COUNT / 2;
const int INDICES_PER_COLOR = SLICES_PER_COLOR * 3;
const float OUTER_RADIUS = 0.8f;
const float INNER_RADIUS = 0.55f;
const float PI = 3.14159265f;

GLfloat gearVertices[POOL_VERTEX_COUNT * 2];
GLushort evenSliceIndices[INDICES_PER_COLOR];
GLushort oddSliceIndices[INDICES_PER_COLOR];

void buildGearArrays()
{
    gearVertices[0] = 0.0f;
    gearVertices[1] = 0.0f;

    for (int ring = 0; ring < RING_VERTEX_COUNT; ++ring) {
        const float angle = 2.0f * PI * ring / RING_VERTEX_COUNT;
        const bool isOuter = (ring % 4 == 0 || ring % 4 == 1);
        const float radius = isOuter ? OUTER_RADIUS : INNER_RADIUS;
        gearVertices[(ring + 1) * 2] = radius * std::cos(angle);
        gearVertices[(ring + 1) * 2 + 1] = radius * std::sin(angle);
    }

    int evenCount = 0;
    int oddCount = 0;
    for (int slice = 0; slice < RING_VERTEX_COUNT; ++slice) {
        const GLushort first = (GLushort)(slice + 1);
        const GLushort second = (GLushort)(((slice + 1) % RING_VERTEX_COUNT) + 1);

        GLushort* target = (slice % 2 == 0) ? evenSliceIndices : oddSliceIndices;
        int& count = (slice % 2 == 0) ? evenCount : oddCount;
        target[count++] = 0;
        target[count++] = first;
        target[count++] = second;
    }
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, gearVertices);

    glColor3f(0.75f, 0.75f, 0.8f);
    glDrawElements(GL_TRIANGLES, INDICES_PER_COLOR, GL_UNSIGNED_SHORT, evenSliceIndices);

    glColor3f(0.9f, 0.5f, 0.1f);
    glDrawElements(GL_TRIANGLES, INDICES_PER_COLOR, GL_UNSIGNED_SHORT, oddSliceIndices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q17 - Procedural Gear");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    buildGearArrays();
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
