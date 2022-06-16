#include <iostream>
#include <vector>

template <typename T>
void insertion_to_high(std::vector<T>&);
template <typename T>
void insertion_forward_to_high(std::vector<T>&);
template <typename T>
void insertion_to_low(std::vector<T>&);
template <typename T>
void insertion_forward_to_low(std::vector<T>&);
template <typename T>
void insertion_by_rec_to_low(std::vector<T>&, int);
template <typename T>
void insertion_by_rec_to_high(std::vector<T>&, int);
template <typename T>
void choosing_operation(std::vector<T>&, int&, int);
template <typename T>
void print(std::vector<T>&, int&);
template <typename T>
void initializing_program(std::vector<T>&);
bool is_digit(const char& ch);

int main ()
{
    std::vector<double> vec;
    initializing_program(vec);

    return 0;
}

template <typename T>
void initializing_program(std::vector<T>& vec)
{
    int size{};
    bool flag;
    std::string tmp = "";
    do{
        flag = false;
        std::cout << "Enter the amount of elements: ";
        std::cin >> tmp;
        
        for(int i = 0; i < tmp.size(); ++i)
        {
            
            if(!((is_digit(tmp[i])) || (tmp[i] == '.')))
            {
                flag = true;
                break;
            }
        }
        
    }while(flag);
    size = std::stoi(tmp);
    T elem{};
    std::cout << "\n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << "Enter #" << i + 1 << " element: ";
        std::cin >> elem;
        vec.push_back(elem);
    }
    std::cout << std::endl;
    
    std::cout << "===============================================\n";
    std::cout << "\t\t\t\tMAIN MANU\n";
    std::cout << "===============================================\n";
    std::cout << "Which operation you choose for insertion sort?\n\n";
    std::cout << "\t[1] Iterative from little to high\n" << "\t[2] Iterative from high to little\n" << "\t[3] Iterative from little to high with forward iterator\n" << "\t[4] Iterative from high to little with forward iterator\n" << "\t[5] Recursive from little to high\n" << "\t[6] Recursive from high to little\n" << "\t[7] EXIT\n" << std::endl;
    std::cout << "=================================Your choice: ";
    int index = 0;
    std::cin >> index;
    choosing_operation(vec, size, index);
}

template <typename T>
void choosing_operation(std::vector<T>& vec, int& size, int index)
{
    switch(index)
    {
        case 1:
            insertion_to_high(vec);
            print(vec, size);
            break;
        case 2:
            insertion_to_low(vec);
            print(vec, size);
            break;
        case 3:
            insertion_forward_to_high(vec);
            print(vec, size);
            break;
        case 4:
            insertion_forward_to_low(vec);
            print(vec, size);
            break;
        case 5:
            insertion_by_rec_to_high(vec, size);
            print(vec, size);
            break;
        case 6:
            insertion_by_rec_to_low(vec, size);
            print(vec, size);
            break;
        case 7:
            exit(0);
        default:
            std::cout << "Wrong index, try again: ";
            int ind = 0;
            std::cin >> ind;
            choosing_operation(vec, size, ind);
    }
}

template <typename T>
void insertion_to_high(std::vector<T>& vec) // with random access iterators
{
    typename std::vector<T>::iterator big = vec.begin();
    typename std::vector<T>::iterator end = vec.end();
    typename std::vector<T>::iterator copy = big;
    typename std::vector<T>::iterator jl;
    
    for(big + 2; big != end; ++big)
    {
       T key = *big;
       jl = big - 1;
        
       while(jl >= copy && *jl > key)
        {
            *(jl + 1) = *jl;
            jl = jl - 1;
        }
        
        *(jl + 1) = key;
    }
}

template <typename T>
void insertion_to_low(std::vector<T>& vec)
{
    typename std::vector<T>::iterator big = vec.begin();
    typename std::vector<T>::iterator end = vec.end();
    typename std::vector<T>::iterator copy = big;
    typename std::vector<T>::iterator jl;
    
    for(big + 2; big != end; ++big)
    {
       T key = *big;
       jl = big - 1;
        
       while(jl >= copy && *jl < key)
        {
            *(jl + 1) = *jl;
            jl = jl - 1;
        }
        
        *(jl + 1) = key;
    }
}

template <typename T>
void insertion_forward_to_high(std::vector<T>& vec) // by forward iterator
{
        typename std::vector< T >::iterator it = vec.begin();
        for (int i = 1; i < vec.size(); i++)
        {
            T key = *(it + i);
            for (int j = i - 1; j >= 0 && *(it + j) > key; j--)
            {
                *(it + j + 1) = *(it + j);
                *(it + j) = key;
            }
        }
}

template <typename T>
void insertion_forward_to_low(std::vector<T>& vec) // by forward iterator
{
        typename std::vector< T >::iterator it = vec.begin();
        for (int i = 1; i < vec.size(); i++)
        {
            T key = *(it + i);
            for (int j = i - 1; j >= 0 && *(it + j) < key; j--)
            {
                *(it + j + 1) = *(it + j);
                *(it + j) = key;
            }
        }
}

template <typename T>
void insertion_by_rec_to_high(std::vector<T>& vec, int n)
{
    if(n <= 1)
    {
        return;
    }

    insertion_by_rec_to_high(vec, n - 1);

    T key = vec[n - 1];
    int j = n - 2;
    while(j >= 0 && vec[j] > key)
     {
         vec[j + 1] = vec[j];
         j = j - 1;
     }
    vec[j + 1] = key;
}

template <typename T>
void insertion_by_rec_to_low(std::vector<T>& vec, int n)
{
    if(n <= 1)
    {
        return;
    }

    insertion_by_rec_to_low(vec, n - 1);

    T key = vec[n - 1];
    int j = n - 2;
    while(j >= 0 && vec[j] < key)
     {
         vec[j + 1] = vec[j];
         j = j - 1;
     }
    vec[j + 1] = key;
}


bool is_digit(const char& ch)
{
    bool check = (ch <= 57 && ch >= 48);
    return check;
}

template <typename T>
void print(std::vector<T>& vec, int& size)
{
    std::cout << "\n\tResult: [" << vec[0];
    for(int i = 1; i < size; ++i)
    {
        std::cout << "," << vec[i];
    }
    std::cout << "]\n\n";
}
