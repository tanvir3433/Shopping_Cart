#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50


typedef struct {
    char name[50];
    float price;
    int quantity;
}Item;

Item cart[MAX_ITEMS];
int cartSize = 0;

void addItem();
void viewCart();
void removeItem();
float getTotal();
void applyDiscount();
void checkout();

int main() {
    int choice;

    while (1) {
        printf("\n===== Shopping Cart Menu =====\n");
        printf("1. Add Item\n");
        printf("2. View Cart\n");
        printf("3. Remove Item\n");
        printf("4. Get Total Price\n");
        printf("5. Apply Discount\n");
        printf("6. Checkout\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1: addItem(); break;
            case 2: viewCart(); break;
            case 3: removeItem(); break;
            case 4: printf("Total: $%.2f\n", getTotal()); break;
            case 5: applyDiscount(); break;
            case 6: checkout(); return 0;
            case 7: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to add an item to the cart
void addItem() {
    if (cartSize >= MAX_ITEMS) {
        printf("Cart is full!\n");
        return;
    }

    printf("Enter item name: ");
    fgets(cart[cartSize].name, 50, stdin);
    cart[cartSize].name[strcspn(cart[cartSize].name, "\n")] = 0;
    printf("Enter price: ");
    scanf("%f", &cart[cartSize].price);

    printf("Enter quantity: ");
    scanf("%d", &cart[cartSize].quantity);


    cartSize++;
    printf("Item added!\n");
}

// Function to view the cart items
void viewCart() {
    if (cartSize == 0) {
        printf("Your cart is empty!\n");
        return;
    }

    printf("\nYour Cart:\n");
    for (int i = 0; i < cartSize; i++) {
        printf("%d. %s - $%.2f x %d\n", i + 1, cart[i].name, cart[i].price, cart[i].quantity);
    }
}

// Function to remove an item from the cart
void removeItem() {
    if (cartSize == 0) {
        printf("Cart is empty!\n");
        return;
    }

    int index;
    viewCart();
    printf("Enter item number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > cartSize) {
        printf("Invalid number!\n");
        return;
    }

    for (int i = index - 1; i < cartSize - 1; i++) {
        cart[i] = cart[i + 1];
    }

    cartSize--;
    printf("Item removed successfully!\n");
}

// Function to calculate total price of itmes
float getTotal() {
    float total = 0;
    for (int i = 0; i < cartSize; i++) {
        total += cart[i].price * cart[i].quantity;
    }
    return total;
}

// Function to apply discount
void applyDiscount() {
    float total = getTotal();
    float discount = 0;

    if (total >= 100) discount = total * (total >= 200 ? 0.20 : 0.10);

    printf("Total: $%.2f\n", total);
    printf("Discount: $%.2f\n", discount);
    printf("Final Total: $%.2f\n", total - discount);
}

// Function to checkout
void checkout() {
    if (cartSize == 0) {
        printf("Cart is empty! Add items first.\n");
        return;
    }

    printf("\n===== Checkout Summary =====\n");
    viewCart();
    applyDiscount();
    printf("\nThanks for shopping!\n");
    cartSize = 0;
}
