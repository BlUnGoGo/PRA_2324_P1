#include <iostream>
#include "List.h"
#include <stdexcept>
#include <ostream>
using namespace std;


template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr; //Puntero a inicio array, almacenará los elementos de forma contigua. Estos elementos son de tipo T 
	int max; //Tamaño actual array. Puede alterarse durante la vida de la lista.
	int n; //Numero elementos contiene la lista
	static const int MINSIZE = 2; //Tamaño minimo array
	
	void resize(int new_size){
		T* aux = new T [new_size];
		for(int i = 0; i < n; i++){
			aux[i] = arr[i];
		}
		delete arr;
		arr = aux;
		max = new_size;
	}

    public:
	//Constructor sin argumentos, reserva memoria para array d MINSIZE d elementos T, inicializa el resto d atributos d instancia
	ListArray(){
	arr = new T [MINSIZE];
	max = 2;  //Tamaño mínimo del array cuando se crea
	n = 0;	  //En array estará vacio (0 elementos)
	
	}

	//Destructor
	~ListArray(){
	delete[] arr;
	}

	//Devuelve elemento la posición pos. Lanza excepción std::out_of_range si la posición no es válida
	T operator[](int pos){
		return get(pos);
	}

	//sobrecarga operador << muestra el vector por pantalla
	friend ostream& operator<<(ostream &out, const ListArray<T> &list){
		cout << "Lista: => [" << endl;
		for (int i = 0; i < list.n; i++){
		out << "  "<<list.arr[i] << endl;
		}
		cout << "]" << endl;
		return out;
	}

	//Inserta elemento e d tipo T en la posicion pos
	void insert(int pos, T e) override{
	if(pos < 0 || pos > size())
		throw out_of_range("Posición invalida!");
	else{
		resize(max+1);
		for(int i = n; i > pos; i--){
			T aux = arr[i - 1];
			arr[i] = aux;
		}
	
		arr[pos] = e;
		n++;
	}
	}

        
	//Inserta e final lista
	void append(T e) override{
		resize(max + 1);
		arr[n] = e;
		n++;
	}
        
	
	void prepend(T e) override{
		resize(max+1);
		for(int i = n; i > 0; i--){
                        T aux = arr[i - 1];
                        arr[i] = aux;
                }
		arr[0] = e;
		n++;
	}
        
	//Elimina y devuelve elemento situado en pos
	T remove(int pos) override{
		if(pos < 0 || pos > size()-1){
                throw out_of_range("Posición invalida!");
		}
	    else{
			T aux;
            aux = arr[pos];
			for(int i = pos; i < n; i ++){
				arr[i] = arr[i+1];
		}
		n--;
		return aux;
		}
	}
	//Devuelve el elemento situado en pos
	T get(int pos) override{
		if(pos < 0 || pos > size()-1){
                throw out_of_range("Posición invalida!");
                } 
		else
		return arr[pos];
	}
        
	//Devuelve la pos del elemento e si hay, si no hay -1
	int search(T e) override{
		for(int i = 0; i < size(); i++){
			if(arr[i] == e)
				return i;
		}
		return -1;
	}
	
	//Indica si la lista está vacía
	bool empty() override{
		if(n == 0)
			return true;
		else
			return false;
	}
        
	//Devuelve numero de elementos de la lista
	int size() override{
		return n;	
	} 	
};
