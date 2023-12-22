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
private:
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

    // Crear algunos libros y revistas
    Libro* libro1 = new Libro("Atomic Habits", 1);
    Libro* libro2 = new Libro("Marco Aurelio", 2);
    Revista* revista1 = new Revista("Mascaly", 1);

    // Incluir los libros y revistas en la biblioteca
    biblioteca->incluir(libro1);
    biblioteca->incluir(libro2);
    biblioteca->incluir(revista1);

    // Crear un usuario
    Usuario* usuario = new Usuario("Rendo", biblioteca);
    Usuario* usuario2= new Usuario("Pedro", biblioteca); 
    // Agregar el usuario a la biblioteca
    biblioteca->agregarUsuario(usuario);
    biblioteca->agregarUsuario(usuario2);

    // Crear un préstamo
    Prestar* prestamo = new Prestar(usuario, libro1, biblioteca);
    Prestar* prestamo2 = new Prestar(usuario2, libro1, biblioteca);
    Prestar* prestamo3 = new Prestar(usuario2, libro2, biblioteca);
    // Realizar el préstamo
    prestamo->realizarPrestamo();
    prestamo2->realizarPrestamo();
    prestamo3->realizarPrestamo();
    // Mostrar los préstamos del usuario
    /*usuario->mostrarPrestamos();
    usuario2->mostrarPrestamos();*/
    
    usuario->mostrarUsuario();
    usuario2->mostrarUsuario();

    // Limpiar la memoria
    delete prestamo;
    delete usuario;
    delete prestamo2;
    delete usuario2;
    delete revista1;
    delete libro2;
    delete libro1;
    delete biblioteca;

    return 0;
}