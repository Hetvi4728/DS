#include <iostream>
using namespace std;

struct Node
{
    char question[100];
    char options[4][50];
    char answer;
    Node *next;
};

Node *head = NULL;

void addQuestion()
{
    Node *newNode = new Node;

    cout << "Enter question: ";
    cin >> ws;
    cin >> newNode->question;

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter option " << char('A' + i) << ": ";
        cin >> ws;
        cin >> newNode->options[i];
    }

    cout << "Enter correct answer (A/B/C/D): ";
    cin >> newNode->answer;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Question added successfully!\n";
}

void displayQuestions()
{
    Node *temp = head;
    int i = 1;

    if (head == NULL)
    {
        cout << "No questions available.\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "\nQ" << i++ << ". " << temp->question << "\n";

        for (int j = 0; j < 4; j++)
            cout << char('A' + j) << ". " << temp->options[j] << "\n";

        temp = temp->next;
    }
}

void startQuiz()
{
    Node *temp = head;
    int score = 0, total = 0;
    char choice;

    if (head == NULL)
    {
        cout << "No questions available.\n";
        return;
    }

    while (temp != NULL)
    {
        total++;

        cout << "\nQ" << total << ". " << temp->question << "\n";

        for (int i = 0; i < 4; i++)
            cout << char('A' + i) << ". " << temp->options[i] << "\n";

        cout << "Enter answer: ";
        cin >> choice;

        if (toupper(choice) == toupper(temp->answer))
        {
            cout << "Correct!\n";
            score++;
        }
        else
        {
            cout << "Wrong! Correct answer: " << temp->answer << "\n";
        }

        temp = temp->next;
    }

    cout << "\nTotal Questions: " << total;
    cout << "\nCorrect Answers: " << score;
    cout << "\nWrong Answers: " << total - score;
    cout << "\nFinal Score: " << score << "/" << total << "\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n--- QUIZ MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Question\n";
        cout << "2. Display Questions\n";
        cout << "3. Start Quiz\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addQuestion();
            break;
        case 2:
            displayQuestions();
            break;
        case 3:
            startQuiz();
            break;
        case 4:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}