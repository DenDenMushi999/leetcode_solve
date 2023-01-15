// #include <sort>
#include <iostream>

template <class T>
void print_array(T* arr, int n){
    for ( int* end = arr+n; arr!=end; ++arr)
        std::cout<<*arr << " ";
    std::cout << "\n";
}

struct InputTask{
    const int n;
    const int coins;
    int costs[];

    // Use rule of 3?
    InputTask(int n, int coins, int* costs): n(n), coins(coins){
        for (int i=0; i<n; ++i)
            this->costs[i] = costs[i];
    }
};


const int count_max_icecreams(InputTask& input){
    int n_icecreams = 0;
    // std::sort(costs);

    int coins = input.coins;
    for(int i=0; i<input.n; ++i){
        if (coins >= input.costs[i]){
            ++n_icecreams;
            coins -= input.costs[i];
        }
        else
            break;
    }
    return n_icecreams;
}

int main() {

    int costs2[] = {6,7,7,8,8,10};
    InputTask case2 = InputTask(6, 5, costs2);
    int costs1[] = {1,1,2,3,4};
    InputTask case1 = InputTask(5, 7, costs1);
    int costs3[] = {1,1,2,3,5,6};
    InputTask case3 = InputTask(6, 30, costs3);

    for (int i=0; i < 17; ++i)
        std::cout << case2.costs[i]<< " ";
    print_array<int>(case1.costs, case1.n);
    print_array<int>(case2.costs, case2.n);
    print_array<int>(case3.costs, case3.n);
    print_array<int>(costs1, 5);
    // std::cin >> n;
    // for (int i=0; i<n; ++i)
    //     std::cin >> costs[i];
    // std::cin >> coins;

    std::cout << count_max_icecreams(case1) << "\n";
    std::cout << count_max_icecreams(case2) << "\n";
    std::cout << count_max_icecreams(case3) << "\n";

    return 0;
}