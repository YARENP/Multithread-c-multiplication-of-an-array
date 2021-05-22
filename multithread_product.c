#include <stdio.h> 
#include <pthread.h> 
  
#define MAX 16 
  
// maximum number of threads 
#define MAX_THREAD 8 
   
  
int a[] = { 1, 5, 7, 10,12,14, 15, 18, 20, 22, 25,27, 30, 64, 110, 220 }; 
double product[8] = { 1,1,1,1,1,1,1,1 }; 
int part = 0; 
  
void* product_array(void* arg) 
{ 
  
    // Each thread computes sum of 1/4th of array 
    int thread_part = part++; 
  
    for (int i = thread_part * (MAX / 8); i < (thread_part + 1) * (MAX / 8); i++) 
        product[thread_part] *= a[i]; 
} 
  
// Driver Code 
int main() 
{ 
  
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 4 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, product_array, (void*)NULL); 
  
    // joining 4 threads i.e. waiting for all 4 threads to complete 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all 4 parts 
  double total_product = 1; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total_product *= product[i]; 
  
    printf("total product is %.f", total_product); 
  
    return 0; 
} 
