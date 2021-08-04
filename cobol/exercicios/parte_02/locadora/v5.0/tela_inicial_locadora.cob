       IDENTIFICATION DIVISION.
       PROGRAM-ID. tela_inicial_locadora.

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
           02 LINE 08 COL 15 VALUE "[1] CADASTRAR NOVO ALUGUEL".
           02 LINE 09 COL 15 VALUE "[2] REGISTRAR  FILMES".
           02 LINE 10 COL 15 VALUE "[0] SAIR".
           02 LINE 11 COL 15 VALUE "OPCAO: ".
           02 LINE 11 COL PLUS 1 PIC X TO WS-OPCAO.
           02 LINE 12 COL 15 VALUE "==================================".

      *================================================================= 
       PROCEDURE DIVISION.
      *=================================================================

       INICIO.
       DISPLAY "===========>>>>>" WS-OPCAO.
       ACCEPT WS-DUMMY.
       DISPLAY MENU-ACAO-INICIAL.
       ACCEPT MENU-ACAO-INICIAL.

       EVALUATE WS-OPCAO
           WHEN 1
               CALL "aluguel"
                   SET WS-OPCAO TO ZERO
               GO TO INICIO
            WHEN 2
               CALL "registro_de_filmes"
               GO TO INICIO
           WHEN 0
               GOBACK
           WHEN OTHER
              GO TO INICIO
       END-EVALUATE.
       
        
       
       