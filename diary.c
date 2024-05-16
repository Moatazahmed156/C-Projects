#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_CONTENT_LEN 1000
#define MAX_ENTRIES 100

// Structure for a diary entry
struct Entry
{
    char date[11];
    char title[MAX_TITLE_LEN];
    char content[MAX_CONTENT_LEN];
};

// Function prototypes
void menu();
void createEntry();
void editEntry();
void deleteEntry();
void listEntries();

// Global variables
struct Entry diary[MAX_ENTRIES];
int numEntries = 0;

int main()
{
    int choice;
    do
    {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            createEntry();
            break;
        case 2:
            editEntry();
            break;
        case 3:
            deleteEntry();
            break;
        case 4:
            listEntries();
            break;
        case 0:
            printf("Exiting...\n");
            printf("Have a good day\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void menu()
{
    printf("\nDiary Management System\n");
    printf(" ---------------------\n");
    printf("| 1. Create Entry     |\n");
    printf("| 2. Edit Entry       |\n");
    printf("| 3. Delete Entry     |\n");
    printf("| 4. List All Entries |\n");
    printf("| 0. Exit             |\n");
    printf(" ---------------------\n");
    printf("Enter your choice: ");
}

void createEntry()
{
    if (numEntries >= MAX_ENTRIES)
    {
        printf("Diary is full! Cannot create more entries.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[numEntries].date);
    getchar();

    printf("Enter title: ");
    fgets(diary[numEntries].title, MAX_TITLE_LEN, stdin);
    diary[numEntries].title[strcspn(diary[numEntries].title, "\n")] = 0;

    printf("Enter content: ");
    fgets(diary[numEntries].content, MAX_CONTENT_LEN, stdin);
    diary[numEntries].content[strcspn(diary[numEntries].content, "\n")] = 0;

    numEntries++;
    printf("Entry created successfully.\n");
}

void editEntry()
{
    if (numEntries == 0)
    {
        printf("No entries found.\n");
        return;
    }

    int index;
    printf("Enter index of entry to edit (1-%d): ", numEntries);
    scanf("%d", &index);
    getchar();
    if (index < 1 || index > numEntries)
    {
        printf("Invalid index!\n");
        return;
    }

    printf("Enter new date (YYYY-MM-DD): ");
    scanf("%s", diary[index - 1].date);
    getchar();

    printf("Enter new title: ");
    fgets(diary[index - 1].title, MAX_TITLE_LEN, stdin);
    diary[index - 1].title[strcspn(diary[index - 1].title, "\n")] = 0;

    printf("Enter new content: ");
    fgets(diary[index - 1].content, MAX_CONTENT_LEN, stdin);
    diary[index - 1].content[strcspn(diary[index - 1].content, "\n")] = 0;

    printf("Entry edited successfully.\n");
}

void deleteEntry()
{
    if (numEntries == 0)
    {
        printf("No entries found.\n");
        return;
    }

    int index;
    printf("Enter index of entry to delete (1-%d): ", numEntries);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > numEntries)
    {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < numEntries - 1; i++)
    {
        strcpy(diary[i].date, diary[i + 1].date);
        strcpy(diary[i].title, diary[i + 1].title);
        strcpy(diary[i].content, diary[i + 1].content);
    }

    numEntries--;
    printf("Entry deleted successfully.\n");
}

void listEntries()
{
    if (numEntries == 0)
    {
        printf("No entries found.\n");
        return;
    }

    printf("Listing all entries:\n");
    for (int i = 0; i < numEntries; i++)
    {
        printf(" -----------------------------------------------------------\n");
        printf(" Entry %d\n", i + 1);
        printf(" Date: %s\n", diary[i].date);
        printf(" Title: %s\n", diary[i].title);
        printf(" Content: %s\n", diary[i].content);
        printf(" -----------------------------------------------------------\n");
        printf("\n");
    }
}
