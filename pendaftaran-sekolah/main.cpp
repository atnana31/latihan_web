#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

// fungsi untuk menggambar lingkaran dengan gradien
void drawGradientCircle(float cx, float cy, float radius, int segments = 100) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.95f, 0.8f); // Pusat terang
    glVertex2f(cx, cy);
    
    glColor3f(0.9f, 0.7f, 0.4f); // Tepi lebih gelap
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd();
}

// fungsi untuk menggambar bintang dekoratif
void drawStar(float cx, float cy, float outerRadius, float innerRadius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    
    for (int i = 0; i <= 10; i++) {
        float angle = i * M_PI / 5;
        float radius = (i % 2 == 0) ? outerRadius : innerRadius;
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd();
}

// Fungsi untuk menggambar buku dengan detail tinggi
void drawDetailedBook() {
    // Bayangan buku
    glColor4f(0.1f, 0.1f, 0.1f, 0.4f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_QUADS);
    // Bayangan halaman kiri
    glVertex2f(-0.42f, -0.32f);
    glVertex2f(-0.02f, -0.35f);
    glVertex2f(-0.02f, 0.35f);
    glVertex2f(-0.42f, 0.32f);
    
    // Bayangan halaman kanan
    glVertex2f(0.02f, -0.35f);
    glVertex2f(0.42f, -0.32f);
    glVertex2f(0.42f, 0.32f);
    glVertex2f(0.02f, 0.35f);
    glEnd();
    
    glDisable(GL_BLEND);
    
    // Halaman kiri buku dengan gradien
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Putih bersih
    glVertex2f(-0.4f, -0.3f);
    
    glColor3f(0.95f, 0.95f, 0.98f); // Sedikit kebiruan
    glVertex2f(0.0f, -0.33f);
    glVertex2f(0.0f, 0.33f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.4f, 0.3f);
    glEnd();
    
    // Halaman kanan buku dengan gradien
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.98f);
    glVertex2f(0.0f, -0.33f);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.3f);
    
    glColor3f(0.95f, 0.95f, 0.98f);
    glVertex2f(0.0f, 0.33f);
    glEnd();
    
    // Detail garis teks halaman kiri
    glColor3f(0.2f, 0.3f, 0.5f);
    glLineWidth(1.5f);
    for (int i = 0; i < 12; i++) {
        float y = 0.25f - i * 0.04f;
        float leftX = -0.35f + (i % 3) * 0.02f; // Variasi indentasi
        float rightX = -0.05f - (i % 2) * 0.03f;
        
        glBegin(GL_LINES);
        glVertex2f(leftX, y);
        glVertex2f(rightX, y - 0.005f);
        glEnd();
    }
    
    // Detail garis teks halaman kanan
    for (int i = 0; i < 12; i++) {
        float y = 0.25f - i * 0.04f;
        float leftX = 0.05f + (i % 2) * 0.03f;
        float rightX = 0.35f - (i % 3) * 0.02f;
        
        glBegin(GL_LINES);
        glVertex2f(leftX, y - 0.005f);
        glVertex2f(rightX, y);
        glEnd();
    }
    
    // Tulang buku dengan detail
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.3f, 0.15f); // Coklat tua
    glVertex2f(-0.03f, -0.33f);
    
    glColor3f(0.8f, 0.5f, 0.2f); // Coklat terang
    glVertex2f(0.03f, -0.33f);
    glVertex2f(0.03f, 0.33f);
    
    glColor3f(0.6f, 0.3f, 0.15f);
    glVertex2f(-0.03f, 0.33f);
    glEnd();
    
    // Detail emas pada tulang buku
    glColor3f(0.9f, 0.8f, 0.3f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, -0.28f);
    glVertex2f(0.0f, 0.28f);
    glEnd();
    
    // Pita bookmark
    glColor3f(0.8f, 0.2f, 0.2f); // Merah
    glBegin(GL_QUADS);
    glVertex2f(-0.008f, 0.33f);
    glVertex2f(0.008f, 0.33f);
    glVertex2f(0.008f, 0.45f);
    glVertex2f(-0.008f, 0.45f);
    glEnd();
    
    // Ujung pita (segitiga)
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.008f, 0.45f);
    glVertex2f(0.008f, 0.45f);
    glVertex2f(0.0f, 0.52f);
    glEnd();
}

// Fungsi untuk menggambar ornamen dekoratif
void drawOrnaments() {
    // Ornamen sudut kiri atas
    glColor3f(0.8f, 0.6f, 0.2f);
    glBegin(GL_LINES);
    glLineWidth(2.0f);
    
    // Garis melengkung dekoratif
    for (float t = 0; t <= 1.0f; t += 0.1f) {
        float x1 = -0.8f + t * 0.15f;
        float y1 = 0.65f + 0.1f * sin(t * M_PI);
        float x2 = -0.8f + (t + 0.1f) * 0.15f;
        float y2 = 0.65f + 0.1f * sin((t + 0.1f) * M_PI);
        
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
    
    // Ornamen sudut kanan atas (simetris)
    glBegin(GL_LINES);
    for (float t = 0; t <= 1.0f; t += 0.1f) {
        float x1 = 0.8f - t * 0.15f;
        float y1 = 0.65f + 0.1f * sin(t * M_PI);
        float x2 = 0.8f - (t + 0.1f) * 0.15f;
        float y2 = 0.65f + 0.1f * sin((t + 0.1f) * M_PI);
        
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
    
    // Bintang dekoratif
    glColor3f(0.9f, 0.8f, 0.4f);
    drawStar(-0.6f, 0.5f, 0.03f, 0.015f);
    drawStar(0.6f, 0.5f, 0.03f, 0.015f);
    drawStar(-0.7f, -0.5f, 0.025f, 0.012f);
    drawStar(0.7f, -0.5f, 0.025f, 0.012f);
}

// Fungsi untuk menggambar teks dengan shadow
void drawTextWithShadow(const char* text, float x, float y, void* font) {
    // Shadow
    glColor3f(0.2f, 0.2f, 0.3f);
    glRasterPos2f(x + 0.003f, y - 0.003f);
    const char* c = text;
    while (*c) {
        glutBitmapCharacter(font, *c);
        c++;
    }
    
    // Teks utama
    glColor3f(0.9f, 0.8f, 0.3f);
    glRasterPos2f(x, y);
    c = text;
    while (*c) {
        glutBitmapCharacter(font, *c);
        c++;
    }
}

// Fungsi untuk menggambar background dengan gradien halus
void drawBackground() {
    glBegin(GL_QUADS);
    // Gradien vertikal dari biru gelap ke biru terang
    glColor3f(0.08f, 0.15f, 0.3f); // Biru navy
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    
    glColor3f(0.2f, 0.35f, 0.6f); // Biru medium
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    
    glColor3f(0.3f, 0.5f, 0.8f); // Biru terang
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

// Fungsi utama untuk menggambar logo
void drawLogo() {
    // Background gradien
    drawBackground();
    
    // Lingkaran cahaya di belakang buku
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glColor4f(1.0f, 0.95f, 0.7f, 0.3f);
    drawGradientCircle(0.0f, 0.0f, 0.6f);
    
    glDisable(GL_BLEND);
    
    // Ornamen dekoratif
    drawOrnaments();
    
    // Buku utama
    drawDetailedBook();
    
    // Border frame
    glColor3f(0.8f, 0.6f, 0.2f);
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.9f, -0.85f);
    glVertex2f(0.9f, -0.85f);
    glVertex2f(0.9f, 0.85f);
    glVertex2f(-0.9f, 0.85f);
    glEnd();
    
    // Inner border
    glLineWidth(1.5f);
    glColor3f(0.9f, 0.7f, 0.3f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.87f, -0.82f);
    glVertex2f(0.87f, -0.82f);
    glVertex2f(0.87f, 0.82f);
    glVertex2f(-0.87f, 0.82f);
    glEnd();
    
    // Teks dengan shadow
    drawTextWithShadow("TOKO BUKU", -0.28f, 0.65f, GLUT_BITMAP_TIMES_ROMAN_24);
    
    glColor3f(0.85f, 0.9f, 1.0f);
    glRasterPos2f(-0.35f, 0.58f);
    const char* subtitle = "LITERASI NUSANTARA";
    while (*subtitle) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *subtitle);
        subtitle++;
    }
    
    // Quote di bawah
    glColor3f(0.7f, 0.8f, 0.9f);
    glRasterPos2f(-0.42f, -0.65f);
    const char* quote = "\"Membaca adalah Jendela Dunia\"";
    while (*quote) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *quote);
        quote++;
    }
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    drawLogo();
    
    glutSwapBuffers();
}

// Fungsi reshape
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    float aspect = (float)width / (float)height;
    if (width >= height) {
        gluOrtho2D(-aspect, aspect, -1.0, 1.0);
    } else {
        gluOrtho2D(-1.0, 1.0, -1.0/aspect, 1.0/aspect);
    }
    
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi keyboard
void keyboard(unsigned char key, int x, int y) {
    if (key == 27) { // ESC
        exit(0);
    }
}

// Fungsi inisialisasi
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

// Fungsi main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Logo Toko Buku - Literasi Nusantara");
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    std::cout << "=== LOGO TOKO BUKU LITERASI NUSANTARA ===" << std::endl;
    std::cout << "Tekan ESC untuk keluar" << std::endl;
    std::cout << "=========================================" << std::endl;
    
    glutMainLoop();
    return 0;
}