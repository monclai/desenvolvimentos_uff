       IDENTIFICATION DIVISION.
       PROGRAM-ID. tela_inicial_locadora.

      *================================================================= 
       DATA DIVISION.
      *=================================================================

      *----------------------------------------------------------------- 
       WORKING-STORAGE SECTION.
      *-----------------------------------------------------------------

       77 WS-OPCAO                 PIC 9(01) VALUE ZERO.
       77 WS-DUMMY                 PIC X(01).
      * 77 WS-SAIR          PIC X(01) VALUE ZEROS.

       77 WS-OP                    PIC X.
           88 WS-ESCOLHA-SAIR              VALUE IS "0".  
       
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
           02 LINE 11 COL PLUS 1 PIC 9(01) TO WS-OPCAO.
           02 LINE 12 COL 15 VALUE "==================================".

      *================================================================= 
       PROCEDURE DIVISION.
      *=================================================================

       INICIO.

       PERFORM UNTIL WS-ESCOLHA-SAIR
      *     MOVE SPACES TO WS-OPCAO
           SET WS-OPCAO TO ZERO
           DISPLAY MENU-ACAO-INICIAL
           ACCEPT MENU-ACAO-INICIAL
           EVALUATE WS-OPCAO
               WHEN 1
                  PERFORM CADASTRO THRU CADASTRO-FIM
               WHEN 2
                  PERFORM REGISTRO THRU REGISTRO-FIM
               WHEN 0
                   GOBACK
           END-EVALUATE
       END-PERFORM.
           
       CADASTRO.
           CALL "aluguel".
       CADASTRO-FIM.    

       REGISTRO.
           CALL "registro_de_filmes".
       REGISTRO-FIM.
        
       
       