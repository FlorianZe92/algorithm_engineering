#include <iostream>
#include <omp.h>
#include <random>

using namespace std;

int main() {
  int n = 1000000000; // amount of points to generate
  int sum = 0; // counter for points in the first quarter of a unit circle
  auto start_time = omp_get_wtime(); // omp_get_wtime() is an OpenMP library routine
  omp_set_num_threads(4); // setting the desired number of threads in the parallel region

#pragma omp parallel // parallel region starts here
  { // idea for parallelisation: split up loop iterations between threads
    int num_threads = omp_get_num_threads(); // used as increment in for loop
    int thread_id = omp_get_thread_num();
    int seed = thread_id;
    int counter = 0;
    default_random_engine re{seed};
    uniform_real_distribution<double> zero_to_one{0.0, 1.0};

    for (int i = thread_id; i < n; i += num_threads) {
        auto x = zero_to_one(re); // generate random number between 0.0 and 1.0
        auto y = zero_to_one(re); // generate random number between 0.0 and 1.0
        if (x * x + y * y <= 1.0) { // if the point lies in the first quadrant of a unit circle
          ++counter;
        }
    }
#pragma omp atomic // only one thread performs the update of the sum
    sum += counter;
  } // parallel region ends here

  auto run_time = omp_get_wtime() - start_time;
  auto pi = 4 * (double(sum) / n);

  cout << "pi: " << pi << endl;
  cout << "run_time: " << run_time << " s" << endl;
  cout << "n: " << n << endl; }
