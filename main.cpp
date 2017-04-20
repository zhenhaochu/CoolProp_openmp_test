#include "CoolProp.h"
#include "AbstractState.h"

#include <stdio.h>
#include <memory>
#include <chrono>

#include "omp.h"

using namespace CoolProp;
void do_one(int N){
    
    // This many threads are in the pool
    int Nthread = 8;

    std::vector<double> rho(N,0);
    std::cout << "N:" << N << std::endl;
    
    // One instance of an AbstractState instance for each thread
    std::vector<std::shared_ptr<AbstractState> > ASvec;
    for(int i = 0; i < N; ++i){ ASvec.push_back(std::shared_ptr<AbstractState>(AbstractState::factory("HEOS","CO2"))); }
    
    {   
        auto startTime = std::chrono::system_clock::now();
        #pragma omp parallel for
        for(int i = 0; i < N; i++){

            // int j = i%omp_get_num_threads(); // You could also try to use a smaller set of AbstractState instances, but that requires synchronization to ensure two threads don't write to the same abstractstate, or other intelligent means
            std::shared_ptr<AbstractState> &AS = ASvec[i];
            AS->update(PT_INPUTS, 101325+i, 300);
            rho[i] = AS->rhomolar();
            // #pragma omp critical
            // std::cout << j << " " << rho[i] << std::endl;
        }
        auto endTime = std::chrono::system_clock::now();
        std::cout << "With OpenMP: " << std::chrono::duration<double>(endTime - startTime).count() << std::endl;
    }
    
    {
        auto startTime = std::chrono::system_clock::now();
        for(int i = 0; i < N; i++){
            std::shared_ptr<AbstractState> &AS = ASvec[i%4];
            AS->update(PT_INPUTS, 101325+i, 300);
            rho[i] = AS->rhomolar();
        }
        auto endTime = std::chrono::system_clock::now();
        std::cout << "Without OpenMP: " << std::chrono::duration<double>(endTime - startTime).count() << std::endl;
    }
    std::cout << "\n";
}
int main(int argc, char *argv[])
{
    do_one(4);
    do_one(100);
    do_one(1000);
    do_one(10000);
    do_one(100000);
}
