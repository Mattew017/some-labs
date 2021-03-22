#include <iostream>

//Элемент циклического списка
struct Node {
    int number;
    Node *next;
    //Конструктор
    Node(int n, Node* t) {
        number = n;
        next = t;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    int N, M;
    std::cout << "Введите N - количество воинов, и M -- через скольких убивать:" << std::endl;
    std::cin >> N >> M;
    Node* root = new Node(1, nullptr); //1-ый элемент списка
    root->next= root;  //1-ый элемент указывает на самого себя
    Node* x = root; //x указывет на 1-ый элемент
    for (int i = 2; i <= N; i++) //заполняем список от 2 до N
    {
        x = (x->next = new Node(i, root));
    };
    x = root; 

    while (x->next != x) //пока x не указывет на самого себя(т.е. остался 1 элемент)
    {
        for (int i = 2; i < M; i++)  //переходим к элементу m - 1
            x = x->next;
        Node* killed = x->next; // m -ый элемент
        x->next = (x->next)->next; //удаляем m -ый элемент из списка, m-1 указывает на m+1
        x = x->next;  //переходим к элементу m + 1
        delete killed; //очистка памяти
    }
    
    std::cout <<"Последний выживший воин стоял под номером " << x->number << std::endl;
    return 0;
}
