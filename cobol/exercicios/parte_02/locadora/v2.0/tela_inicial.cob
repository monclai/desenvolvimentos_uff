       IDENTIFICATION DIVISION.
       PROGRAM-ID. TELA_INICIAL.

      *================================================================= 
       DATA DIVISION.
      *================================================================= 

      *----------------------------------------------------------------- 
       WORKING-STORAGE SECTION.
      *----------------------------------------------------------------- 

      *---------------------CONTROLE DE TELA---------------------------- 
       01 WS-MODULO.
           02 FILLER       PIC X(11).
           02 WS-OP        PIC X(20)   VALUE spaces.

       77 ws-numl          pic 999.
       77 ws-numc          pic 999.
       77 cor-fundo        pic 9       value 4.
       77 cor-frente       pic 9       value 6.

       77 ws-status        pic x(30).
       
       77 WS-DUMMY         PIC X(01).

       88 WS-ENCERRAR                     VALUE IS "X" "x".
      *-----------------------------------------------------------------

       77 WS-OPCAO         PIC X(01).  

      *----------------------------------------------------------------- 
       SCREEN SECTION.
      *----------------------------------------------------------------- 

       01 SS-CLS.
           05 SS-FILLER.
               10 BLANK SCREEN.
               10 LINE 01 COLUMN 01 ERASE EOL
               BACKGROUND-COLOR COR-FUNDO.
               10 LINE WS-NUML COLUMN 01 ERASE EOL
               BACKGROUND-COLOR COR-FUNDO.
           05 SS-CABECALHO.
               10 LINE 01 COLUMN 02 PIC X(31) FROM WS-MODULO
               HIGHLIGHT FOREGROUND-COLOR COR-FRENTE
               BACKGROUND-COLOR COR-FUNDO.
           05 SS-STATUS.
               10 LINE WS-NUML COLUMN 2 ERASE EOL PIC X(30)
               FROM WS-STATUS HIGHLIGHT
               FOREGROUND-COLOR COR-FRENTE
               BACKGROUND-COLOR COR-FUNDO.

       01 SS-TELA-INICIAL.
           02 LINE 07 COL 15 VALUE "==================================".
           02 LINE 08 COL 15 VALUE "            LOCADORA              ".
           02 LINE 09 COL 15 VALUE "==================================".

      *================================================================= 
       PROCEDURE DIVISION.
      *================================================================= 

       INICIO.
       
       SET ENVIRONMENT 'COB_SCREEN_EXCEPTIONS' TO 'Y'.
       SET ENVIRONMENT 'COB_SCREEN_ESC' TO 'Y'.
       SET ENVIRONMENT 'ESCDELAY' TO '25'.           
       ACCEPT WS-NUML FROM LINES.
       ACCEPT WS-NUMC FROM COLUMNS.
       MOVE "TELA INICIAL" TO WS-OP.
       MOVE "PRESIONE ENTER PRA CONTINUAR" TO WS-STATUS.
       DISPLAY SS-CLS.
       DISPLAY SS-TELA-INICIAL.
       ACCEPT SS-TELA-INICIAL.
       ACCEPT WS-DUMMY.
       CALL "tela_inicial_locadora"
       ACCEPT WS-DUMMY.
       
       
       STOP RUN.
       