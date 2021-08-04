       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX_3.
       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT ARQ-ENTRADA
           ASSIGN TO "/home/monclai/Documentos/cobol/exemplos/file/alunos.dat"
           ORGANIZATION IS LINE SEQUENTIAL.
           ACESS IS SEQUENTIAL
           FILE STATUS IS WS-FS.
       SELECT ARQ-SAIDA
           ASSIGN TO "/home/monclai/Documentos/cobol/exemplos/file/saida.dat"
           ORGANIZATION IS LINE SEQUENTIAL.
           ACESS IS SEQUENTIAL
           FILE STATUS IS WS-FS2.
       
       DATA DIVISION.
       FILE SECTION.
       FD ARQ-ENTRADA.
       01 REG-DATA.
           05 ALU-NUM PIC 9(03).
           05 ALU-NOME PIC A(25).
       FD ARQ-SAIDA.
       01 REG-SAIDA.
           05 SAIDA-NOME PIC A(25).
       
       WORKING-STORAGE SECTION.
       77 WS-FS PIC 99.
       77 WS-FS2 PIC 99.
       01 WS-ALU.
           05 WS-ALUNUM PIC 9(03).
           05 WS-ALUNOME PIC A(25).
       01 WS-EOF PIC A(1).
       
       PROCEDURE DIVISION.
       A01-PROCESSA.
       OPEN INPUT ARQ-ENTRADA.
       IF WS-FS <> 0
       DISPLAY "ERRO DE ABERTURA WS-FS: "WS-FS
       CLOSE ARQ-ENTRADA
       STOP RUN.
       OPEN OUTPUT ARQ-SAIDA
       IF WS-FS2 <> 0
           DISPLAY "ERRO DE ABERTURA DE SAIDA WS-FS2: "WS-FS2
           CLOSE ARQ-ENTRADA
           STOP RUN.
       
       PERFORM UNTIL WS-EOF="Y"
           READ ARQ-ENTRADA INTO WS-ALU
               AT END MOVE "Y" TO WS-EOF
               NOT END PERFORM A02-IMPRIME
           END-READ
       END-PERFORM.
       
       CLOSE ARQ-ENTRADA ARQ-SAIDA.
       STOP RUN.
       
       A02-IMPRIME
       DISPLAY WS-ALU.
       MOVE ALU-NOME TO SAIDA-NOME.
       WRITE REG-SAIDA.