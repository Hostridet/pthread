#include <iostream>
#include <ctime>
#include "thread.h"


using namespace std;

int main() {
    clock_t start, end;
    start = clock();
    cout << "Сумма высчитанная в одном потоке: " << SoloThread() << endl;
    end = clock();
    cout << "Один поток посчитал сумму чисел во всех файлах за: " << (end - start) / 1000.0 << endl;
    start = clock();
    cout << "Сумма высчитанная в 10 потоках: " << MultiThread() << endl;
    end = clock();
    cout << "10 потоков посчитали сумму чисел во всех файлах за: " << (end - start) / 1000.0 << endl;
    return 0;
}
