#include <iostream>
#include <ctime>

int* RandomTable(int n)
{
    srand(time(NULL));
    bool flag = true;
    int random;
    int *tab = new int[n];

    for(size_t i = 0; i < n; i++)
    {
        random = rand() % n;
        for(size_t j = 0; j < i; j++){
            if(tab[j] == random){
                i--;
                break;
            }
        }
        tab[i] = random; 
    }
    return tab;
}

void PrintArray(int tab[], int length)
{
    std::cout << "Printing an array: " << std::endl;
    for(size_t k=0; k<length; k++)
        {
            std::cout << tab[k] << " ";
        }
    std::cout << "\n";
}

int SequentialSearch(int tab[], int length, int num_to_find, int &counter){
    for(size_t i = 0; i < length; i++){
        if(tab[i] == num_to_find){
            std::cout << "Znaleziono poszukiwaną liczbę " << num_to_find << "!. Jest ona na indeksie numer " << i << std::endl;
            counter++;
            std::cout << "Potrzeba było " << counter << " porównań aby znaleźć tę liczbę.\n"; 
            return i;
        }
        else{
            counter++;
        }
    }
    std::cout << "Nie znaleziono tej liczby.\n";
    return -1;
}

int main(){
    int counter {};
    std::cout << "Podaj rozmiar tablicy: ";
    int length;
    std::cin >> length;
    int *new_tab = RandomTable(length);
    PrintArray(new_tab, length);
    std::cout << "Podaj szukaną liczbę: ";
    int num_to_find;
    std::cin >> num_to_find;
    SequentialSearch(new_tab, length, num_to_find, counter);

    delete [] new_tab;
}