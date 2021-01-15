#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include "thread.h"

using namespace std;


long SoloThread() {
    stringstream ss;
    long sum = 0;
    for (int i = 1; i <= 10; i++) {
        ss << "..\\Files\\" << i << ".txt";
        ifstream fout(ss.str());
        ss.str(string());
        long num;
        fout >> num;
        sum += num;
        while (!fout.eof()) {
            fout >> num;
            sum += num;
        }
        fout.close();
    }
    return sum;
}
void* GetSum(void *Types_one) {
    int num=0;
    stringstream ss;
    ifstream input;
    Types *data = (Types*) Types_one;

    ss << "..\\Files\\" << data->file << ".txt";
    input.open(ss.str());
    ss.str(string());
    input >> num;
    data->sum = data->sum + num;
    while (!input.eof()) {
        input >> num;
        data->sum = data->sum + num;
    }
    input.close();
    return nullptr;
}


long MultiThread() {
    long Sum = 0;
    pthread_t threads[10];
    Types* data = new Types[10];

    for (int i = 1; i <= 10; i++) {
        data[i].file = i;
        data[i].sum = 0;
        pthread_create(&(threads[i]), nullptr, GetSum, &data[i]);
    }
    for (int i = 1; i <= 10; i++) {
        pthread_join (threads[i], nullptr);
        Sum += data[i].sum;
    }
    delete[] data;
    return Sum;
}