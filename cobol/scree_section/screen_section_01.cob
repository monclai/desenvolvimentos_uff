       IDENTIFICATION DIVISION.
       PROGRAM-ID. PGM001.
       DATA DIVISION.
       WORKING-STORAGE SECTION. 
       01 WS-N1    PIC 9(04).
       01 WS-N2    PIC 9(04).
       01 WS-SUM   PIC 9(04).
       01 WS-DUMMY PIC X(01).
       SCREEN SECTION.
       01 INPUT-SCREEN.
           02 BLANK SCREEN.
           02 LINE 1 COL 1 VALUE "------------------------------------".
           02 LINE 2 COL 1 VALUE "-             INPUT                -".
           02 LINE 3 COL 1 VALUE "------------------------------------".
           02 LINE 4 COL 1 VALUE "-(1). NUMBER 1:                    -".
           02 LINE 4 COL 18 PIC 9(10) TO WS-N1.
           02 LINE 5 COL 1 VALUE "-(2). NUMBER 2:                    -".
           02 LINE 5 COL 18 PIC 9(10) TO WS-N2.
           02 LINE 6 COL 1 VALUE "------------------------------------".
        01 OUTPUT-SCREEN.
           02 BLANK SCREEN.
           02 LINE 1 COL 1 VALUE "------------------------------------".
           02 LINE 2 COL 1 VALUE "-             SUM                  -".
           02 LINE 3 COL 1 VALUE "------------------------------------".
           02 LINE 4 COL 1 VALUE "-(1). SUM:                         -".
           02 LINE 4 COL 18 PIC 9(04) FROM WS-SUM.
           02 LINE 5 COL 1 VALUE "------------------------------------".
           02 LINE 6 COL 1 VALUE "EXIT ->                             ".
       procedure division.
       A-100.
            DISPLAY INPUT-SCREEN.
            ACCEPT  INPUT-SCREEN.
       
            GO TO A-200.
       A-200.
            ADD WS-N1 TO WS-N2 GIVING WS-SUM.
       
            GO TO A-300.
       A-300.
           DISPLAY OUTPUT-SCREEN.
           ACCEPT WS-DUMMY AT LINE 7 COL 8.
       STOP RUN.
       