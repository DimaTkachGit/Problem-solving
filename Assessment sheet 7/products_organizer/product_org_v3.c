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

    // --- Display before full sort ---
    printf("\n🛒 Products BEFORE full Bubble Sort:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
    }

    // --- Full Bubble Sort for prices ---
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

    // --- Display after full sort ---
    printf("\n✅ Products AFTER full Bubble Sort (by ascending price):\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Product: %-14s | Price: $%.2f\n", productNames[i], productPrices[i]);
    }

    return 0;
}
