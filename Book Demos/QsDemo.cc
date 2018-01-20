#include <cstring>
#include <iostream>

void qs(char* items, int left, int right) {
  int i, j;
  char x, y;

  i = left;
  j = right;
  // Partition: Middle item in array (rounded down)
  x = items[(left + right) / 2];

  while (i < j) {
    // increment i as long as we haven't reached the end of the array and the
    // items[i] is smaller than the partition
    while ((items[i] < x) && (i < right)) i++;
    // decrement j as long as we haven't reached the start of the array and the
    // items[j] is greater than the partition
    while ((x < items[j]) && (j > left)) j--;

    if (i <= j) {
      // Swap items[i] and items[j]
      y = items[i];
      items[i] = items[j];
      items[j] = y;

      // Increment/decrement both
      i++;
      j--;
    }
  }

  // If j is stil greater than left, sort the the items in between
  if (left < j) qs(items, left, j);
  // If i is stil less than right, sort the the items in between
  if (right > i) qs(items, i, right);
}

void QuickSort(char* items, int len) { qs(items, 0, len - 1); }

int main() {
  char str[] = "This is text";
  std::cout << "start:" << str << std::endl;
  QuickSort(str, std::strlen(str));
  std::cout << "end  :" << str << std::endl;
}