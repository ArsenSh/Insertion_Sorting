#include <iostream>
#include <vector>

void initializing_program();
void choosing_operation(std::vector<int>&, std::size_t&, int);
void insertion_h(std::vector<int>&, std::size_t&);
void insertion_l(std::vector<int>&, std::size_t&);
void insertion_rec_h(std::vector<int>&, std::size_t);
void insertion_rec_l(std::vector<int>&, std::size_t);
void print(std::vector<int>&, std::size_t&);

int main()
{
    initializing_program();
    return 0;
}

void initializing_program()
{
    std::vector<int> vec;
    std::size_t size = 0;
    std::cout << "Enter the amount of elements: ";
    std::cin >> size;
    int elem{};
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
    std::cout << "\t[1] Iterative from little to high\n" << "\t[2] Iterative from high to little\n" << "\t[3] Recursive from little to high\n" << "\t[4] Recursive from high to little\n" << "\t[5] EXIT\n" << std::endl;
    std::cout << "=================================Your choice: ";
    int index = 0;
    std::cin >> index;
    choosing_operation(vec, size, index);
}

void choosing_operation(std::vector<int>& vec, std::size_t& size, int index)
{
    switch(index)
    {
        case 1:
            insertion_h(vec, size);
            print(vec, size);
            break;
        case 2:
            insertion_l(vec, size);
            print(vec, size);
            break;
        case 3:
            insertion_rec_h(vec, size);
            print(vec, size);
            break;
        case 4:
            insertion_rec_l(vec, size);
            print(vec, size);
            break;
        case 5:
            exit(0);
        default:
            std::cout << "Wrong index, try again: ";
            int ind = 0;
            std::cin >> ind;
            choosing_operation(vec, size, ind);
    }
}

void insertion_h(std::vector<int>& vec, std::size_t& n)
{
         for(int i = 1; i < n; ++i)
         {
            int key = vec[i];
            int j = i - 1;
             
            while(j >= 0 && vec[j] > key)
             {
                 vec[j + 1] = vec[j];
                 j = j - 1;
             }
             
            vec[j + 1] = key;
         }
}

void insertion_l(std::vector<int>& vec, std::size_t& n)
{
         for(int i = 1; i < n; ++i)
         {
            int key = vec[i];
            int j = i - 1;
             
            while(j >= 0 && vec[j] < key)
             {
                 vec[j + 1] = vec[j];
                 j = j - 1;
             }
             
            vec[j + 1] = key;
         }
}

void insertion_rec_h(std::vector<int>& vec, std::size_t n)
{
    if(n <= 1)
    {
        return;
    }
    
    insertion_rec_h(vec, n - 1);
    
    int key = vec[n - 1];
    int j = static_cast<int>(n - 2);
    while(j >= 0 && vec[j] > key)
     {
         vec[j + 1] = vec[j];
         j = j - 1;
     }
    vec[j + 1] = key;
}

void insertion_rec_l(std::vector<int>& vec, std::size_t n)
{
    if(n <= 1)
    {
        return;
    }
    
    insertion_rec_l(vec, n - 1);
    
    int key = vec[n - 1];
    int j = static_cast<int>(n - 2);
    while(j >= 0 && vec[j] < key)
     {
         vec[j + 1] = vec[j];
         j = j - 1;
     }
    vec[j + 1] = key;
}

void print(std::vector<int>& vec, std::size_t& size)
{
    std::cout << "\n\tResult: [" << vec[0];
    for(int i = 1; i < size; ++i)
    {
        std::cout << "," << vec[i];
    }
    std::cout << "]\n\n";
}
