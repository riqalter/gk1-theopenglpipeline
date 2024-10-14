#include <GL/glut.h>

void drawCube() {
    glutWireCube(1.0); // Menggambar wireframe cube
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Membersihkan buffer
    glLoadIdentity(); // Reset transformasi

    glTranslatef(0.0f, 0.0f, -10.0f); // Geser kamera lebih jauh

    // Menggunakan mode polygon wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Atur warna objek
    glColor3f(1.0f, 1.0f, 1.0f); // Warna putih

    // Gambar kubus
    drawCube();

    glutSwapBuffers(); // Swap buffer untuk double buffering
}

void initGL() {
    glEnable(GL_DEPTH_TEST); // Mengaktifkan depth test
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Latar belakang hitam

    // Mengatur proyeksi perspektif
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0); // Mengatur perspektif

    glMatrixMode(GL_MODELVIEW); // Kembali ke mode model view
}

int main(int argc, char** argv) {
    // Inisialisasi GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Wireframe Cube");

    initGL(); // Inisialisasi OpenGL
    glutDisplayFunc(display); // Mengatur callback display

    glutMainLoop(); // Masuk ke loop utama
    return 0;
}
