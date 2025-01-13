#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

typedef struct Appointment {
    int id;
    char date[20];
    char time[10];
    struct Appointment *next;
} Appointment;

typedef struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    Appointment *appointments;
    struct Patient *next;
} Patient;

typedef struct Doctor {
    int id;
    char name[MAX_NAME_LENGTH];
    char specialization[MAX_NAME_LENGTH];
    Patient *patients;
    struct Doctor *next;
} Doctor;

Doctor *headDoctor = NULL;

// Function to create a new doctor
Doctor *createDoctor(int id, const char *name, const char *specialization) {
    Doctor *newDoctor = (Doctor *)malloc(sizeof(Doctor));
    newDoctor->id = id;
    strncpy(newDoctor->name, name, MAX_NAME_LENGTH);
    strncpy(newDoctor->specialization, specialization, MAX_NAME_LENGTH);
    newDoctor->patients = NULL;
    newDoctor->next = NULL;
    return newDoctor;
}

// Function to create a new patient
Patient *createPatient(int id, const char *name, int age) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    newPatient->id = id;
    strncpy(newPatient->name, name, MAX_NAME_LENGTH);
    newPatient->age = age;
    newPatient->appointments = NULL;
    newPatient->next = NULL;
    return newPatient;
}

// Function to create a new appointment
Appointment *createAppointment(int id, const char *date, const char *time) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    newAppointment->id = id;
    strncpy(newAppointment->date, date, 20);
    strncpy(newAppointment->time, time, 10);
    newAppointment->next = NULL;
    return newAppointment;
}

// Function to add a doctor to the list
void addDoctor(Doctor *doctor) {
    doctor->next = headDoctor;
    headDoctor = doctor;
}

// Function to add a patient to a specific doctor
void addPatientToDoctor(int doctorId, Patient *patient) {
    Doctor *current = headDoctor;
    while (current != NULL && current->id != doctorId) {
        current = current->next;
    }
    if (current != NULL) {
        patient->next = current->patients;
        current->patients = patient;
    } else {
        printf("Doctor with ID %d not found.\n", doctorId);
    }
}

// Function to add an appointment to a patient
void addAppointmentToPatient(int doctorId, int patientId, Appointment *appointment) {
    Doctor *currentDoctor = headDoctor;
    while (currentDoctor != NULL && currentDoctor->id != doctorId) {
        currentDoctor = currentDoctor->next;
    }
    if (currentDoctor != NULL) {
        Patient *currentPatient = currentDoctor->patients;
        while (currentPatient != NULL && currentPatient->id != patientId) {
            currentPatient = currentPatient->next;
        }
        if (currentPatient != NULL) {
            appointment->next = currentPatient->appointments;
            currentPatient->appointments = appointment;
        } else {
            printf("Patient with ID %d not found under Doctor ID %d.\n", patientId, doctorId);
        }
    } else {
        printf("Doctor with ID %d not found.\n", doctorId);
    }
}

// Function to display all doctors and their details
void displayDoctors() {
    Doctor *currentDoctor = headDoctor;
    while (currentDoctor != NULL) {
        printf("Doctor ID: %d, Name: %s, Specialization: %s\n", currentDoctor->id, currentDoctor->name, currentDoctor->specialization);
        Patient *currentPatient = currentDoctor->patients;
        while (currentPatient != NULL) {
            printf("  Patient ID: %d, Name: %s, Age: %d\n", currentPatient->id, currentPatient->name, currentPatient->age);
            Appointment *currentAppointment = currentPatient->appointments;
            while (currentAppointment != NULL) {
                printf("    Appointment ID: %d, Date: %s, Time: %s\n", currentAppointment->id, currentAppointment->date, currentAppointment->time);
                currentAppointment = currentAppointment->next;
            }
            currentPatient = currentPatient->next;
        }
        currentDoctor = currentDoctor->next;
    }
}

// Function to free all allocated memory
void freeAll() {
    Doctor *currentDoctor = headDoctor;
    while (currentDoctor != NULL) {
        Doctor *tempDoctor = currentDoctor;
        Patient *currentPatient = currentDoctor->patients;
        while (currentPatient != NULL) {
            Patient *tempPatient = currentPatient;
            Appointment *currentAppointment = currentPatient->appointments;
            while (currentAppointment != NULL) {
                Appointment *tempAppointment = currentAppointment;
                currentAppointment = currentAppointment->next;
                free(tempAppointment);
            }
            currentPatient = currentPatient->next;
            free(tempPatient);
        }
        currentDoctor = currentDoctor->next;
        free(tempDoctor);
    }
}

int main() {
    Doctor *doc1 = createDoctor(1, "Dr. Smith", "Cardiology");
    Doctor *doc2 = createDoctor(2, "Dr. Brown", "Neurology");

    addDoctor(doc1);
    addDoctor(doc2);

    Patient *pat1 = createPatient(101, "Alice", 30);
    Patient *pat2 = createPatient(102, "Bob", 40);
    Patient *pat3 = createPatient(103, "Charlie", 25);

    addPatientToDoctor(1, pat1);
    addPatientToDoctor(1, pat2);
    addPatientToDoctor(2, pat3);

    Appointment *app1 = createAppointment(201, "2025-01-15", "10:00 AM");
    Appointment *app2 = createAppointment(202, "2025-01-16", "11:30 AM");
    Appointment *app3 = createAppointment(203, "2025-01-17", "09:00 AM");

    addAppointmentToPatient(1, 101, app1);
    addAppointmentToPatient(1, 102, app2);
    addAppointmentToPatient(2, 103, app3);

    displayDoctors();

    freeAll();
    return 0;
}