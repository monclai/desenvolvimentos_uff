       IDENTIFICATION DIVISION.
       PROGRAM-ID. AULA003.

       DATA DIVISION.
       
       WORKING-STORAGE SECTION.
       
       77 WS-VALOR     PIC 9(10) VALUE 10.
       77 WS-VALOR2    PIC 9(10) VALUE ZEROS.

       01 WS-TOT.
           02 WS-TOTAL     PIC 9(5) VALUE 19.

       01 WS-TOT2.
           02 WS-TOTAL     PIC 9(5) VALUE ZEROS.

      *================================================================= 

       PROCEDURE DIVISION.
       
       MOVE WS-TOTAL OF WS-TOT TO WS-VALOR.

       DISPLAY WS-VALOR.

       STOP RUN.



      *MOVE 20 TO WS-VALOR2.
      *VALOR2=20
      *DISPLAY WS-VALOR2. 

      *MOVE WS-VALOR TO WS-VALOR2
      *DISPLAY WS-VALOR2.

      *MOVE 70 TO WS-VALOR WS-VALOR2.
      *DISPLAY 'VALOR ' WS-VALOR.
      *DISPLAY 'VALOR_2 ' WS-VALOR2.

       