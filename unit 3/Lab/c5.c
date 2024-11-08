#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Users 100

typedef struct Message
{
    char content[256];
    char sender[256];
    struct Message *next;
    struct Message *prev;
} Message;

typedef struct Chat
{
    Message *head;
    Message *tail;
} Chat;

typedef struct User
{
    char userId[50];
    char username[50];
    Chat chatHistory;

} User;

User *userDirectory[MAX_Users];

int hashFunction(char *userId)
{
    int i, hash = 0;
    for (i = 0; userId[i] != '\0'; i++)
    {
        hash = (hash + userId[i]) % MAX_Users;
    }
    return hash;
}

void CreateUser(char *userId, char *username)
{
    int index = hashFunction(userId);
    User *newUser = (User *)malloc(sizeof(User));
    strcpy(newUser->userId, userId);
    strcpy(newUser->username, username);
    newUser->chatHistory.head = newUser->chatHistory.tail = NULL;
    userDirectory[index] = newUser;
}

User *findUser(char *userId)
{
    int index = hashFunction(userId);
    if (userDirectory[index] != NULL && strcmp(userDirectory[index]->userId, userId) == 0)
    {
        return userDirectory[index];
    }
    return NULL;
}

Message *createMessage(char *content, char *sender)
{
    Message *newMessage = (Message *)malloc(sizeof(Message));
    strcpy(newMessage->content, content);
    strcpy(newMessage->sender, sender);
    newMessage->next = newMessage->prev = NULL;
    return newMessage;
}

void sendMessage(User *user, char *content, char *senderId)
{
    Message *newMessage = createMessage(content, senderId);

    if (user->chatHistory.tail == NULL)
    {
        user->chatHistory.head = user->chatHistory.tail = newMessage;
    }
    else
    {
        user->chatHistory.tail->next = newMessage;
        newMessage->prev = user->chatHistory.tail;
        user->chatHistory.tail = newMessage;
    }
}

void ListMessages(User *user)
{
    Message *current = user->chatHistory.head;
    while (current != NULL)
    {
        printf("%s: %s\n", current->sender, current->content);
        current = current->next;
    }
}

int main()
{
    int i;
    for (i = 0; i < MAX_Users; i++)
    {
        userDirectory[i] = NULL;
    }

    int choice, unmUsers, numMessages;
    char userId[50], username[50], content[256], senderId[50];

    printf("Enter number of users: ");
    scanf("%d", &unmUsers);
    for (i = 0; i < unmUsers; i++)
    {
        printf("Enter user id: ");
        scanf("%s", userId);
        printf("Enter username: ");
        scanf("%s", username);
        CreateUser(userId, username);
    }

    printf("Enter number of messages: ");
    scanf("%d", &numMessages);
    for (i = 0; i < numMessages; i++)
    {
        printf("Enter user id: ");
        scanf("%s", userId);
        printf("Enter message: ");
        User *user = findUser(userId);
        if (user != NULL)
        {
            scanf(" %[^\n]s", content); // Read the message content
            printf("Enter sender id: ");
            scanf("%s", senderId);
            sendMessage(user, content, senderId);
        }
        else
        {
            printf("User with id %s not found.\n", userId);
        }
    }

    printf("Enter user id: ");
    scanf("%s", userId);
    User *user = findUser(userId);
    ListMessages(user);

    return 0;
}