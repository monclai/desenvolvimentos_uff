       identification division.
       program-id. registro_de_filmes.             

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

       fd file1 value of file-id is "lista_de_filmes.dat".
       01 file1-rec.
           02 fs-key.
               03 fs-id        pic 9(11) blank when zeros.
            02 fs-categoria    pic x(40).
            02 fs-nome-filme   pic x(40).
            02 filler          pic x(20).

      *----------------------------------------------------------------- 
       working-storage section.
      *----------------------------------------------------------------- 
       
       01 ws-modulo.
           02 filler           pic x(11)   value "clientes-".
           02 ws-op            pic x(20)   value spaces.

       77 ws-opcao             pic x.
           88 e-incluir                value is "1".
           88 e-consultar              value is "2".
           88 e-alterar                value is "3".
           88 e-excluir                value is "4".
           88 e-encerrar               value is "X" "x".

       77 fs-stat              pic 9(02).
           88 fs-ok                    value zeros.
           88 fs-cancela               value 99.
           88 fs-nao-existe            value 35.

       77 ws-erro              pic x.
           88 e-sim                    values are "S" "s".

       77 ws-numl              pic 999.
       77 ws-numc              pic 999.
       77 cor-fundo            pic 9       value 4.
       77 cor-frente           pic 9       value 6.

       77 ws-status            pic x(30).
       77 ws-msgerro           pic x(80).

       copy screenio.

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
           05 LINE 07 COLUMN 15 VALUE "1 - REGISTRAR FILME".
           05 LINE 08 COLUMN 15 VALUE "2 - CONSULTAR".
           05 LINE 09 COLUMN 15 VALUE "3 - ALTERAR".
           05 LINE 10 COLUMN 15 VALUE "4 - EXCLUIR".
           05 LINE 11 COLUMN 15 VALUE "X - ENCERRAR".
           05 LINE 13 COLUMN 15 VALUE "OPCAO: ".
           05 LINE 13 COL PLUS 1 USING WS-OPCAO AUTO.

       01 SS-TELA-REGISTRO.
           05 SS-CHAVE FOREGROUND-COLOR 2.
               10 LINE 10 COLUMN 10 VALUE "IDENTIFICACAO DO FILME:".
               10 COLUMN PLUS 2 PIC 9(11) USING fs-id.
      *         BLANK WHEN ZEROS.
           05 SS-DADOS.
               10 LINE 11 COLUMN 10 VALUE "CATEGORIA:".
               10 COLUMN PLUS 2 PIC X(40) USING fs-categoria.
               10 LINE 12 COLUMN 10 VALUE "NOME DO FILME".
               10 COLUMN PLUS 2 PIC X(40) USING fs-nome-filme.
       01 SS-ERRO.
           05 FILLER FOREGROUND-COLOR 4 BACKGROUND-COLOR 1 HIGHLIGHT.
               10 LINE WS-NUML COLUMN 2 PIC X(80) FROM WS-MSGERRO BELL.
               10 COLUMN PLUS 2 TO WS-ERRO.

      *=================================================================  
       PROCEDURE DIVISION.
      *================================================================= 

       INICIO.

           SET ENVIRONMENT 'COB_SCREEN_EXCEPTIONS' TO 'Y'.
           SET ENVIRONMENT 'COB_SCREEN_ESC' TO 'Y'.
           SET ENVIRONMENT 'ESCDELAY' TO '25'.           
           ACCEPT WS-NUML FROM LINES
           ACCEPT WS-NUMC FROM COLUMNS           
           PERFORM ABRIR-ARQUIVOS
           PERFORM UNTIL E-ENCERRAR
               MOVE "REGISTRO DE FILMES" TO WS-OP
               MOVE "ESCOLHA A OPCAO" TO WS-STATUS
               MOVE SPACES TO WS-OPCAO
               DISPLAY SS-CLS
               ACCEPT SS-MENU
               EVALUATE TRUE
                   WHEN E-INCLUIR
                       PERFORM INCLUI THRU INCLUI-FIM
                   WHEN E-CONSULTAR
                       PERFORM CONSULTA THRU CONSULTA-FIM
                   WHEN E-ALTERAR
                       PERFORM ALTERA THRU ALTERA-FIM
                   WHEN E-EXCLUIR
                       PERFORM EXCLUI THRU EXCLUI-FIM
               END-EVALUATE
           END-PERFORM.
    
       FINALIZA.
       
       CLOSE FILE1.
       GOBACK.

      * -----------------------------------
       
       INCLUI.
           MOVE "INCLUSAO" TO WS-OP.
           MOVE "ESC PARA ENCERRAR" TO WS-STATUS.
           DISPLAY SS-CLS.
           MOVE SPACES TO FILE1-REC.

           INCLUI-LOOP.
           ACCEPT SS-TELA-REGISTRO.
           IF COB-CRT-STATUS = COB-SCR-ESC
               GO INCLUI-FIM
           END-IF
           IF fs-categoria EQUAL SPACES OR fs-nome-filme EQUAL SPACES
               MOVE "FAVOR INFORMAR CATEGORIA E FILME" TO WS-MSGERRO
               PERFORM MOSTRA-ERRO
               GO INCLUI-LOOP
           END-IF
           WRITE FILE1-REC
           INVALID KEY
           MOVE "REGISTRO JA REALIZADO" TO WS-MSGERRO
           PERFORM MOSTRA-ERRO
           MOVE ZEROS TO FS-KEY
           END-WRITE.
           GO INCLUI.
       INCLUI-FIM.
      
      * -----------------------------------
      
       CONSULTA.
           MOVE "CONSULTA" TO WS-OP.
           MOVE "ESC PARA ENCERRAR" TO WS-STATUS.
           DISPLAY SS-CLS.
           CONSULTA-LOOP.
           MOVE SPACES TO FILE1-REC.
           DISPLAY SS-TELA-REGISTRO.
           PERFORM LE-CLIENTE THRU LE-CLIENTE-FIM.
           IF FS-CANCELA
               GO CONSULTA-FIM
           END-IF
           IF FS-OK
               DISPLAY SS-DADOS
               MOVE "PRESSIONE ENTER" TO WS-MSGERRO
               PERFORM MOSTRA-ERRO
           END-IF.
           GO CONSULTA-LOOP.
       CONSULTA-FIM.

      * -----------------------------------
       
       ALTERA.
           MOVE "ALTERACAO" TO WS-OP.
           MOVE "ESC PARA ENCERRAR" TO WS-STATUS.
           DISPLAY SS-CLS.
           ALTERA-LOOP.
           MOVE SPACES TO FILE1-REC.
           DISPLAY SS-TELA-REGISTRO.
           PERFORM LE-CLIENTE THRU LE-CLIENTE-FIM.
           IF FS-CANCELA
               GO TO ALTERA-FIM
           END-IF
           IF FS-OK
               ACCEPT SS-DADOS
               IF COB-CRT-STATUS = COB-SCR-ESC
               GO ALTERA-LOOP
           END-IF
           ELSE
               GO ALTERA-LOOP
           END-IF
           REWRITE FILE1-REC
           INVALID KEY
           MOVE "ERRO AO GRAVAR" TO WS-MSGERRO
           PERFORM MOSTRA-ERRO
           NOT INVALID KEY
           CONTINUE
           END-REWRITE.
           GO ALTERA-LOOP.
       ALTERA-FIM.

      * -----------------------------------

       EXCLUI.
           MOVE "EXCLUSAO" TO WS-OP.
           MOVE "ESC PARA ENCERRAR" TO WS-STATUS.
           DISPLAY SS-CLS.
           MOVE SPACES TO FILE1-REC.
           DISPLAY SS-TELA-REGISTRO.
           PERFORM LE-CLIENTE THRU LE-CLIENTE-FIM.
           IF FS-CANCELA
               GO EXCLUI-FIM
           END-IF
           IF NOT FS-OK
               GO EXCLUI
           END-IF
           DISPLAY SS-DADOS.
           MOVE "N" TO WS-ERRO.
           MOVE "CONFIRMA A EXCLUSAO (S/N)?" TO WS-MSGERRO.
           ACCEPT SS-ERRO.
           IF NOT E-SIM
               GO EXCLUI-FIM
           END-IF
           DELETE FILE1
           INVALID KEY
           MOVE "ERRO AO EXCLUIR" TO WS-MSGERRO
           PERFORM MOSTRA-ERRO
           END-DELETE.
       EXCLUI-FIM.

      * -----------------------------------
      * LE CLIENTE E MOSTRA MENSAGEM SE CHAVE NÃO EXISTE

       LE-CLIENTE.

           ACCEPT SS-CHAVE.
           IF NOT COB-CRT-STATUS = COB-SCR-ESC
               READ FILE1
               INVALID KEY
               MOVE "REGISTRO NAO ENCONTRADO" TO WS-MSGERRO
               PERFORM MOSTRA-ERRO
               END-READ
               ELSE
                   MOVE 99 to FS-STAT
           END-IF.

       LE-CLIENTE-FIM.

      * -----------------------------------
      * ABRE ARQUIVOS PARA ENTRADA E SAÍDA

       ABRIR-ARQUIVOS.
           OPEN I-O FILE1
           IF FS-NAO-EXISTE THEN
               OPEN OUTPUT FILE1
               CLOSE FILE1
               OPEN I-O FILE1
           END-IF.

      * -----------------------------------
      * MOSTRA MENSAGEM, ESPERA ENTER, ATUALIZA BARRA STATUS

       MOSTRA-ERRO.
           DISPLAY SS-ERRO
           ACCEPT SS-ERRO
           DISPLAY SS-STATUS.
