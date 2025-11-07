#include <stdio.h>

int main() {
    int n, search, first, last, middle;
    
    printf("Enter number of products in store: ");
    scanf("%d", &n);
    
    int productIDs[n];
    printf("Enter %d Product IDs in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &productIDs[i]);
    }

    printf("Enter Product ID to search: ");
    scanf("%d", &search);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (productIDs[middle] == search) {
            printf("Product ID %d found at position %d in inventory.\n", search, middle + 1);
            return 0;
        } 
        else if (productIDs[middle] < search)
            first = middle + 1;
        else
            last = middle - 1;
        
        middle = (first + last) / 2;
    }

    printf("Product ID %d not found in inventory.\n", search);
    return 0;
}
