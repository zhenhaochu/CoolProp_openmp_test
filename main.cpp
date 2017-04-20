#include "CoolProp.h"
#include "AbstractState.h"

#include <stdio.h>
#include <memory>
#include <chrono>

#include "omp.h"

using namespace CoolProp;
void do_one(int N){
    
    std::vector<double> rho(N,0);
    std::cout << "N:" << N << std::endl;
    
    // One instance of an AbstractState instance for each thread
    std::vector<std::shared_ptr<AbstractState> > ASvec;
    // Note that the number of instances here must be larger than the number of threads you plan to
    // use or you will get a segfault because you are accessing outside the range of valid
    // indices. Make it conservatively large
    for(int i = 0; i < 20; ++i){ 
        ASvec.push_back(std::shared_ptr<AbstractState>(AbstractState::factory("HEOS","CO2"))); 
    }
    
    {   
        auto startTime = std::chrono::system_clock::now();
        #pragma omp parallel for
        for(int i = 0; i < N; i++){
            std::size_t tid = omp_get_thread_num();
            std::shared_ptr<AbstractState> &AS = ASvec[tid];
            AS->update(PT_INPUTS, 101325+i, 300);
            rho[i] = AS->rhomolar();

            // Uncomment this block to see what thread id you have
            // --
            // #pragma omp critical
            // std::cout << "tid: " << omp_get_thread_num() << std::endl;
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
    do_one(10);
    do_one(100);
    do_one(1000);
    do_one(10000);
    do_one(100000);
    do_one(1000000);
}
