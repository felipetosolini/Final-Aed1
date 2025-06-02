#include <iostream>
#include <functional>
#include <vector>
using namespace std;

// ------------------ CLASES DE ESTRUCTURAS DE DATOS ------------------


// ------------------ NODO GENERICO ------------------
template <typename T>
struct Nodo {
public:
    T dato;
    Nodo* siguiente;
    Nodo* anterior; // Solo usado en lista doble
    Nodo(T d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
};

// ------------------ LISTA ENLAZADA SIMPLE ------------------
template<typename T>
class ListaEnlazada {
protected:
    class Nodo {
    public:
        T dato;
        Nodo* sig;
        Nodo(T valor) : dato(valor), sig(nullptr) {}
    };
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->sig;
            delete temp;
        }
    }

    void agregarAlFinal(T valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->sig != nullptr) {
                actual = actual->sig;
            }
            actual->sig = nuevo;
        }
    }

    void agregarAlInicio(T valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->sig = cabeza;
        cabeza = nuevo;
    }

    // Elimina el ultimo nodo de la lista enlazada
    // Elimina el ultimo nodo de la lista enlazada y devuelve su valor. Si la lista esta vacia, retorna T().
    T eliminarUltimo() {
        if (cabeza == nullptr) {
            return T();
        }
        if (cabeza->sig == nullptr) {
            T valor = cabeza->dato;
            delete cabeza;
            cabeza = nullptr;
            return valor;
        }
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;
        while (actual->sig != nullptr) {
            anterior = actual;
            actual = actual->sig;
        }
        T valor = actual->dato;
        anterior->sig = nullptr;
        delete actual;
        return valor;
    }

    // Elimina el primer nodo de la lista enlazada y devuelve su valor. Si la lista esta vacia, retorna T().
    T eliminarPrimero() {
        if (cabeza == nullptr) {
            return T();
        }
        Nodo* temp = cabeza;
        T valor = temp->dato;
        cabeza = cabeza->sig;
        delete temp;
        return valor;
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }
};

// ------------------ LISTA DOBLEMENTE ENLAZADA ------------------
template<typename T>
class ListaDobleEnlazada {
public:
    class Nodo {
    public:
        T dato;
        Nodo* sig;
        Nodo* ant;
        Nodo(T valor) : dato(valor), sig(nullptr), ant(nullptr) {}
    };
    Nodo* cabeza;
    Nodo* cola;
public:
    ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr) {}

    ~ListaDobleEnlazada() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->sig;
            delete temp;
        }
    }

    void agregarAlFinal(T valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            cola->sig = nuevo;
            nuevo->ant = cola;
            cola = nuevo;
        }
    }

    void agregarAlInicio(T valor) {
        Nodo* nuevo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            cola = nuevo;
        } else {
            nuevo->sig = cabeza;
            cabeza->ant = nuevo;
            cabeza = nuevo;
        }
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

};

// ------------------ PILA (LIFO)  ------------------

template<typename T>
class Pila
{
protected:
    class Nodo
    {
    public:
        T info;
        Nodo *sig;
        Nodo(T valor) : info(valor), sig(nullptr) {}
        Nodo() : sig(nullptr) {}
    };
    Nodo *raiz;

public:
    Pila()
    { 
        raiz = NULL;   
    };
    ~Pila(){
        Nodo *reco = raiz;
        Nodo *bor;
        while (reco != NULL)
        {
            bor = reco;
            reco = reco->sig;
            delete bor;
        }
    }
    void insertar(T x){
        Nodo *nuevo;
        nuevo = new Nodo();
        nuevo->info = x;
        if (raiz == NULL)
        {
            raiz = nuevo;
            nuevo->sig = NULL;
        }
        else
        {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
    };
    T extraer(){
        if (raiz != NULL)
        {
            T informacion = raiz->info;
            Nodo *bor = raiz;
            raiz = raiz->sig;
            delete bor;
            return informacion;
        }
        else
        {
            return T();
        }
    }
    bool estaVacia() {

        return raiz == NULL;
    };
};

// ------------------ FILA (FIFO) ------------------

template<typename T>
class Fila
{
protected:
    class Nodo
    {
    public:
        T info;
        Nodo *sig;
    };
    Nodo *frente;
    Nodo *fondo;

public:
    Fila()
    {
        frente = NULL;
        fondo = NULL;
    };
    ~Fila()
    {
        Nodo *reco = frente;
        Nodo *bor;
        while (reco != NULL)
        {
            bor = reco;
            reco = reco->sig;
            delete bor;
        }
    };
    void insertar(T x)
    {
        Nodo *nuevo = new Nodo();
        nuevo->info = x;
        nuevo->sig = NULL;
        if (fondo == NULL)
        {
            frente = nuevo;
            fondo = nuevo;
        }
        else
        {
            fondo->sig = nuevo;
            fondo = nuevo;
        }
    };
    T extraer()
    {
        if (frente != NULL)
        {
            T informacion = frente->info;
            Nodo *bor = frente;
            frente = frente->sig;
            if (frente == NULL)
            {
                fondo = NULL;
            }
            delete bor;
            return informacion;
        }
        else
        {
            return T();
        }
    };
    bool estaVacia() {
        return frente == NULL;
    };
};

// ------------------ CLASE FILA CON METODOS ------------------

template<typename T>
class Filon : public Fila<T> {

public:
    T obtenerMaximo() {
        if (this->estaVacia()) {
            cout << "La fila esta vacia\n";
            return T();
        }
        Fila<T> auxiliar;
        T maximo = this->extraer();
        auxiliar.insertar(maximo);

        while (!this->estaVacia()) {
            T elemento = this->extraer();
            if (elemento > maximo) {
                maximo = elemento;
            }
            auxiliar.insertar(elemento);
        }

        while (!auxiliar.estaVacia()) {
            this->insertar(auxiliar.extraer());
        }

        return maximo;
    }
    void imprimir() {
        typename Fila<T>::Nodo *reco = this->frente;
        cout << "Listado de todos los elementos de la fila.\n";
        while (reco != NULL)
        {
            cout << reco->info << "-";
            reco = reco->sig;
        }
        cout << "\n";
    };
    T obtenerCima() {
        if (this->frente != NULL)
        {
            return this->frente->info;
        }
        else
        {
            cout << "La fila esta vacia.\n";
            return T();
        }
    };
};

// ------------------ CLASE LISTA ENLAZADA CON METODOS ------------------

template <typename T>
class Liston : public ListaEnlazada<T> {
public:
    // Alias para evitar escribir todo el tipo largo
    using Nodo = typename ListaEnlazada<T>::Nodo;

    void imprimir() {
        Nodo* actual = this->cabeza;
        cout << "Lista: ";
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->sig;
        }
        cout << endl;
    }

    Nodo* obtenerCabeza() {
        if (this->cabeza != nullptr) {
            return this->cabeza;
        } else {
            cout << "La lista esta vacia.\n";
            return nullptr;
        }
    }

    bool existe(T valor) {
        Nodo* actual = this->cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true; // Valor encontrado
            }
            actual = actual->sig;
        }
        return false; // Valor no encontrado
    }
};

// ------------------ CLASE LISTA DOBLEMENTE ENLAZADA CON METODOS ------------------
template <typename T>
class ListonDoble : public ListaDobleEnlazada<T> {
    public:
    void imprimir() {
        typename ListaDobleEnlazada<T>::Nodo* actual = this->cabeza;
        cout << "Lista Doble: ";
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->sig;
        }
        cout<<endl;
    }

    bool existe(T valor) {
        typename ListaDobleEnlazada<T>::Nodo* actual = this->cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true; // Valor encontrado
            }
            actual = actual->sig;
        }
        return false; // Valor no encontrado
    }

    // Eliminar nodo especifico por valor
    void eliminar(T valor) {
        typename ListaDobleEnlazada<T>::Nodo* actual = this->cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                if (actual->ant != nullptr) {
                    actual->ant->sig = actual->sig;
                } else {
                    this->cabeza = actual->sig; // Actualizar cabeza si es el primer nodo
                }
                if (actual->sig != nullptr) {
                    actual->sig->ant = actual->ant;
                } else {
                    this->cola = actual->ant; // Actualizar cola si es el ultimo nodo
                }
                delete actual;
                return; // Salir despues de eliminar el nodo
            }
            actual = actual->sig;
        }
        cout << "Valor no encontrado en la lista.\n";
    }

    typename ListaDobleEnlazada<T>::Nodo* obtenerCabeza() {
        if (this->cabeza != nullptr) {
            return this->cabeza;
        } else {
            cout << "La lista esta vacia.\n";
            return nullptr;
        }
    }
};

/*Clase que hereda de pila que obtiene el valor minimo y otro del maximo de la pila, el ultimo valor, y 
muestra los valores de la pila sin eliminarlos*/

// ------------------ CLASE PILA CON METODOS ------------------

template<typename T>
class Pilon : public Pila<T> {
public:
    T obtenerMinimo() {
        if (this->estaVacia()) {
            cout<<"La pila esta vacia\n";
            return 0;
        }
        Pila<T> auxiliar;
        T minimo = this->extraer();
        auxiliar.insertar(minimo);

        while (!this->estaVacia()) {
            T elemento = this->extraer();
            if (elemento < minimo) {
                minimo = elemento;
            }
            auxiliar.insertar(elemento);
        }

        while (!auxiliar.estaVacia()) {
            this->insertar(auxiliar.extraer());
        }

        return minimo;
    }
    void imprimir() {
        typename Pila<T>::Nodo *reco = this->raiz;
        cout << "Listado de todos los elementos de la pila.\n";
        while (reco != NULL)
        {
            cout << reco->info << "-";
            reco = reco->sig;
        }
        cout << "\n";
    };
    T obtenerMaximo(){
        if (this->estaVacia()){
            cout<<"La pila esta vacia\n";
            return 0;
        }
        Pila<T> auxiliar;
        T maximo = this->extraer();
        auxiliar.insertar(maximo);
        while(!this->estaVacia()){
            T elemento = this->extraer();
            if(elemento > maximo){
                maximo = elemento;
            }
            auxiliar.insertar(elemento);
        }
        while(!auxiliar.estaVacia()){
            this->insertar(auxiliar.extraer());
        }
        return maximo;
    }
    T obtenerCima() 
    {
        if (this->raiz != NULL)
        {
            return this->raiz->info;
        }
        else
        {
            cout << "La pila esta vacia.\n";
            return T();
        }
    };

};

// ------------------ ARBOL BINARIO DE BUSQUEDA (ABB) ------------------

template<typename T>
class ArbolBinario {
private:
    class NodoBinario {
    public:
        T dato;
        NodoBinario* izquierdo;
        NodoBinario* derecho;

        NodoBinario(T valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
    };
    NodoBinario* raiz;

    void preordenRecursivo(NodoBinario* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";
            preordenRecursivo(nodo->izquierdo);
            preordenRecursivo(nodo->derecho);
        }
    }

    void inordenRecursivo(NodoBinario* nodo) {
        if (nodo != nullptr) {
            inordenRecursivo(nodo->izquierdo);
            cout << nodo->dato << " ";
            inordenRecursivo(nodo->derecho);
        }
    }

    void postordenRecursivo(NodoBinario* nodo) {
        if (nodo != nullptr) {
            postordenRecursivo(nodo->izquierdo);
            postordenRecursivo(nodo->derecho);
            cout << nodo->dato << " ";
        }
    }

    void descendenteRecursivo(NodoBinario* nodo) {
        if (nodo != nullptr) {
            descendenteRecursivo(nodo->derecho);
            cout << nodo->dato << " ";
            descendenteRecursivo(nodo->izquierdo);
        }
    }

    typename ArbolBinario<T>::NodoBinario* insertarRecursivo(typename ArbolBinario<T>::NodoBinario* nodo, T valor) {
        if (nodo == nullptr) {
            return new NodoBinario(valor);
        }
        if (valor < nodo->dato) {
            nodo->izquierdo = insertarRecursivo(nodo->izquierdo, valor);
        } else if (valor > nodo->dato) {
            nodo->derecho = insertarRecursivo(nodo->derecho, valor);
        }
        return nodo;
    }

    typename ArbolBinario<T>::NodoBinario* eliminarRecursivo(typename ArbolBinario<T>::NodoBinario* nodo, T valor) {
        if (nodo == nullptr) {
            return nullptr;
        }
        if (valor < nodo->dato) {
            nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, valor);
        } else if (valor > nodo->dato) {
            nodo->derecho = eliminarRecursivo(nodo->derecho, valor);
        } else {
            // Nodo encontrado
            if (nodo->izquierdo == nullptr) {
                NodoBinario* temp = nodo->derecho;
                delete nodo;
                return temp;
            } else if (nodo->derecho == nullptr) {
                NodoBinario* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            } else {
                // Nodo con dos hijos
                NodoBinario* temp = encontrarMinimo(nodo->derecho);
                nodo->dato = temp->dato;
                nodo->derecho = eliminarRecursivo(nodo->derecho, temp->dato);
            }
        }
        return nodo;
    }

    typename ArbolBinario<T>::NodoBinario* encontrarMinimo(typename ArbolBinario<T>::NodoBinario* nodo) {
        while (nodo->izquierdo != nullptr) {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }

    int conteoRecursivo(typename ArbolBinario<T>::NodoBinario* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return 1 + conteoRecursivo(nodo->izquierdo) + conteoRecursivo(nodo->derecho);
    }

    int alturaRecursiva(typename ArbolBinario<T>::NodoBinario* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        int alturaIzquierda = alturaRecursiva(nodo->izquierdo);
        int alturaDerecha = alturaRecursiva(nodo->derecho);
        return 1 + max(alturaIzquierda, alturaDerecha);
    }

    bool existeRecursivo(typename ArbolBinario<T>::NodoBinario* nodo, T valor) {
        if (nodo == nullptr) {
            return false;
        }
        if (nodo->dato == valor) {
            return true;
        }
        return existeRecursivo(nodo->izquierdo, valor) || existeRecursivo(nodo->derecho, valor);
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(T valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void eliminar(T valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }

    void preorden() {
        cout << "Recorrido Preorden: ";
        preordenRecursivo(raiz);
        cout << endl;
    }

    void inorden() {
        cout << "Recorrido Inorden: ";
        inordenRecursivo(raiz);
        cout << endl;
    }

    void postorden() {
        cout << "Recorrido Postorden: ";
        postordenRecursivo(raiz);
        cout << endl;
    }

    void descendente() {
        cout << "Recorrido Descendente: ";
        descendenteRecursivo(raiz);
        cout << endl;
    }

    int contador() {
        return conteoRecursivo(raiz);
    }

    int altura() {
        return alturaRecursiva(raiz);
    }

    bool existe(T valor) {
        return existeRecursivo(raiz, valor);
    }
};

// ------------------ ARBOL AVL ------------------

template<typename T>
class ArbolAVL {
private:
    class NodoAVL {
    public:
        T dato;
        NodoAVL* izquierdo;
        NodoAVL* derecho;
        int altura;

        NodoAVL(T valor) : dato(valor), izquierdo(nullptr), derecho(nullptr), altura(1) {}
    };

    NodoAVL* raiz;

    int obtenerAltura(NodoAVL* nodo) {
        return nodo == nullptr ? 0 : nodo->altura;
    }

    int obtenerBalance(NodoAVL* nodo) {
        return nodo == nullptr ? 0 : obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
    }

    NodoAVL* rotacionDerecha(NodoAVL* y) {
        NodoAVL* x = y->izquierdo;
        NodoAVL* T2 = x->derecho;

        x->derecho = y;
        y->izquierdo = T2;

        y->altura = 1 + max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho));
        x->altura = 1 + max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho));

        return x;
    }

    NodoAVL* rotacionIzquierda(NodoAVL* x) {
        NodoAVL* y = x->derecho;
        NodoAVL* T2 = y->izquierdo;

        y->izquierdo = x;
        x->derecho = T2;

        x->altura = 1 + max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho));
        y->altura = 1 + max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho));

        return y;
    }

    NodoAVL* insertarRecursivo(NodoAVL* nodo, T valor) {
        if (nodo == nullptr) {
            return new NodoAVL(valor);
        }

        if (valor < nodo->dato) {
            nodo->izquierdo = insertarRecursivo(nodo->izquierdo, valor);
        } else if (valor > nodo->dato) {
            nodo->derecho = insertarRecursivo(nodo->derecho, valor);
        } else {
            return nodo; // No se permiten valores duplicados
        }

        nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

        int balance = obtenerBalance(nodo);

        // Rotaciones para balancear el arbol
        if (balance > 1 && valor < nodo->izquierdo->dato) {
            return rotacionDerecha(nodo);
        }
        if (balance < -1 && valor > nodo->derecho->dato) {
            return rotacionIzquierda(nodo);
        }
        if (balance > 1 && valor > nodo->izquierdo->dato) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            return rotacionDerecha(nodo);
        }
        if (balance < -1 && valor < nodo->derecho->dato) {
            nodo->derecho = rotacionDerecha(nodo->derecho);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    NodoAVL* eliminarRecursivo(NodoAVL* nodo, T valor) {
        if (nodo == nullptr) {
            return nodo;
        }

        if (valor < nodo->dato) {
            nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, valor);
        } else if (valor > nodo->dato) {
            nodo->derecho = eliminarRecursivo(nodo->derecho, valor);
        } else {
            if (nodo->izquierdo == nullptr || nodo->derecho == nullptr) {
                NodoAVL* temp = nodo->izquierdo ? nodo->izquierdo : nodo->derecho;
                if (temp == nullptr) {
                    temp = nodo;
                    nodo = nullptr;
                } else {
                    *nodo = *temp;
                }
                delete temp;
            } else {
                NodoAVL* temp = encontrarMinimo(nodo->derecho);
                nodo->dato = temp->dato;
                nodo->derecho = eliminarRecursivo(nodo->derecho, temp->dato);
            }
        }

        if (nodo == nullptr) {
            return nodo;
        }

        nodo->altura = 1 + max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

        int balance = obtenerBalance(nodo);

        if (balance > 1 && obtenerBalance(nodo->izquierdo) >= 0) {
            return rotacionDerecha(nodo);
        }
        if (balance > 1 && obtenerBalance(nodo->izquierdo) < 0) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            return rotacionDerecha(nodo);
        }
        if (balance < -1 && obtenerBalance(nodo->derecho) <= 0) {
            return rotacionIzquierda(nodo);
        }
        if (balance < -1 && obtenerBalance(nodo->derecho) > 0) {
            nodo->derecho = rotacionDerecha(nodo->derecho);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    NodoAVL* encontrarMinimo(NodoAVL* nodo) {
        while (nodo->izquierdo != nullptr) {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }

    void preordenRecursivo(NodoAVL* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";
            preordenRecursivo(nodo->izquierdo);
            preordenRecursivo(nodo->derecho);
        }
    }

    void inordenRecursivo(NodoAVL* nodo) {
        if (nodo != nullptr) {
            inordenRecursivo(nodo->izquierdo);
            cout << nodo->dato << " ";
            inordenRecursivo(nodo->derecho);
        }
    }

    void postordenRecursivo(NodoAVL* nodo) {
        if (nodo != nullptr) {
            postordenRecursivo(nodo->izquierdo);
            postordenRecursivo(nodo->derecho);
            cout << nodo->dato << " ";
        }
    }

public:
    ArbolAVL() : raiz(nullptr) {}

    void insertar(T valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void eliminar(T valor) {
        raiz = eliminarRecursivo(raiz, valor);
    }

    void preorden() {
        cout << "Recorrido Preorden: ";
        preordenRecursivo(raiz);
        cout << endl;
    }

    void inorden() {
        cout << "Recorrido Inorden: ";
        inordenRecursivo(raiz);
        cout << endl;
    }

    void postorden() {
        cout << "Recorrido Postorden: ";
        postordenRecursivo(raiz);
        cout << endl;
    }

    void bfs() {
        if (raiz == nullptr) {
            cout << "El arbol esta vacio.\n";
            return;
        }

        Filon<NodoAVL*> cola;
        cola.insertar(raiz);

        cout << "Recorrido BFS: ";
        while (!cola.estaVacia()) {
            NodoAVL* actual = cola.obtenerCima();
            cola.extraer();

            cout << actual->dato << " ";

            if (actual->izquierdo != nullptr) {
                cola.insertar(actual->izquierdo);
            }
            if (actual->derecho != nullptr) {
                cola.insertar(actual->derecho);
            }
        }
        cout << endl;
    }
    
    bool buscar(T valor) {
        NodoAVL* actual = raiz;
        while (actual != nullptr) {
            if (valor < actual->dato) {
                actual = actual->izquierdo;
            } else if (valor > actual->dato) {
                actual = actual->derecho;
            } else {
                return true; // Valor encontrado
            }
        }
        return false; // Valor no encontrado
    }
};

// ------------------ ARBOL ROJO-Negro ------------------

template<typename T>
class ArbolRojoNegro {
private:
    enum Color { ROJO, NEGRO };

    class NodoRN {
    public:
        T dato;
        Color color;
        NodoRN* izquierdo;
        NodoRN* derecho;
        NodoRN* padre;

        NodoRN(T valor) : dato(valor), color(ROJO), izquierdo(nullptr), derecho(nullptr), padre(nullptr) {}
    };

    NodoRN* raiz;

    void rotacionIzquierda(NodoRN* x) {
        NodoRN* y = x->derecho;
        x->derecho = y->izquierdo;
        if (y->izquierdo != nullptr) {
            y->izquierdo->padre = x;
        }
        y->padre = x->padre;
        if (x->padre == nullptr) {
            raiz = y;
        } else if (x == x->padre->izquierdo) {
            x->padre->izquierdo = y;
        } else {
            x->padre->derecho = y;
        }
        y->izquierdo = x;
        x->padre = y;
    }

    void rotacionDerecha(NodoRN* x) {
        NodoRN* y = x->izquierdo;
        x->izquierdo = y->derecho;
        if (y->derecho != nullptr) {
            y->derecho->padre = x;
        }
        y->padre = x->padre;
        if (x->padre == nullptr) {
            raiz = y;
        } else if (x == x->padre->derecho) {
            x->padre->derecho = y;
        } else {
            x->padre->izquierdo = y;
        }
        y->derecho = x;
        x->padre = y;
    }

    void arreglarInsercion(NodoRN* nodo) {
        while (nodo->padre != nullptr && nodo->padre->color == ROJO) {
            if (nodo->padre == nodo->padre->padre->izquierdo) {
                NodoRN* tio = nodo->padre->padre->derecho;
                if (tio != nullptr && tio->color == ROJO) {
                    nodo->padre->color = NEGRO;
                    tio->color = NEGRO;
                    nodo->padre->padre->color = ROJO;
                    nodo = nodo->padre->padre;
                } else {
                    if (nodo == nodo->padre->derecho) {
                        nodo = nodo->padre;
                        rotacionIzquierda(nodo);
                    }
                    nodo->padre->color = NEGRO;
                    nodo->padre->padre->color = ROJO;
                    rotacionDerecha(nodo->padre->padre);
                }
            } else {
                NodoRN* tio = nodo->padre->padre->izquierdo;
                if (tio != nullptr && tio->color == ROJO) {
                    nodo->padre->color = NEGRO;
                    tio->color = NEGRO;
                    nodo->padre->padre->color = ROJO;
                    nodo = nodo->padre->padre;
                } else {
                    if (nodo == nodo->padre->izquierdo) {
                        nodo = nodo->padre;
                        rotacionDerecha(nodo);
                    }
                    nodo->padre->color = NEGRO;
                    nodo->padre->padre->color = ROJO;
                    rotacionIzquierda(nodo->padre->padre);
                }
            }
        }
        raiz->color = NEGRO;
    }

    void preordenRecursivo(NodoRN* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << (nodo->color == ROJO ? " (R) " : " (N) ");
            preordenRecursivo(nodo->izquierdo);
            preordenRecursivo(nodo->derecho);
        }
    }

    void postordenRecursivo(NodoRN* nodo) {
        if (nodo != nullptr) {
            postordenRecursivo(nodo->izquierdo);
            postordenRecursivo(nodo->derecho);
            cout << nodo->dato << (nodo->color == ROJO ? " (R) " : " (N) ");
        }
    }

    void inordenRecursivo(NodoRN* nodo) {
        if (nodo != nullptr) {
            inordenRecursivo(nodo->izquierdo);
            cout << nodo->dato << (nodo->color == ROJO ? " (R) " : " (N) ");
            inordenRecursivo(nodo->derecho);
        }
    }

    void inordenDescendenteRecursivo(NodoRN* nodo) {
        if (nodo != nullptr) {
            inordenDescendenteRecursivo(nodo->derecho);
            cout << nodo->dato << (nodo->color == ROJO ? " (R) " : " (N) ");
            inordenDescendenteRecursivo(nodo->izquierdo);
        }
    }

    void recorridoProfundidad() {
        preordenRecursivo(raiz);
        cout << endl;
    }


public:
    ArbolRojoNegro() : raiz(nullptr) {}

    void insertar(T valor) {
        NodoRN* nuevo = new NodoRN(valor);
        NodoRN* y = nullptr;
        NodoRN* x = raiz;

        while (x != nullptr) {
            y = x;
            if (nuevo->dato < x->dato) {
                x = x->izquierdo;
            } else {
                x = x->derecho;
            }
        }

        nuevo->padre = y;
        if (y == nullptr) {
            raiz = nuevo;
        } else if (nuevo->dato < y->dato) {
            y->izquierdo = nuevo;
        } else {
            y->derecho = nuevo;
        }

        arreglarInsercion(nuevo);
    }

    void preorden() {
        cout << "Recorrido Preorden: ";
        preordenRecursivo(raiz);
        cout << endl;
    }

    void postorden() {
        cout << "Recorrido Postorden: ";
        postordenRecursivo(raiz);
        cout << endl;
    }

    void inorden() {
        cout << "Recorrido Inorden: ";
        inordenRecursivo(raiz);
        cout << endl;
    }

    void inordenDescendente() {
        cout << "Recorrido Inorden Descendente: ";
        inordenDescendenteRecursivo(raiz);
        cout << endl;
    }

    void bfs() {
        if (raiz == nullptr) {
            cout << "El arbol esta vacio.\n";
            return;
        }

        Filon<NodoRN*> cola;
        cola.insertar(raiz);

        cout << "Recorrido BFS: ";
        while (!cola.estaVacia()) {
            NodoRN* actual = cola.obtenerCima();
            cola.extraer();

            cout << actual->dato << (actual->color == ROJO ? " (R) " : " (N) ") << " ";

            if (actual->izquierdo != nullptr) {
                cola.insertar(actual->izquierdo);
            }
            if (actual->derecho != nullptr) {
                cola.insertar(actual->derecho);
            }
        }
        cout << endl;
    }

    void obtenerRecorridoProfundidad() {
        cout << "Recorrido en profundidad: ";
        recorridoProfundidad();
    }


};

// ------------------ TABLA HASH ------------------

template<typename K, typename V>
class TablaHash {
private:
    static const int TAMANIO = 100; // Tamaño de la tabla hash

    struct Nodo {
        K clave;
        V valor;
        Nodo* siguiente;
        Nodo(const K& k, const V& v, Nodo* sig = nullptr)
            : clave(k), valor(v), siguiente(sig) {}
    };

    Nodo* tabla[TAMANIO];

    size_t calcularHash(const K& clave) const {
        return std::hash<K>{}(clave) % TAMANIO;
    }

    void liberarMemoria() {
        for (int i = 0; i < TAMANIO; ++i) {
            Nodo* actual = tabla[i];
            while (actual != nullptr) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
            tabla[i] = nullptr;
        }
    }

public:
    TablaHash() {
        for (int i = 0; i < TAMANIO; ++i) {
            tabla[i] = nullptr;
        }
    }

    ~TablaHash() {
        liberarMemoria();
    }

    // Inserta una clave con su valor
    void insertar(const K& clave, const V& valor) {
        size_t indice = calcularHash(clave);
        Nodo* actual = tabla[indice];
        while (actual != nullptr) {
            if (actual->clave == clave) {
                actual->valor = valor; // Actualiza si ya existe
                return;
            }
            actual = actual->siguiente;
        }
        tabla[indice] = new Nodo(clave, valor, tabla[indice]);
    }

    // Elimina una clave existente
    void eliminar(const K& clave) {
        size_t indice = calcularHash(clave);
        Nodo* actual = tabla[indice];
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->clave == clave) {
                if (anterior == nullptr) {
                    tabla[indice] = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        }

        throw invalid_argument("Clave no encontrada");
    }

    // Devuelve el valor asociado a una clave
    V obtener(const K& clave) const {
        size_t indice = calcularHash(clave);
        Nodo* actual = tabla[indice];
        while (actual != nullptr) {
            if (actual->clave == clave) {
                return actual->valor;
            }
            actual = actual->siguiente;
        }
        throw invalid_argument("Clave no encontrada");
    }

    // Verifica si una clave existe
    bool existe(const K& clave) const {
        size_t indice = calcularHash(clave);
        Nodo* actual = tabla[indice];
        while (actual != nullptr) {
            if (actual->clave == clave) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Imprime todos los elementos de la tabla
    void imprimir() const {
        for (int i = 0; i < TAMANIO; ++i) {
            Nodo* actual = tabla[i];
            while (actual != nullptr) {
                cout << "[" << actual->clave << "] = " << actual->valor << endl;
                actual = actual->siguiente;
            }
        }
    }

    // NUEVO: Obtener todos los valores
    std::vector<V> obtenerValores() const {
        std::vector<V> valores;
        for (int i = 0; i < TAMANIO; ++i) {
            Nodo* actual = tabla[i];
            while (actual != nullptr) {
                valores.push_back(actual->valor);
                actual = actual->siguiente;
            }
        }
        return valores;
    }

    // NUEVO: Saber si la tabla está vacía
    bool vacia() const {
        for (int i = 0; i < TAMANIO; ++i) {
            if (tabla[i] != nullptr) return false;
        }
        return true;
    }
};

