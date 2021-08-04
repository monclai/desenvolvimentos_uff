       IDENTIFICATION DIVISION.
       PROGRAM-ID. TELA_LOGIN.

      *================================================================= 
       DATA DIVISION.
      *=================================================================

      *----------------------------------------------------------------- 
       WORKING-STORAGE SECTION.
      *-----------------------------------------------------------------

       77 WS-OPCAO         PIC X.
       77 WS-DUMMY         PIC X(01).  
       
      *----------------------------------------------------------------- 
       SCREEN SECTION.
      *-----------------------------------------------------------------

       01 MENU-ACAO-INICIAL.
           02 BLANK SCREEN.
           02 LINE 07 COL 15 VALUE "==================================".
           02 LINE 08 COL 15 VALUE "[1] CADASTRAR NOVO CLIENTE".
           02 LINE 09 COL 15 VALUE "[2] ALUGAR FILME".
           02 LINE 10 COL 15 VALUE "[3] DEVOLVER FILME".
           02 LINE 11 COL 15 VALUE "[0] SAIR".
           02 LINE 12 COL 15 VALUE "OPCAO: ".
           02 LINE 12 COL PLUS 1 PIC X TO WS-OPCAO.
           02 LINE 13 COL 15 VALUE "==================================".

      *================================================================= 
       PROCEDURE DIVISION.
      *=================================================================

       INICIO.

       DISPLAY MENU-ACAO-INICIAL.
       ACCEPT MENU-ACAO-INICIAL.

       IF WS-OPCAO IS EQUAL 1
           CALL "cadastro_cliente".

       ACCEPT WS-DUMMY.

       STOP RUN.
        
       
       