#include <iostream>
#define size 10
using namespace std;
class patient
{
public:
    string patient_name;
    int priority;
};
class Priority_queue
{
private:
    patient arr[size];
    int front;
    int rear;

public:
    Priority_queue()
    {
        front = -1;
        rear = -1;
    }
    bool isfull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
    bool isempty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
    void enqueue(patient p)
    {
        if (isfull())
        {
            cout << "Queue Overflow..." << endl;
            return;
        }
        else
        {
            int i = rear;
            while (i >= 0 && (p.priority > arr[i].priority))
            {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = p;
            rear++;
        }
    }
    string check(int num)
    {
        if (num == 3)
        {
            return "Serious";
        }
        else if (num == 2)
        {
            return "Non-Serious";
        }
        return "General Checkup";
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "Queue is Empty..." << endl;
            return;
        }
        else
        {
            front++;

            cout << arr[front].patient_name << "\t\t" << check(arr[front].priority) << endl;
        }
    }
};
int main()
{
    Priority_queue Q;
    int count;
    cout << "\nEnter Number of patients:- ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        patient P;
        cout << "\n\nEnter patient name:- ";
        cin >> P.patient_name;
        cout << "Enter priority for patient[1(low), 2(medium), 3(high)]:- ";
        cin >> P.priority;
        Q.enqueue(P);
    }
    cout << endl;
    cout << "\nPatient in Queue : - " << endl;
    while (!Q.isempty())
    {
        Q.dequeue();
    }
    return 0;
}
