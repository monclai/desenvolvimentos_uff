       IDENTIFICATION DIVISION.
       PROGRAM-ID. SCREEN_SECTION_02.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       WOPCAO PIC 9 VALUE ZERO.
       SCREEN SECTION.
       01 MENU-PRINCIPAL.
           02 BLANK SCREEN.
               02 LINE 1 COL 1 VALUE "*****************************************".
               02 LINE 2 COL 21 VALUE "SISTEMA DE COMPRA E VENDA DE MERCADORIAS".
               02 LINE 3 COL 1 VALUE "*****************************************".
               02 LINE 4 COL 33 VALUE "MENU PRINCIPAL".
               02 LINE 7 COL 10 VALUE "[1] CADASTRO MERCADORIA".
               02 LINE 8 COL 10 VALUE "[2] CADASTRO CLIENTE".
               02 LINE 9 COL 10 VALUE "[3] CADASTRO".
               02 LINE 10 COL 10 VALUE "[4] LISTAGEM DE MERCADORIA".
               02 LINE 11 COL 10 VALUE "[5] LISTAGEM DE CLIENTE".
               02 LINE 12 COL 10 VALUE "[6] SAIR SISTEMA".
               02 LINE 15 COL 10 "DIGITE A OPÇÃO DESEJADA[.]".
               02 OPCAO LINE 15 COL 34 PIC 9 USING WOPCAO AUTO.



       PROCEDURE DIVISION.
       INICIO.
           DISPLAY MENU-PRINCIPAL.
           ACCEPT MENU-PRINCIPAL.
           EVALUATE WOPCAO
               WHEN 1
                  CALL "CADMERCADORIA" USING WOPCAO
                WHEN 2
                   CALL "APLICACAO"
                   GO TO INICIO
                WHEN 6
                   STOP RUN
               WHEN OTHER
                  GO TO INICIO
           END-EVALUATE.
       STOP RUN.
              