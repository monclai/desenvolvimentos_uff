       IDENTIFICATION DIVISION.
       PROGRAM-ID. SORTE.
       ENVIRONMENT DIVISION.
           INPUT-OUTPUT SECTION.
           FILE-CONTROL.
           SELECT INPUTE
              ASSIGN TO "entrada.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.
              SELECT OUTPUTE ASSIGN TO "saida.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.
              SELECT WORK ASSIGN TO "arqtemp.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS IS SEQUENTIAL.
       DATA DIVISION.
           FILE SECTION.
           FD INPUTE.
           01 INPUT-STUDENT.
              05 STUDENT-ID-I PIC 9(3).
              05 STUDENT-NAME-I PIC X(25).

           FD OUTPUTE.
           01 OUTPUT-STUDENT.
              05 STUDENT-ID-O PIC 9(3).
              05 STUDENT-NAME-O PIC X(25).

           SD WORK.
           01 WORK-STUDENT.
              05 STUDENT-ID-W PIC 9(3).
              05 STUDENT-NAME-W PIC X(25).

       PROCEDURE DIVISION.
           SORT WORK ON ASCENDING KEY STUDENT-ID-O
           USING INPUTE GIVING OUTPUTE.
           DISPLAY 'Enfim ordenado!'.
       STOP RUN.
