       IDENTIFICATION DIVISION.
       PROGRAM-ID. CONEXAO.

      *================================================================= 
       DATA DIVISION.
      *=================================================================

      *----------------------------------------------------------------- 
       LINKAGE SECTION.
      *-----------------------------------------------------------------

       77 WS-OPCAO                 PIC 9(01).

      *================================================================= 
       PROCEDURE DIVISION USING WS-OPCAO.
      *=================================================================

       EVALUATE WS-OPCAO
               WHEN 1
                  PERFORM CADASTRO THRU CADASTRO-FIM
               WHEN 2
                  PERFORM REGISTRO THRU REGISTRO-FIM
       END-EVALUATE.

       GOBACK.

      *-------------------------------- 
       CADASTRO.
           CALL "aluguel".
       CADASTRO-FIM.

      *------------------------------- 
       REGISTRO.
           CALL "registro_de_filmes".
       REGISTRO-FIM.
       
       