#include <stdio.h>
#include <string.h>

int main() {
    // Arrays to store product names and prices
    char *productNames[] = {"Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"};
    float productPrices[] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    int numProducts = sizeof(productPrices) / sizeof(productPrices[0]);

    // --- Display before sorting ---
    printf("\n🛒 Products BEFORE sorting:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
    }

    // --- Bubble Sort for prices ---
    for (int i = 0; i < numProducts - 1; i++) {
        for (int j = 0; j < numProducts - 1 - i; j++) {
            if (productPrices[j] > productPrices[j + 1]) {
                // Swap prices
                float tempPrice = productPrices[j];
                productPrices[j] = productPrices[j + 1];
                productPrices[j + 1] = tempPrice;

                // Swap corresponding product names
                char *tempName = productNames[j];
                productNames[j] = productNames[j + 1];
                productNames[j + 1] = tempName;
            }
        }
    }

    // --- Insertion Sort for product names ---
    for (int i = 1; i < numProducts; i++) {
        char *keyName = productNames[i];
        float keyPrice = productPrices[i];
        int j = i - 1;

        // Move elements of productNames[0..i-1] that are greater than keyName
        while (j >= 0 && strcmp(productNames[j], keyName) > 0) {
            productNames[j + 1] = productNames[j];
            productPrices[j + 1] = productPrices[j];
            j = j - 1;
        }
        productNames[j + 1] = keyName;
        productPrices[j + 1] = keyPrice;
    }

    // --- Display after sorting ---
    printf("\n✅ Products AFTER sorting by price and name:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
    }

    return 0;
}