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

// Add a user to the hash table
void addUser(UserHashTable *ht, User *user)
{
    unsigned int index = userHash(user->username);
    ht->table[index] = user;
}

// Retrieve a user from the hash table
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
} Product;

typedef struct ProductHashTable
{
    Product *table[TABLE_SIZE];
} ProductHashTable;

// Hash function for products
int productHash(char *str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Add a product to the hash table
void addProduct(ProductHashTable *ht, Product *product)
{
    unsigned int index = productHash(product->productId);
    ht->table[index] = product;
}

// Retrieve a product from the hash table
Product *getProduct(ProductHashTable *ht, char *productId)
{
    unsigned int index = productHash(productId);
    return ht->table[index];
}

// Trie Node for Browsing and Purchase History
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

// Create a new Trie node
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

// Insert a key into the Trie
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

// Search for a key in the Trie
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

// Graph Node for Recommendation Engine
typedef struct GraphNode
{
    char productId[50];
    struct GraphNode *next;
} GraphNode;

// Graph structure
typedef struct Graph
{
    int numVertices;
    GraphNode **adjLists;
} Graph;

// Create a new graph
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(GraphNode *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph *graph, int src, int dest, char *productId)
{
    GraphNode *newNode = malloc(sizeof(GraphNode));
    strcpy(newNode->productId, productId);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Heap Node for top-N recommendations
typedef struct HeapNode
{
    char productId[50];
    int score;
} HeapNode;

// MinHeap structure
typedef struct MinHeap
{
    int size;
    int capacity;
    HeapNode *array;
} MinHeap;

// Create a new MinHeap
MinHeap *createMinHeap(int capacity)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (HeapNode *)malloc(capacity * sizeof(HeapNode));
    return minHeap;
}

// Swap two heap nodes
void swapHeapNode(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify the MinHeap
void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].score < minHeap->array[smallest].score)
    {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right].score < minHeap->array[smallest].score)
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Insert a node into the MinHeap
void insertMinHeap(MinHeap *minHeap, HeapNode node)
{
    if (minHeap->size == minHeap->capacity)
    {
        if (node.score > minHeap->array[0].score)
        {
            minHeap->array[0] = node;
            minHeapify(minHeap, 0);
        }
    }
    else
    {
        minHeap->size++;
        int i = minHeap->size - 1;
        minHeap->array[i] = node;

        while (i && minHeap->array[i].score < minHeap->array[(i - 1) / 2].score)
        {
            swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
}

// Main function to demonstrate usage
int main()
{
    UserHashTable userTable;
    memset(&userTable, 0, sizeof(userTable));

    ProductHashTable productTable;
    memset(&productTable, 0, sizeof(productTable));

    TrieNode *root = createTrieNode();

    Graph *graph = createGraph(100);

    MinHeap *minHeap = createMinHeap(10);

    char command[50];
    while (1)
    {
        printf("Enter command (add_user, add_product, browse, recommend, exit): ");
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
        else if (strcmp(command, "recommend") == 0)
        {
            char product[50];
            printf("Enter product name to recommend: ");
            scanf("%s", product);
            if (searchTrie(root, product))
            {
                printf("Browsing history found for %s.\n", product);
            }
            else
            {
                printf("Browsing history not found for %s.\n", product);
            }
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
// Purchase History Tracker
typedef struct PurchaseHistory
{
    char username[50];
    char productId[50];
    struct PurchaseHistory *next;
} PurchaseHistory;

PurchaseHistory *purchaseHistoryHead = NULL;

// Add purchase history
void addPurchaseHistory(char *username, char *productId)
{
    PurchaseHistory *newHistory = (PurchaseHistory *)malloc(sizeof(PurchaseHistory));
    strcpy(newHistory->username, username);
    strcpy(newHistory->productId, productId);
    newHistory->next = purchaseHistoryHead;
    purchaseHistoryHead = newHistory;
}

// Display purchase history for a user
void displayPurchaseHistory(char *username)
{
    PurchaseHistory *current = purchaseHistoryHead;
    printf("Purchase history for %s:\n", username);
    while (current)
    {
        if (strcmp(current->username, username) == 0)
        {
            printf("Product ID: %s\n", current->productId);
        }
        current = current->next;
    }
}

// Product Management: Manage product categories and inventory
typedef struct ProductCategory
{
    char categoryId[50];
    char categoryName[50];
} ProductCategory;

typedef struct ProductInventory
{
    char productId[50];
    int quantity;
} ProductInventory;

ProductCategory productCategories[TABLE_SIZE];
ProductInventory productInventory[TABLE_SIZE];

// Add a product category
void addProductCategory(char *categoryId, char *categoryName)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (strlen(productCategories[i].categoryId) == 0)
        {
            strcpy(productCategories[i].categoryId, categoryId);
            strcpy(productCategories[i].categoryName, categoryName);
            break;
        }
    }
}

// Add product inventory
void addProductInventory(char *productId, int quantity)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (strlen(productInventory[i].productId) == 0)
        {
            strcpy(productInventory[i].productId, productId);
            productInventory[i].quantity = quantity;
            break;
        }
    }
}

// Update product inventory
void updateProductInventory(char *productId, int quantity)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (strcmp(productInventory[i].productId, productId) == 0)
        {
            productInventory[i].quantity = quantity;
            break;
        }
    }
}

// Display product inventory
void displayProductInventory()
{
    printf("Product Inventory:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (strlen(productInventory[i].productId) > 0)
        {
            printf("Product ID: %s, Quantity: %d\n", productInventory[i].productId, productInventory[i].quantity);
        }
    }
}