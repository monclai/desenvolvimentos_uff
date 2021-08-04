       IDENTIFICATION DIVISION.
       PROGRAM-ID.PGM001.
       ENVIRONMENT DIVISION.
           INPUT-OUTPUT SECTION.
           FILE-CONTROL.
           SELECT ARQ-ENTRADA
           ASSIGN TO "/home/monclai/Documentos/cobol/exemplos/file/alunos.dat"
           ORGANIZATION IS LINE SEQUENTIAL
           ACCESS IS SEQUENTIAL
           FILE STATUS IS WS-FS.
       DATA DIVISION.
           FILE SECTION.
               FD ARQ-ENTRADA.
               01 REG-DATA.
                   05 ALU-NUM PIC 9(03).
                   05 ALU-NOME PIC A(25).
           WORKING-STORAGE SECTION.
               77 WS-FS PIC 99.
               01 WS-ALU.
                   05 WS-ALUNUM PIC 9(03).
                   05 WS-ALUNOME PIC A(25).
               01 WS-EOF PIC A(1).
                      
       PROCEDURE DIVISION.
              OPEN INPUT ARQ-ENTRADA.
              IF WS-FS <> 0
                  DISPLAY "ERRO NA ABERTURA WS-FS: " WS-FS
                  CLOSE ARQ-ENTRADA
              STOP RUN.
              PERFORM UNTIL WS-EOF = "Y"
                  READ ARQ-ENTRADA INTO WS-ALU
                      AT END MOVE "Y" TO WS-EOF
                      NOT END PERFORM A02-IMPRIME
                  END-READ
              END-PERFORM.
              CLOSE ARQ-ENTRADA.
              PERFORM A03-INCLUI.
                  STOP RUN.
       
              A02-IMPRIME.
                  DISPLAY WS-ALU.
                  
              A03-INCLUI.
                  OPEN EXTEND ARQ-ENTRADA.
                  MOVE 115 TO ALU-NUM.
                  MOVE " MESTRE Lee" TO ALU-NOME.
                  WRITE REG-DATA.
                  CLOSE ARQ-ENTRADA.