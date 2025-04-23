#include <stdio.h>
#include <stdlib.h>

void insert_arr(int a[], int n);
void update_arr(int a[], int n);
int delete_arr(int a[], int n);
void sort_arr(int a[], int n);
void search_arr(int a[], int n);
void display_arr(int a[], int n);
void show_menu();

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of elements (1 to 100 only).\n");
        return 1;
    }

    int a[100];  // Fixed size for simplicity
    insert_arr(a, n);

    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                update_arr(a, n);
                break;
            case 2:
                n = delete_arr(a, n);
                break;
            case 3:
                sort_arr(a, n);
                break;
            case 4:
                search_arr(a, n);
                break;
            case 5:
                display_arr(a, n);
                break;
            case 6:
                printf("\nAnwar Hossaim\nID:200\n");
                exit(0);
            default:
                printf("Invalid option! Please select between 1 to 6.\n");
        }
    }

    return 0;
}

void insert_arr(int a[], int n) {
    printf("Please enter your values:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Values inserted successfully.\n");
}

void update_arr(int a[], int n) {
    int index, value;
    printf("Enter index to update (0 to %d): ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        printf("Enter new value: ");
        scanf("%d", &value);
        a[index] = value;
        printf("Value updated at index %d.\n", index);
    } else {
        printf("Invalid index!\n");
    }
}

int delete_arr(int a[], int n) {
    int index;
    if (n == 0) {
        printf("Array is already empty!\n");
        return n;
    }
    printf("Enter index to delete (0 to %d): ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        printf("Element deleted from index %d.\n", index);
        return n - 1;
    } else {
        printf("Invalid index!\n");
        return n;
    }
}

void sort_arr(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

void search_arr(int a[], int n) {
    int value, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            printf("Value found at index %d.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value not found in the array.\n");
    }
}

void display_arr(int a[], int n) {
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void show_menu() {
    printf("\nChoose an option:\n");
    printf(" 1. Update\n");
    printf(" 2. Delete\n");
    printf(" 3. Sort\n");
    printf(" 4. Search\n");
    printf(" 5. Display\n");
    printf(" 6. Exit\n");
    printf("Enter your choice: ");
}
