000000 IDENTIFICATION DIVISION.
000000 PROGRAM-ID arq_reletivo.
000000*
000000 ENVIRONMENT DIVISION.
000000 INPUT-OUTPUT SECTION.
000000 FILE CONTROL.
000000 SELECT nome-de-arquivo
000000 ASSIGN TO referencia-externa-de-arquivo
000000 ORGANIZATION IS RELATIVE
000000 [ACCESS MODE IS modo-de-acesso]
000000 [RELATIVE KEY IS chave-relativa].
000000*
000000 DATA DIVISION.
000000 FILE SECTION
000000 FD nome-de-arquivo
000000 [RECORD tamanho-de-registro].
000000 01 nome-de-registro.
000000 02 nome-de-campo ...
000000 ...
000000 ...
000000*
000000 WORKING-STORAGE SECTION.
000000 [01 chave-relativa PIC 9(5) BINARY].
000000*
000000 PROCEDURE DIVISION.
000000 OPEN modo-de-abertura nome-de-arquivo.
000000 MOVE posição-relativa-de-registro TO chave-relativa.
000000 READ nome-de-arquivo.
000000 START nome-de-arquivo.
000000 REWRITE nome-de-registro.
000000 DELETE nome-de-arquivo.
000000 WRITE nome-de-registro.
000000 CLOSE nome-de-arquivo.
000000
       STOP RUN.