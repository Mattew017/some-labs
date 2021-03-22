#include <iostream>

template <typename T>
class Stack
{
private:
    int top = 0; //кол-во элементов
    int MaxSize = 0;
    T* stack;
public:
    Stack(int size)
    {
        stack = new T[size];
        MaxSize = size;
    }
    ~Stack()
    {
        delete[] stack;
    }

    void push(T item)
    {
        if (top >= MaxSize)
        {
            std::cout << "Стэк переполнен!"<< std::endl;
        }
        else 
        {
            stack[top++] = item;
        }
    }

    T pop()
    {
        top--;
        return stack[top];
    }

    void delete_middle()
    {
        if (top % 2 == 0)
        {
            for (int i = top/2 - 1; i < top - 2; i++)
            {
                stack[i] = stack[i+2];
                stack[i+1] = stack[i+3];
            }
            top = top -2;
        }
        else
        {
            for (int  i = top/2; i < top - 1; i++)
            {
                stack[i] = stack[i+1];
            }
            top--;
        }
    }

    void show_stack()
    {
        for (int i = 0; i < top; i++)
            std::cout << stack[i] << " ";
        std::cout << std::endl;
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    int max_size, n, item;
    std::cout << "Введите максимальный размер стека:" << std::endl;
    std::cin >> max_size;
    Stack <int> s(max_size);
    while (true)
    {
        std::cout << "Введите кол-во вводимых элементов:" << std::endl;
        std::cin >> n;
        if (n > max_size)
            std::cout << "Макс. размер стека -- " << max_size << "!" << std::endl;
        else
            break;
    }
    std::cout << "Введите числа для записи их в стек:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> item;
        s.push(item);
    }
    std::cout << "Элементы стэка:" << std::endl;
    s.show_stack();
    std::cout << "Удаление среднего(средних) элементов" << std::endl;
    s.delete_middle();
    s.show_stack();
}
