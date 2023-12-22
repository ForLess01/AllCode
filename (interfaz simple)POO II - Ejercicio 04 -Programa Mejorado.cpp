#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Volumen {
protected:
    string nombre;
    int numVol;

public:
    Volumen(string n, int num) : nombre(n), numVol(num) {}
    virtual void mostrar() = 0; // Método virtual puro para hacer la clase abstracta
};

class Libro : public Volumen {
private:
    static int numLibros;

public:
    Libro(string n, int num) : Volumen(n, num) { ++numLibros; }
    
    void mostrar() override {
        cout << "Libro: " << nombre << ", Volumen: " << numVol << endl;
    }

    static int getNumLibros() { return numLibros; }
};

int Libro::numLibros = 0; // Inicialización de la variable estática

class Revista : public Volumen {
private:
    static int numRevistas;

public:
    Revista(string n, int num) : Volumen(n, num) { ++numRevistas; }

    void mostrar() override {
        cout << "Revista: " << nombre << ", Volumen: " << numVol << endl;
     }

     static int getNumRevistas() { return numRevistas; }
};

int Revista::numRevistas = 0; // Inicialización de la variable estática

class Biblioteca;  // Declaración adelantada de la clase Biblioteca

class Usuario {
public:
    string nombre;
    vector<Volumen*> prestamos;
    Biblioteca* biblioteca;  // Relación con la Biblioteca

public:
    Usuario(string n, Biblioteca* b) : nombre(n), biblioteca(b) {}

    bool prestar(Volumen* v);

    void mostrarPrestamos(){
        for(Volumen* v: prestamos){
            v->mostrar();
        }
    }
    void mostrarUsuario() {
        cout << "Nombre del usuario: " << nombre << endl;
        cout << "Número de préstamos: " << prestamos.size() << endl;
        cout << "Préstamos:" << endl;
        mostrarPrestamos();
        cout<<endl;
    }
};

class Biblioteca {
private:
   vector<Volumen*> volumenes;
   vector<Usuario*> usuarios;
   const int maxLibros;
   const int maxRevistas;

public:
   Biblioteca(int maxL, int maxR): maxLibros(maxL), maxRevistas(maxR){}

   bool incluir(Volumen* v){
       if(dynamic_cast<Libro*>(v)){
           if(Libro::getNumLibros() > maxLibros)
               return false;
       } else if(dynamic_cast<Revista*>(v)){
           if(Revista::getNumRevistas() > maxRevistas)
               return false;
       }
       
       volumenes.push_back(v);
       return true;
   }

   bool agregarUsuario(Usuario* u){
       usuarios.push_back(u);
       return true;
   }

   void mostrarBiblioteca(){
      for(Volumen* v: volumenes){
          v->mostrar();
      }
   }
   Usuario* getUsuarioPorNombre(string nombre) {
        for (Usuario* u : usuarios) {
            if (u->nombre == nombre) {
                return u;
            }
        }
        return nullptr;
    }
};

class Prestar {
private:
    Usuario* usuario;
    Volumen* volumen;
    Biblioteca* biblioteca;  // Relación con la Biblioteca

public:
    Prestar(Usuario* u, Volumen* v, Biblioteca* b) : usuario(u), volumen(v), biblioteca(b) {}

    void realizarPrestamo() {
        usuario->prestar(volumen);
    }
};

bool Usuario::prestar(Volumen* v){
    prestamos.push_back(v);
    return true;
}
int main() {
    // Crear una biblioteca con un máximo de 10 libros y 5 revistas
    Biblioteca* biblioteca = new Biblioteca(10, 5);

    // Crear n libros, revistas y usuarios
    int n;
    cout << "Ingrese el número de libros, revistas y usuarios que desea crear: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        // Crear un usuario y agregarlo a la biblioteca
        string nombreUsuario;
        cout << "Ingrese el nombre del usuario " << i+1 << ": ";
        cin >> nombreUsuario;
        Usuario* usuario = new Usuario(nombreUsuario, biblioteca);
        biblioteca->agregarUsuario(usuario);
        // Crear un libro
        string nombreLibro;
        int numVolLibro;
        cout << "Ingrese el nombre del libro " << i+1 << ": ";
        cin >> nombreLibro;
        cout << "Ingrese el número de volumen del libro " << i+1 << ": ";
        cin >> numVolLibro;
        Libro* libro = new Libro(nombreLibro, numVolLibro);

        // Crear una revista
        string nombreRevista;
        int numVolRevista;
        cout << "Ingrese el nombre de la revista " << i+1 << ": ";
        cin >> nombreRevista;
        cout << "Ingrese el número de volumen de la revista " << i+1 << ": ";
        cin >> numVolRevista;
        Revista* revista = new Revista(nombreRevista, numVolRevista);

        // Incluir el libro y la revista en la biblioteca
        biblioteca->incluir(libro);
        biblioteca->incluir(revista);

    

        // Crear un préstamo y realizarlo
        Prestar* prestamo = new Prestar(usuario, libro, biblioteca);
        prestamo->realizarPrestamo();
        delete prestamo;  // Limpiar la memoria del préstamo
    }

    // Imprimir cada usuario por nombre, con su número de préstamos y qué préstamos tiene
    for (int i = 0; i < n; ++i) {
        string nombreUsuario;
        cout << "Ingrese el nombre del usuario que desea buscar: ";
        cin >> nombreUsuario;
        Usuario* usuario = biblioteca->getUsuarioPorNombre(nombreUsuario);
        if (usuario != nullptr) {
            usuario->mostrarUsuario();
        }
    }
    cout<<"Datos Proporcionados"<<endl;
    // Limpiar la memoria
    delete biblioteca;

    return 0;
}