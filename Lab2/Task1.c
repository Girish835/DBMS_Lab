#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 4
#define MIN_COURSES 3
#define FILE_NAME "students.txt"
#define TEMP_FILE_NAME "students_temp.txt"
#define STR_MAX_LENGTH 30

typedef struct {
    char course_name[STR_MAX_LENGTH];
    int credits;
    int grade;
} course;

typedef struct {
    int roll_no;
    char name[STR_MAX_LENGTH];
    char dept[STR_MAX_LENGTH];
    course courses[MAX_COURSES];
    float gpa;
} student;

void insert_student();
void create_gpa_column();
void delete_course();
void insert_new_course();
void update_course_name();
void calculate_gpa();
void upgrade_grade();
void generate_report_card();

int main() {
    char query;
    printf("\nMenu:\n");
    printf("a. Insert student\n");
    printf("b. Create GPA column for all students\n");
    printf("c. Delete a course for a student\n");
    printf("d. Insert a new course for a student\n");
    printf("e. Update the name of a course for two students\n");
    printf("f. Calculate GPA of all students\n");
    printf("g. Upgrade the grade point of a students who have go 7 in a course\n");
    printf("h. calculate GPA of students\n");
    printf("i. Genreate report card for given roll number\n");
    printf("X. Exit\n");

    do {
        printf("Enter your query: ");
        scanf(" %c", &query);

        switch (query) {
            case 'a':
                insert_student();
                break;
            case 'b':
                create_gpa_column();
                break;
            case 'c':
                delete_course();
                break;
            case 'd':
                insert_new_course();
                break;
            case 'e':
                update_course_name();
                break;
            case 'f':
                calculate_gpa();
                break;
            case 'g':
                upgrade_grade();
                break;
            case 'h':
                calculate_gpa();
                break;
            case 'i':
                generate_report_card();
                break;
            case 'X':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid query.\n");
        }
    } while (query != 'X');

    return 0;
}

void insert_student() {
    student s;
    printf("Enter roll no.: ");
    scanf("%d", &s.roll_no);
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student department: ");
    scanf("%s", s.dept);

    int num_courses = 0;
    for (int i = 0; i < MAX_COURSES; i++) {
        printf("Enter course_name, credits, grade of course %d: ", i + 1);
        scanf("%s %d %d", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade);
        if (s.courses[i].credits != 0) {
            ++num_courses;
        }
    }

    if (num_courses < MIN_COURSES) {
        printf("The student should have taken a minimum of %d courses the previous semester\n", MIN_COURSES);
        return;
    }

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%d %s %s", s.roll_no, s.name, s.dept);
    for (int i = 0; i < MAX_COURSES; i++) {
        fprintf(file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
    }
    fprintf(file, "\n");
    fclose(file);
}

void create_gpa_column() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILE_NAME, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        int total_grade = 0, total_creds = 0;
        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
            total_grade += s.courses[i].grade * s.courses[i].credits;
            total_creds += s.courses[i].credits;
        }

        s.gpa = (float) total_grade / total_creds;
        printf("gpa is %.2f\n", s.gpa);
        fprintf(temp_file, "%d %s %s", s.roll_no, s.name, s.dept);
        for (int i = 0; i < MAX_COURSES; i++) {
            fprintf(temp_file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
        }
        fprintf(temp_file, " %.2f\n", s.gpa);
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);
}

void delete_course() {
    int roll_no;
    printf("Enter roll number of the student: ");
    scanf("%d", &roll_no);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILE_NAME, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
        }

        sscanf(buffer + offset, "%f", &s.gpa);

        if (s.roll_no == roll_no) {
            s.courses[MAX_COURSES - 1].credits = 0;
            s.courses[MAX_COURSES - 1].grade = 0;
            strcpy(s.courses[MAX_COURSES - 1].course_name, "NA");
        }

        fprintf(temp_file, "%d %s %s", s.roll_no, s.name, s.dept);
        for (int i = 0; i < MAX_COURSES; i++) {
            fprintf(temp_file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
        }
        fprintf(temp_file, " %.2f\n", s.gpa);
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);
}

void insert_new_course() {
    int roll_no;
    printf("Enter roll number of the student: ");
    scanf("%d", &roll_no);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILE_NAME, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        int num_courses = 0;
        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
            if (s.courses[i].credits != 0) {
                ++num_courses;
            }
        }

        sscanf(buffer + offset, "%f", &s.gpa);

        if (s.roll_no == roll_no) {
            if (num_courses >= MAX_COURSES) {
                printf("The student has already taken the maximum number of courses (%d).\n", MAX_COURSES);
            } else {
                printf("Enter new course name, credits, and grade: ");
                scanf("%s %d %d", s.courses[num_courses].course_name, &s.courses[num_courses].credits, &s.courses[num_courses].grade);
            }
        }

        fprintf(temp_file, "%d %s %s", s.roll_no, s.name, s.dept);
        for (int i = 0; i < MAX_COURSES; i++) {
            fprintf(temp_file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
        }
        fprintf(temp_file, " %.2f\n", s.gpa);
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);
}

void update_course_name() {
    int roll_no1, roll_no2;
    char old_course_name[STR_MAX_LENGTH], new_course_name[STR_MAX_LENGTH];

    printf("Enter roll number of first student: ");
    scanf("%d", &roll_no1);
    printf("Enter roll number of second student: ");
    scanf("%d", &roll_no2);
    printf("Enter old course name: ");
    scanf("%s", old_course_name);
    printf("Enter new course name: ");
    scanf("%s", new_course_name);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILE_NAME, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
            if ((s.roll_no == roll_no1 || s.roll_no == roll_no2) && strcmp(s.courses[i].course_name, old_course_name) == 0) {
                strcpy(s.courses[i].course_name, new_course_name);
            }
        }

        sscanf(buffer + offset, "%f", &s.gpa);

        fprintf(temp_file, "%d %s %s", s.roll_no, s.name, s.dept);
        for (int i = 0; i < MAX_COURSES; i++) {
            fprintf(temp_file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
        }
        fprintf(temp_file, " %.2f\n", s.gpa);
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);
}

void calculate_gpa() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILE_NAME, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        int total_grade = 0, total_creds = 0;
        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
            total_grade += s.courses[i].grade * s.courses[i].credits;
            total_creds += s.courses[i].credits;
        }

        s.gpa = (float) total_grade / total_creds;

        fprintf(temp_file, "%d %s %s", s.roll_no, s.name, s.dept);
        for (int i = 0; i < MAX_COURSES; i++) {
            fprintf(temp_file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
        }
        fprintf(temp_file, " %.2f\n", s.gpa);
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);
}

void upgrade_grade() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILE_NAME, "w");
    if (temp_file == NULL) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
            if (s.courses[i].grade == 7) {
                s.courses[i].grade++;
            }
        }

        sscanf(buffer + offset, "%f", &s.gpa);

        fprintf(temp_file, "%d %s %s", s.roll_no, s.name, s.dept);
        for (int i = 0; i < MAX_COURSES; i++) {
            fprintf(temp_file, " %s %d %d", s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
        }
        fprintf(temp_file, " %.2f\n", s.gpa);
    }

    fclose(file);
    fclose(temp_file);

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);
}

void generate_report_card() {
    int roll_no;
    printf("Enter roll number of the student: ");
    scanf("%d", &roll_no);

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[500];
    while (fgets(buffer, sizeof(buffer), file)) {
        student s;
        int offset = 0;
        sscanf(buffer, "%d %s %s %n", &s.roll_no, s.name, s.dept, &offset);

        for (int i = 0; i < MAX_COURSES; i++) {
            int local_offset = 0;
            sscanf(buffer + offset, "%s %d %d %n", s.courses[i].course_name, &s.courses[i].credits, &s.courses[i].grade, &local_offset);
            offset += local_offset;
        }

        sscanf(buffer + offset, "%f", &s.gpa);

        if (s.roll_no == roll_no) {
            printf("Report Card for Roll No: %d\n", s.roll_no);
            printf("Name: %s\n", s.name);
            printf("Department: %s\n", s.dept);
            for (int i = 0; i < MAX_COURSES; i++) {
                printf("Course %d: %s, Credits: %d, Grade: %d\n", i + 1, s.courses[i].course_name, s.courses[i].credits, s.courses[i].grade);
            }
            printf("GPA: %.2f\n", s.gpa);
        }
    }

    fclose(file);
}
