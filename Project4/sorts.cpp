#include <vector>
#include <string>
#include <sys/time.h>
#include <iostream>
#include "sorts.h"
using namespace std;

void export_times();

//Global functions
void InitVector(vector<int>& item_vetor, int size);
void PrintVector(const vector<int>& item_vector, string name);
int Elapsed(const timeval &start, const timeval &end);

int main(int argc, char* argv[]) {
    sorts sort;
    
    int size = 0;
    string sort_name = "";
    bool print_out = false;

    if ((argc != 3) && (argc != 4)) {
        if(argc == 1) {
            export_times();
            return 0;
        }
        cerr << "Usage: Sorter algorithm size [Print]" << endl;
        return -1;
    }

    sort_name = string(argv[1]);
    size = atoi(argv[2]);

    if (size <= 0) {
        cerr << "Vector size must be positive" << endl;
        return -1;
    }

    if (argc == 4) {
        string print_arr = string(argv[3]);

        if (print_arr == "Print") {
            print_out = true;

        } else {
            cerr << "Usage: Sorter algorithm size [Print]" << endl;
            return -1;

        }

    }

    srand(1);
    vector<int> items(size);
    InitVector(items, size);


    if(print_out) {
        cout << "Initial:" << endl;
        PrintVector(items, string("items"));
        cout << endl;
    }

    //get time to measure the time it takes to sort
    struct timeval start_time, end_time;
    gettimeofday(&start_time, 0);

    if (sort_name == "QuickSort") {
        sort.QuickSort(items, 0, size - 1);
    }

    if (sort_name == "BubbleSort") {
        sort.BubbleSort(items, size);
    }

    if (sort_name == "InsertionSort") {
        sort.InsertionSort(items, size);
    }

    if (sort_name == "MergeSort") {
        sort.MergeSort(items, 0, size - 1);
    }

    if (sort_name == "IterativeMergeSort") {
        sort.IterativeMergeSort(items, size);
    }

    if (sort_name == "ShellSort") {
        sort.ShellSort(items, size);
    }

    gettimeofday(&end_time, 0);

    if (print_out) {
        cout << "Sorted:" << endl;
        PrintVector(items, string("item"));
    }

    cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
    return 0;
}

void InitVector(vector<int>& item_vector, int rand_max) {
    if (rand_max < 0) {
        return;
    }

    vector<int> pool(rand_max);
    for (int i = 0; i < rand_max; i++) {
        pool[i] = i;
    }

    int spot;
    for (int i = 0; i < rand_max; i++) {
        spot = rand() % (pool.size());
        item_vector[i] = pool[spot];
        pool.erase(pool.begin() + spot);

    }

}

void PrintVector(const vector<int>& item_vector, string name) {
    int size = item_vector.size();

    for (int i = 0; i < size; i++) {
        cout << item_vector[i] << " ";

    }
    cout << endl;
}

// Function to calculate elapsed time
// Microseconds
int Elapsed(const timeval &start, const timeval &end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

}

void export_times() {
    sorts sort;
    struct timeval start_time, end_time;

    vector<string> daList = {"BubbleSort", "InsertionSort", "MergeSort", "IterativeMergeSort", "QuickSort", "ShellSort"};
    
    // cout << "something!!!!!!";

    for (string sort_name : daList) {

        cout << sort_name + ": ";

        for (int i = 2; i < 100000; i*=2) {

            int size = i;

            srand(1);
            vector<int> items(size);
            InitVector(items, size);

            gettimeofday(&start_time, 0);
            if (sort_name == "QuickSort") {
                sort.QuickSort(items, 0, size - 1);
            }

            if (sort_name == "BubbleSort") {
                sort.BubbleSort(items, size);
            }

            if (sort_name == "InsertionSort") {
                sort.InsertionSort(items, size);
            }

            if (sort_name == "MergeSort") {
                sort.MergeSort(items, 0, size - 1);
            }

            if (sort_name == "IterativeMergeSort") {
                sort.IterativeMergeSort(items, size);
            }

            if (sort_name == "ShellSort") {
                sort.ShellSort(items, size);
            }
            gettimeofday(&end_time, 0);
            int timeElapsed = Elapsed(start_time, end_time);


            cout << std::to_string(timeElapsed) + " ";


        }

        cout << "\n";
        
    }

}