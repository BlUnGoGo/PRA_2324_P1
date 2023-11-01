#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
    Node<T>* first;
    int n;
    public:
    ListLinked(){
        first = nullptr;
        n = 0;
    }
    ~ListLinked(){
        Node<T>* aux = first;
        while(aux != nullptr){
            Node<T>* aux2 = aux->next;
            delete aux;
            aux = aux2;
        }
    }


    T operator[](int pos){
        if(pos < 0 || pos > size()-1)
            throw std::out_of_range("Posición invalida!");
        else{
            Node<T>* aux = first;
            for(int i = 0; i < pos; i++){
                aux = aux->next;
            }
            return aux->data;
        }
    }


    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
        out << "Lista: => [";
        Node<T>* aux = list.first;
        while(aux != nullptr){
            out << aux->data << " ";
            aux = aux->next;
        }
        out << "]";
        return out;
    }


    void insert(int pos, T e) override{ //inserta el elemento e en la posición pos. Lanza una excepción std::out_of_range si la posición pos no es válida (fuera del intervalo [0, size()]).
        if(pos < 0 || pos > size())
            throw std::out_of_range("Posición invalida!");
        else{
            if(pos == 0){
                Node<T>* aux = new Node<T>(e, first);
                first = aux;
            }
            else{
                Node<T>* aux = first;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->next;
                }
                Node<T>* aux2 = new Node<T>(e, aux->next);
                aux->next = aux2;
            }
            n++;
        }
    }


    void append(T e) override{ //Inserta el elemento e al final de la lista.
        if(first == nullptr){
            first = new Node<T>(e);
        }
        else{
            Node<T>* aux = first;
            while(aux->next != nullptr){
                aux = aux->next;
            }
            Node<T>* aux2 = new Node<T>(e);
            aux->next = aux2;
        }
        n++;
    }


    void prepend(T e) override{ //Inserta el elemento e al principio de la lista.
        Node<T>* aux = new Node<T>(e, first);
        first = aux;
        n++;
    }


    T remove(int pos) override{ //Elimina el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición pos no es válida (fuera del intervalo [0, size()-1]).
        if(pos < 0 || pos > size()-1){
            throw std::out_of_range("Posición invalida!");
        }
        else{
            if(pos == 0){
                Node<T>* aux = first;
                first = first->next;
                T aux2 = aux->data;
                delete aux;
                n--;
                return aux2;
            }
            else{
                Node<T>* aux = first;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->next;
                }
                Node<T>* aux2 = aux->next;
                aux->next = aux2->next;
                T aux3 = aux2->data;
                delete aux2;
                n--;
                return aux3;
            }
        }
    }


    T get(int pos) override{ //Devuelve el elemento situado en la posición pos. Lanza una excepción std::out_of_range si la posición pos no es válida (fuera del intervalo [0, size()-1]).
        if(pos < 0 || pos > size()-1){
            throw std::out_of_range("Posición invalida!");
        }
        else{
            Node<T>* aux = first;
            for(int i = 0; i < pos; i++){
                aux = aux->next;
            }
            return aux->data;
        }
    }


    int search(T e) override{ //Devuelve la posición del elemento e si hay, si no hay -1.
        Node<T>* aux = first;
        for(int i = 0; i < size(); i++){
            if(aux->data == e){
                return i;
            }
            aux = aux->next;
        }
        return -1;
    }


    bool empty() override{ //Indica si la lista está vacía.
        return n == 0;
    }


    int size() override{ //Devuelve el número de elementos de la lista.
        return n;
    }
       
};