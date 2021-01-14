

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

struct Student {
    char name[50];
    int serial_no;
    int subject_1_mark;
    int subject_2_mark;
    int subject_3_mark;
    int subject_4_mark;
    int subject_5_mark;
    int average;
    int rank;
};



int main() 
{ 
	
	FILE* fp = fopen("./input.csv", "r"); 
    struct Student students[100]; 
    int n = 0;
	if (!fp) 
		printf("Can't open file\n"); 

	else { 
	
		char buffer[1024]; 

		int row = 0; 
		int column = 0; 

		while (fgets(buffer, 1024, fp)) { 
			column = 0; 
			row++; 

			if (row == 1) 
				continue; 
            n++;
			char* value = strtok(buffer, ","); 
            struct Student student;
			while (value) { 
				switch (column) {
                    case 0:
                        strcpy(student.name,value);
                        break;
                    case 1:
                        student.serial_no = atoi(value);
                        break;
                    case 2:
                        student.subject_1_mark = atoi(value);
                        break;
                    case 3:
                        student.subject_2_mark = atoi(value);
                        break;
                    case 4:
                        student.subject_3_mark = atoi(value);
                        break;
                    case 5:
                        student.subject_4_mark = atoi(value);
                        break;
                    case 6:
                        student.subject_5_mark = atoi(value);
                        student.average = (student.subject_1_mark + student.subject_2_mark+student.subject_3_mark+student.subject_4_mark + student.subject_5_mark)/5;
                        students[row-2] = student;
                        break;

                }
				value = strtok(NULL, ","); 
				column++; 
			} 
            // printf("%d",students[row-2].average);
			// printf("\n"); 
		} 

		fclose(fp); 
	}
    
    struct Student temp;

    for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                if (students[i].average < students[j].average) 
                {
                    temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        } 
    printf("--------------------------------------------------------------\n");
    printf("serial no. |    name   | average  | rank \n");
    for (int i = 0; i < n; ++i) {
        students[i].rank = i+1;
        printf("%d          |   %s    |   %d    |   %d   \n",students[i].serial_no,students[i].name,students[i].average,students[i].rank);
    }
    printf("--------------------------------------------------------------\n");

	return 0; 
} 
