       IDENTIFICATION DIVISION.
       PROGRAM-ID. AULA004.

       DATA DIVISION.
       
       WORKING-STORAGE SECTION.
       
       77 WS-ACUMULADODR   PIC 9(02) VALUE ZEROS.
       77 WS-ACUMULADODR_2 PIC 9(02) VALUE ZEROS.


       PROCEDURE DIVISION.
       
       ADD 1 TO WS-ACUMULADODR.
       ADD 1 3 TO WS-ACUMULADODR.

       ADD 1 GIVING WS-ACUMULADODR_2.

      *Quando usado o giving o valor da variável é reiniciado com o novo
      *Valor, mesmo em somas.


       DISPLAY WS-ACUMULADODR.
       DISPLAY WS-ACUMULADODR_2.

       COMPUTE WS-ACUMULADODR = WS-ACUMULADODR/2.

       DISPLAY WS-ACUMULADODR.



       STOP RUN.