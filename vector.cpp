#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    inline double magnitud() const {
        return sqrt(x * x + y * y);
    }

    void mostrar() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    friend double productoPunto(const Vector2D &v1, const Vector2D &v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    Vector2D operator+(const Vector2D &otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }
};

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    cout << "Vector 1: ";
    v1.mostrar();

    cout << "Vector 2: ";
    v2.mostrar();

    //Magnitud de v1
    cout << "Magnitud de v1: " << v1.magnitud() << endl;

    //Producto punto
    cout << "Producto punto: " << productoPunto(v1, v2) << endl;

    //Suma de vectores
    Vector2D suma = v1 + v2;
    cout << "Suma de vectores: ";
    suma.mostrar();

    //Lambda para verificar si la magnitud supera un umbral
    auto superaUmbral = [](const Vector2D &v, double umbral) {
        return v.magnitud() > umbral;
    };

    double umbral = 5.0;
    cout << "¿v1 supera el umbral " << umbral << "? "
         << (superaUmbral(v1, umbral) ? "Sí" : "No") << endl;

    return 0;
}