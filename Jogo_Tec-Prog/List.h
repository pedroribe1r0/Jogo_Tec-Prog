#include <iostream>

template <class T>
class List {
public:
    template<class T2>
    class Node {
    private:
        T2* data;
        Node<T2>* next;
        Node<T2>* prev;
    public:
        Node() : data(nullptr), next(nullptr), prev(nullptr) {}

        ~Node() {
            //delete data;
            data = nullptr;
            next = nullptr;
            prev = nullptr;
        }

        void setData(T2* data) {
            this->data = data;
        }

        void setNext(Node<T2>* n) {
            next = n;
        }

        void setPrev(Node<T2>* p) {
            prev = p;
        }

        T2* getData() const {
            return data;
        }

        Node<T2>* getNext() const {
            return next;
        }

        Node<T2>* getPrev() const {
            return prev;
        }
    };

    class iterator {
    private:
        Node<T>* current;
    public:
        iterator(Node<T>* n = nullptr) : current(n) {}

        // Operador de desreferencia��o
        T* operator*() {
            return (current->getData());
        }

        // Operador de incremento prefixado
        iterator& operator++() {
            current = current->getNext();
            return *this;
        }

        // Operador de decremento prefixado
        iterator& operator--() {
            current = current->getPrev();
            return *this;
        }

        // Operador de igualdade
        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        // Operador de desigualdade
        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

        // Operador de atribui��o
        iterator& operator=(const iterator& other) {
            if (this != &other) {
                current = other.current;
            }
            return *this;
        }
    };

    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        clear();
    }

    void push_back(T* data) {
        if (data == nullptr) {
            std::cout << "Valor Inv�lido" << std::endl;
            return;
        }
        Node<T>* aux = new Node<T>;
        aux->setData(data);
        if (head == nullptr) {
            head = tail = aux;
        }
        else {
            tail->setNext(aux);
            aux->setPrev(tail);
            tail = aux;
        }
        size++;
    }

    int getSize() const {
        return size;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->getNext();
            if (current->getData()) {
                delete current->getData(); // Deleta os dados armazenados no n�
            }
            delete current; // Deleta o n� em si
            current = next; // Atualiza current para o pr�ximo n�
        }
        head = tail = nullptr; // Reseta head e tail para nullptr
    }

    void removeNode(T* data) {
        Node<T>* aux = head;

        // Encontra o n� com os dados especificados
        while (aux != nullptr && aux->getData() != data) {
            aux = aux->getNext();
        }

        // Se o n� foi encontrado
        if (aux != nullptr) {
            if (aux == head) {
                head = aux->getNext(); // Atualiza o head
                if (head != nullptr) {
                    head->setPrev(nullptr); // Se houver novo head, remove refer�ncia ao n� antigo
                }
            }
            else if (aux == tail) {
                tail = aux->getPrev(); // Atualiza o tail
                if (tail != nullptr) {
                    tail->setNext(nullptr); // Se houver novo tail, remove refer�ncia ao n� antigo
                }
            }
            else {
                aux->getPrev()->setNext(aux->getNext()); // Atualiza ponteiro do n� anterior
                aux->getNext()->setPrev(aux->getPrev()); // Atualiza ponteiro do n� seguinte
            }

            // Libera a mem�ria do n� removido
            delete aux;

            // Caso tenha removido o �nico elemento, defina head e tail como nullptr
            if (head == nullptr || tail == nullptr) {
                head = nullptr;
                tail = nullptr;
            }
        }
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

