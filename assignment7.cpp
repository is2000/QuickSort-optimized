#include <iostream>
#include <vector>
#include <algorithm>

// Iusing iterators to make an inline function for partitioning
inline auto part(std::vector<int>::iterator l, std::vector<int>::iterator h) {
    auto piv = *h;
    auto i = l - 1;

    for (auto j = l; j < h; j++) {
        if (*j < piv) {
            i++;
            std::iter_swap(i, j);
        }
    }
    std::iter_swap(i + 1, h);
    return i + 1;
}

// now using interators for quick sort
void quickSort(std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (low < high) {
        auto p = part(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr.begin(), arr.end() - 1);
    std::cout << "Sorted array: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}
