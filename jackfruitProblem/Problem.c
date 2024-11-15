#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define ALPHABET_SIZE 26

// User Management Structures
typedef struct User
{
    char username[50];
    char email[50];
} User;

typedef struct UserHashTable
{
    User *table[TABLE_SIZE];
} UserHashTable;

// Hash function for users
unsigned int userHash(char *str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

void addUser(UserHashTable *ht, User *user)
{
    unsigned int index = userHash(user->username);
    ht->table[index] = user;
}

User *getUser(UserHashTable *ht, char *username)
{
    unsigned int index = userHash(username);
    return ht->table[index];
}

// Product Management Structures
typedef struct Product
{
    char productId[50];
    char name[50];
    char category[50];
    int inventory;
} Product;

typedef struct ProductHashTable
{
    Product *table[TABLE_SIZE];
} ProductHashTable;

// Hash function for products
unsigned int productHash(char *str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

void addProduct(ProductHashTable *ht, Product *product)
{
    unsigned int index = productHash(product->productId);
    ht->table[index] = product;
}

Product *getProduct(ProductHashTable *ht, char *productId)
{
    unsigned int index = productHash(productId);
    return ht->table[index];
}

// Browsing and Purchase History (Trie)
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode *createTrieNode()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

void insertTrie(TrieNode *root, const char *key)
{
    TrieNode *node = root;
    while (*key)
    {
        int index = *key - 'a';
        if (!node->children[index])
        {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
        key++;
    }
    node->isEndOfWord = 1;
}

int searchTrie(TrieNode *root, const char *key)
{
    TrieNode *node = root;
    while (*key)
    {
        int index = *key - 'a';
        if (!node->children[index])
        {
            return 0;
        }
        node = node->children[index];
        key++;
    }
    return node != NULL && node->isEndOfWord;
}

// Purchase History Tracking
typedef struct Purchase
{
    char username[50];
    char productId[50];
} Purchase;

typedef struct PurchaseNode
{
    Purchase purchase;
    struct PurchaseNode *next;
} PurchaseNode;

typedef struct PurchaseHistory
{
    PurchaseNode *head;
} PurchaseHistory;

void addPurchase(PurchaseHistory *history, Purchase *purchase)
{
    PurchaseNode *newNode = (PurchaseNode *)malloc(sizeof(PurchaseNode));
    newNode->purchase = *purchase;
    newNode->next = history->head;
    history->head = newNode;
}

void printPurchaseHistory(PurchaseHistory *history)
{
    PurchaseNode *current = history->head;
    while (current != NULL)
    {
        printf("User: %s, Product: %s\n", current->purchase.username, current->purchase.productId);
        current = current->next;
    }
}

// Main Function to Demonstrate Usage
int main()
{
    UserHashTable userTable;
    memset(&userTable, 0, sizeof(userTable));

    ProductHashTable productTable;
    memset(&productTable, 0, sizeof(productTable));

    TrieNode *root = createTrieNode();

    PurchaseHistory purchaseHistory;
    purchaseHistory.head = NULL;

    char command[50];
    while (1)
    {
        printf("Enter command (add_user, add_product, browse, purchase, history, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add_user") == 0)
        {
            User user;
            printf("Enter username: ");
            scanf("%s", user.username);
            printf("Enter email: ");
            scanf("%s", user.email);
            addUser(&userTable, &user);
            printf("User added successfully.\n");
        }
        else if (strcmp(command, "add_product") == 0)
        {
            Product product;
            printf("Enter product ID: ");
            scanf("%s", product.productId);
            printf("Enter product name: ");
            scanf("%s", product.name);
            printf("Enter product category: ");
            scanf("%s", product.category);
            printf("Enter product inventory: ");
            scanf("%d", &product.inventory);
            addProduct(&productTable, &product);
            printf("Product added successfully.\n");
        }
        else if (strcmp(command, "browse") == 0)
        {
            char product[50];
            printf("Enter product name to browse: ");
            scanf("%s", product);
            insertTrie(root, product);
            printf("Browsing history recorded.\n");
        }
        else if (strcmp(command, "purchase") == 0)
        {
            Purchase purchase;
            printf("Enter username: ");
            scanf("%s", purchase.username);
            printf("Enter product ID: ");
            scanf("%s", purchase.productId);
            addPurchase(&purchaseHistory, &purchase);
            printf("Purchase recorded.\n");
        }
        else if (strcmp(command, "history") == 0)
        {
            printPurchaseHistory(&purchaseHistory);
        }
        else if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}