       IDENTIFICATION DIVISION.
       PROGRAM-ID. TELA_LOGIN.

      *================================================================= 
       ENVIRONMENT DIVISION.
      *=================================================================

      *-----------------------------------------------------------------
       INPUT-OUTPUT SECTION.
      *-----------------------------------------------------------------

       FILE-CONTROL.

       SELECT FILE-INPUT
           ASSIGN TO "FUNC.dat"
           ORGANIZATION IS LINE SEQUENTIAL
           ACCESS MODE IS SEQUENTIAL
           FILE STATUS IS FS-STAT.
      

      *================================================================= 
       DATA DIVISION.
      *=================================================================

      *----------------------------------------------------------------- 
       FILE SECTION.
      *-----------------------------------------------------------------

       FD FILE-INPUT.
       01 FILE-INPUT-REG.
           02 FS-KEY.
               03 FS-CPF   PIC 9(03).
            02 FS-NOME     PIC X(40).
            02 FS-SENHA    PIC X(20). 

      *----------------------------------------------------------------- 
       WORKING-STORAGE SECTION.
      *-----------------------------------------------------------------

       
       77 FS-STAT          PIC 9.
       77 WS-VERIFIC       PIC 9(01) VALUE ZERO.
       

       01 WS-EOF           PIC A(01).

       01 WS-USER.
           02 WS-NOME      PIC X(40).
           02 WS-SENHA     PIC X(40).
           03 WS-CPF       PIC 9(11).

       01 WS-FILE-INPUT-REG.
           02 WS-FILE-KEY.
               03 WS-FILE-ID    PIC 9(03).
            02 WS-FILE-NOME     PIC X(40).
            02 WS-FILE-SENHA    PIC X(20). 


      *----------------------------------------------------------------- 
       SCREEN SECTION. 
      *-----------------------------------------------------------------

       01 TELA-LOGIN.
           02 BLANK SCREEN.
           02 LINE 07 COL 15 VALUE "===========================".
           02 LINE 08 COL 15 VALUE "NOME: ".
           02 LINE 08 COL PLUS 1 PIC X(40) TO WS-NOME.
           02 LINE 09 COL 15 VALUE "SENHA: ".
           02 LINE 09 COL PLUS 1 PIC X(40) TO WS-SENHA.
           02 LINE 11 COL 15 VALUE "===========================".

      *================================================================= 
       PROCEDURE DIVISION.
      *================================================================= 
    
       INICIO.

       DISPLAY TELA-LOGIN.
       ACCEPT TELA-LOGIN.

       PERFORM UNTIL WS-EOF = "Y"
           READ FILE-INPUT INTO WS-FILE-INPUT-REG
               AT END MOVE "Y" TO WS-EOF
               NOT END PERFORM CONSULTA
            END-READ 
       END-PERFORM.

       CLOSE FILE-INPUT.

       IF WS-VERIFIC IS EQUAL 1
           CALL "tela_inicial_locadora"
       ELSE 
           DISPLAY "USUARIO NAO CADASTRADO"
       END-IF.

       GOBACK.

      *----------------------------------------------------------------- 
       CONSULTA.
       IF WS-FILE-NOME = WS-NOME
           IF WS-FILE-SENHA = WS-SENHA
               SET WS-VERIFIC TO 1
       END-IF.

       
       