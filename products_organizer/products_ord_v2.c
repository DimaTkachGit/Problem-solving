#include <stdio.h>

int main() {
    // Arrays to store product names and prices
    char *productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    float productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};

    int numProducts = sizeof(productPrices) / sizeof(productPrices[0]);

    // --- Display adjacent products ---
    printf("\n📋 Displaying adjacent products:\n");
    for (int i = 0; i < numProducts - 1; i++) {
        printf("-----------------------------------------------\n");
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
        printf("Adjacent Product: %-14s | Price: $%.2f\n", productNames[i + 1], productPrices[i + 1]);
    }
    printf("-----------------------------------------------\n");

    // --- Display before sorting ---
    printf("\n🛒 Products BEFORE single Bubble Sort pass:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
    }
    //[1,2,1,2,4,3,]
    // --- One pass of Bubble Sort to move highest price to the end ---
    for (int i = 0; i < numProducts - 1; i++) {
        if (productPrices[i] > productPrices[i + 1]) {
            // Swap prices
            float tempPrice = productPrices[i];
            productPrices[i] = productPrices[i + 1];
            productPrices[i + 1] = tempPrice;

            // Swap corresponding names
            char *tempName = productNames[i];
            productNames[i] = productNames[i + 1];
            productNames[i + 1] = tempName;
        }
    }

    // --- Display after sorting ---
    printf("\n✅ Products AFTER single Bubble Sort pass:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
    }

    return 0;
}