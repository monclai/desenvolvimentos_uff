       IDENTIFICATION DIVISION.
       PROGRAM-ID. RELATORIO_CLIENTE.


       DATA DIVISION.

       WORKING-STORAGE SECTION.
       
       01 CLIENTE.
           02 CLIENTE_INFO OCCURS 10 TIMES.
               03 CPF_CLIENTE PIC 9(11).
               03 NOME_CLIENTE PIC X(30).
               03 ESTADO PIC X(02).
               03 CIDADE PIC X(30).
               03 TELEFONE PIC 9(08).

       77 SUBSCRIP PIC 9(02) VALUE ZERO.

       77 DUMMY  PIC X(01).

       SCREEN SECTION.

       01 INPUT-SCREEN.
           02 BLANK SCREEN.
           02 LINE 1 COL 1 VALUE "------------------------------------".
           02 LINE 2 COL 1 VALUE "NOME DO CLIENTE: ".
           02 LINE 2 COL 18 PIC X(30) TO NOME_CLIENTE(SUBSCRIP).
           02 LINE 3 COL 1 VALUE "CPF DO CLIENTE: ".
           02 LINE 3 COL 17 PIC 9(11) TO CPF_CLIENTE(SUBSCRIP).
           02 LINE 4 COL 1 VALUE "ESTADO DO CLIENTE: ".
           02 LINE 4 COL 20 PIC X(02) TO ESTADO(SUBSCRIP).
           02 LINE 5 COL 1 VALUE "CIDADE: ".
           02 LINE 5 COL 9 PIC X(30) TO CIDADE(SUBSCRIP).
           02 LINE 6 COL 1 VALUE "TELEFONE: ".
           02 LINE 6 COL 10 PIC 9(08) TO TELEFONE(SUBSCRIP).
           02 LINE 7 COL 1 VALUE "------------------------------------".

       01 OUTPUT-SCREEN.
           02 BLANK SCREEN.
           02 LINE 1 COL 1 VALUE "------------------------------------".
           02 LINE 2 COL 1 VALUE "NOME DO CLIENTE: ".
           02 LINE 2 COL 18 PIC X(30) FROM NOME_CLIENTE(SUBSCRIP).
           02 LINE 3 COL 1 VALUE "------------------------------------".
       
       
       PROCEDURE DIVISION.

       SET SUBSCRIP TO 1.

       PERFORM 2 TIMES
           ADD 1 GIVING SUBSCRIP
           DISPLAY INPUT-SCREEN
           ACCEPT INPUT-SCREEN
       END-PERFORM. 

       SET SUBSCRIP TO 1.

       DISPLAY OUTPUT-SCREEN.  

       ACCEPT DUMMY.

       STOP RUN.