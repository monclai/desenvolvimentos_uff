IDENTIFICATION DIVISION.
PROGRAM-ID. CHAMADO.
ENVIRONMENT DIVISION.
DATA DIVISION.
       LINKAGE SECTION.
              77 A1   PIC 99.
              77 A2   PIC 99.
              77 RES  PIC 999.

PROCEDURE DIVISION USING A1 A2 RES.
       INICIO.
           DISPLAY "NO PROGRAMA CHAMADO" UPON CONSOLE.
           COMPUTE RES=A1+A2.
           EXIT PROGRAM.

