

inline void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

inline void quicksort(int *begin, int *end) {
    int *ptr;
    int *split;
    if (end - begin <= 1)
        return;
    ptr = begin;
    split = begin + 1;
    while (++ptr != end) {
        if (*ptr < *begin) {
            swap(ptr, split);
            ++split;
        }
    }
    swap(begin, split - 1);
    quicksort(begin, split - 1);
    quicksort(split, end);
}

/*
void sampleQuickSort()
{
  const int NUMBERS = 9;
  int* a = new int[NUMBERS];
  int* b = a;
  
  for (int i = 0; i < NUMBERS; i++)
  {
    *b++ = rand() - 1000;
  }

  b = a + NUMBERS;
  quicksort(a,b);

  b = a;
  for (int i = 0; i < NUMBERS; i++)
  {
    cout << *b++ << " ";
  }
  delete[] a; 
}
*/