       identification division.
       program-id. HELLO-WORLD.
       DATA DIVISION.
       working-storage section.
       77 x PIC 99.
       77 y PIC 99.
       77 z PIC 99.
       77 DATAATUAL PIC X(008).
       77 HORAATUAL PIC 9(008).
       77 NOME      PIC X(030) VALUE SPACES.
       77 IDADE     PIC 9(003).
           88 CRIANCA          VALUE 0 THRU 10.
           88 ADOLESCENTE      VALUE 11 THRU 19.
           88 JOVEM            VALUE 20 THRU 30.
           88 ADULTO           VALUE 31 THRU 60.
       PROCEDURE DIVISION.
           SET X TO 10.
           SET Y TO 25.
           ADD X Y GIVING Z.
           DISPLAY "X + Y = "Z.
           DISPLAY "DIGITE SEU NOME: "
           ACCEPT NOME.
           DISPLAY NOME
           ACCEPT DATAATUAL FROM DATE
           DISPLAY DATAATUAL
           DISPLAY "DIGITE SUA IDADE: "
           ACCEPT IDADE
           EVALUATE TRUE
               WHEN CRIANCA DISPLAY "CRIANCA"
               WHEN ADOLESCENTE DISPLAY "ADOLESCENTE"
               WHEN JOVEM DISPLAY "JOVEM"
               WHEN ADULTO DISPLAY "ADULTO"              
               WHEN OTHER DISPLAY "OUTRA CATEGORIA"
           END-EVALUATE
       STOP RUN.
       