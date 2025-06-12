#include <stdio.h>

int main() {
    // Arrays to store product names and their corresponding prices
    char *productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    float productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    
    int numProducts = sizeof(productPrices) / sizeof(productPrices[0]);

    // Loop through products to display each and its adjacent product
    for (int i = 0; i < numProducts - 1; i++) {
        printf("-----------------------------------------------\n");
        printf("Product: %-14s          | Price: $%.2f\n", productNames[i], productPrices[i]);
        printf("Adjacent Product: %-14s | Price: $%.2f\n", productNames[i + 1], productPrices[i + 1]);

    }

    return 0;
}
