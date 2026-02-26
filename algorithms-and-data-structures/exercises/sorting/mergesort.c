#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

void print(int* v);
void load(int* v);
void merge(int a[], int p, int q, int r);
void mergeSort(int a[], int p, int r);

int main(){
  int v[MAX];
  load(v);
  printf("\nArray given in input:\n");
  print(v);
  mergeSort(v,0,MAX-1);
  printf("Result:\n");
  print(v);
}

// Computational cost: Theta(n * log_2(n))
void mergeSort(int a[], int p, int r) {
  int q;
  if (p < r) {
    q = (p+r)/2;
    mergeSort(a, p, q);
    mergeSort(a, q+1, r);
    merge(a, p, q, r);
  }
  return;
}

// Computational cost: Theta(n)
void merge(int a[], int p, int q, int r) {
  int i, j, k=0, b[MAX];
  i = p;
  j = q+1;

  while (i<=q && j<=r) {

    if (a[i]<a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }

    k++;
  }

  while (i <= q) {
    b[k] = a[i];
    i++;
    k++;
  }

  while (j <= r) {
    b[k] = a[j];
    j++;
    k++;
  }

  for (k=p; k<=r; k++){
    a[k] = b[k-p];
  }
  
  return;
}

void print(int* v){
  int i;
  for(i=0;i<MAX;i++){
    printf("%d|",v[i]);
  }
  printf("\n\n");
}

void load(int* v){
  int i;
  srand(time(NULL));
  for(i=0;i<MAX;i++){
    v[i] = rand()%10;
  }
}


