#include <iostream>
using namespace std;

struct Node
{
    string question;
    string options[4];
    char answer;
    Node *next;
};

Node *head = NULL;

void addQuestion()
{
    Node *newNode = new Node;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter question: ";
    getline(cin, newNode->question);

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter option " << char('A' + i) << ": ";
        getline(cin, newNode->options[i]);
    }

    cout << "Enter correct answer (A/B/C/D): ";
    cin >> newNode->answer;

    newNode->answer = toupper(newNode->answer);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Question added successfully!\n";
}

void displayQuestions()
{
    Node *temp = head;
    int count = 1;

    if (head == NULL)
    {
        cout << "No questions available.\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "\nQ" << count++ << ". "
             << temp->question << "\n";

        for (int i = 0; i < 4; i++)
        {
            cout << char('A' + i) << ". "
                 << temp->options[i] << "\n";
        }

        temp = temp->next;
    }
}

void startQuiz()
{
    Node *temp = head;
    int score = 0;
    int total = 0;
    char choice;

    if (head == NULL)
    {
        cout << "No questions available. Add questions first.\n";
        return;
    }

    while (temp != NULL)
    {
        total++;

        cout << "\nQ" << total << ". "
             << temp->question << "\n";

        for (int i = 0; i < 4; i++)
        {
            cout << char('A' + i) << ". "
                 << temp->options[i] << "\n";
        }

        cout << "Enter your answer (A/B/C/D): ";
        cin >> choice;

        choice = toupper(choice);

        if (choice == temp->answer)
        {
            cout << "Correct answer!\n";
            score++;
        }
        else
        {
            cout << "Wrong answer! Correct answer: "
                 << temp->answer << "\n";
        }

        temp = temp->next;
    }

    cout << "\n----- QUIZ RESULT -----\n";
    cout << "Total Questions: " << total << "\n";
    cout << "Correct Answers: " << score << "\n";
    cout << "Wrong Answers: " << total - score << "\n";
    cout << "Final Score: " << score << "/" << total << "\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== QUIZ MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Question\n";
        cout << "2. Display Questions\n";
        cout << "3. Start Quiz\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
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
            cout << "Exiting Quiz Management System.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}