       IDENTIFICATION DIVISION.
       PROGRAM-ID. TELA_INICIAL.

      *================================================================= 
       DATA DIVISION.
      *=================================================================

      *----------------------------------------------------------------- 
       WORKING-STORAGE SECTION.
      *----------------------------------------------------------------- 

       77 WS-OPCAO PIC 9(01).
       77 DUMMY PIC X(01).
       
      *----------------------------------------------------------------- 
       SCREEN SECTION.
      *----------------------------------------------------------------- 

       01 MENU-INICIAL.
           02 BLANK SCREEN.
           02 LINE 07 COL 15 VALUE "==================================".
           02 LINE 08 COL 15 VALUE "[1] LOGIN".
           02 LINE 09 COL 15 VALUE "[2] LOGIN COMO ADMINISTRADOR".
           02 LINE 10 COL 15 VALUE "[0] SAIR ".
           02 LINE 11 COL 15 VALUE "OPCAO: ".
           02 LINE 11 COL PLUS 1 PIC 9(01) TO WS-OPCAO.
           02 LINE 13 COL 15 VALUE "==================================".

      *================================================================= 
       PROCEDURE DIVISION.
      *================================================================= 

       INICIO.
       
       DISPLAY MENU-INICIAL.
       ACCEPT MENU-INICIAL.       

       EVALUATE WS-OPCAO
           WHEN 1
               CALL "tela_login"              
               GO TO INICIO
           WHEN 0
              STOP RUN
           WHEN OTHER
              GO TO INICIO
       END-EVALUATE.

       STOP RUN.
        
       