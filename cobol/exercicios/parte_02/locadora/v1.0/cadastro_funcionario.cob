       identification division.
       program-id. cadastro_cliente.

      *=================================================================
       environment division.
      *================================================================= 
       input-output section.
      *----------------------------------------------------------------- 
       file-control.

       select file1
           assign to disk
           organization is indexed
           access mode is random
           file status is fs-stat
           record key is fs-key.

      *================================================================= 
       data division.
      *================================================================= 
       file section.
      *-----------------------------------------------------------------

       FD FILE1 VALUE OF FILE-ID IS "FUNC.dat".
       01 FILE1-REC.
           02 FS-KEY.
               03 FS-ID    PIC 9(03).
            02 FS-NOME     PIC X(40).
            02 FS-SENHA    PIC X(40).

      *----------------------------------------------------------------- 
       working-storage section.
      *----------------------------------------------------------------- 
       77 WS-ID            PIC 9(01).

      *----------------------------------------------------------------- 
       screen section.
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

       01 SS-MENU FOREGROUND-COLOR 6.
           05 LINE 07 COLUMN 15 VALUE "1 - INCLUIR".
           05 LINE 08 COLUMN 15 VALUE "2 - CONSULTAR".
           05 LINE 09 COLUMN 15 VALUE "3 - ALTERAR".
           05 LINE 10 COLUMN 15 VALUE "4 - EXCLUIR".
           05 LINE 11 COLUMN 15 VALUE "X - ENCERRAR".
           05 LINE 13 COLUMN 15 VALUE "OPCAO: ".
           05 LINE 13 COL PLUS 1 USING WS-OPCAO AUTO.

       01 SS-TELA-REGISTRO.
           05 SS-DADOS.
               10 LINE 11 COLUMN 10 VALUE " NOME:".
               10 COLUMN PLUS 2 PIC X(40) USING FS-NOME.
               10 LINE 12 COLUMN 10 VALUE "SENHA:".
               10 COLUMN PLUS 2 PIC X(40) USING FS-SENHA.

       01 SS-ERRO.
           05 FILLER FOREGROUND-COLOR 4 BACKGROUND-COLOR 1 HIGHLIGHT.
               10 LINE WS-NUML COLUMN 2 PIC X(80) FROM WS-MSGERRO BELL.
               10 COLUMN PLUS 2 TO WS-ERRO.

      *=================================================================  
       PROCEDURE DIVISION.
      *================================================================= 

       INICIO.

           DISPLAY SS-TELA-REGISTRO.
           ACCEPT SS-TELA-REGISTRO.

       
       CLOSE FILE1.
       STOP RUN.

      * -----------------------------------
      
       