      *================================================================= 
       identification division.
       PROGRAM-ID. cpf.
      *================================================================= 

      *================================================================= 
       DATA DIVISION.
      *================================================================= 
       WORKING-STORAGE SECTION.
      *-----------------------------------------------------------------

       01 CPF_DESCRIPTION.
           05 CPF.
              10 P1_CPF PIC 9(1) OCCURS 3.
              10 FILLER PIC X(1) VALUE ".".
              10 P2_CPF PIC 9(1) OCCURS 3.
              10 FILLER PIC X(1) VALUE ".".
              10 P3_CPF PIC 9(1) OCCURS 3.
              10 FILLER PIC X(1) VALUE "-".
              10 P4_CPF PIC 9(1) OCCURS 2.

       77 AUX_VAR PIC 9(3).
       01 DIGIT_VERIFIC_MAIN.
           02 DIGIT_VERIFIC PIC 9(1) OCCURS 2.
       77 I PIC 9(2) VALUE ZERO.
       77 J PIC 9(2) VALUE ZERO.
       01 PESO_MAIN.
           02 PESO PIC 9(2) OCCURS 9.
       
      *=================================================================           
       PROCEDURE DIVISION.
      *=================================================================

       DISPLAY "DIGITE SEU CPF".
       ACCEPT CPF.

       PERFORM VARYING I FROM 1 BY 1 UNTIL I=10
           COMPUTE AUX_VAR = 11 - I
           MOVE AUX_VAR TO PESO(I)
       END-PERFORM.

       MOVE ZERO TO AUX_VAR.

       PERFORM VARYING I FROM 1 BY 1 UNTIL I=4
           COMPUTE AUX_VAR = AUX_VAR + (P1_CPF(I) * PESO(I))
       END-PERFORM.

       MOVE 3 TO J.

       PERFORM VARYING I FROM 1 BY 1 UNTIL I=4
           COMPUTE J = J + 1
           COMPUTE AUX_VAR = AUX_VAR + (P2_CPF(I) * PESO(J))
       END-PERFORM.

       MOVE 6 TO J.

       PERFORM VARYING I FROM 1 BY 1 UNTIL I=4
           COMPUTE J =  J + 1
           COMPUTE AUX_VAR = AUX_VAR + (P3_CPF(I) * PESO(J)) 
       END-PERFORM.

       COMPUTE AUX_VAR = FUNCTION MOD(AUX_VAR, 11).
       COMPUTE AUX_VAR = 11 - AUX_VAR.

       IF AUX_VAR>9
           MOVE ZERO TO AUX_VAR
       END-IF.
       
       MOVE AUX_VAR TO DIGIT_VERIFIC(1).
       MOVE ZERO TO AUX_VAR.



       PERFORM VARYING I FROM 1 BY 1 UNTIL I=10
           COMPUTE AUX_VAR = 12 - I
           MOVE AUX_VAR TO PESO(I)
       END-PERFORM.

       MOVE ZERO TO AUX_VAR.

       PERFORM VARYING I FROM 1 BY 1 UNTIL I=4
           COMPUTE AUX_VAR = AUX_VAR + (P1_CPF(I) * PESO(I))
       END-PERFORM.

       MOVE 3 TO J.

       PERFORM VARYING I FROM 1 BY 1 UNTIL I=4
           COMPUTE J = J + 1
           COMPUTE AUX_VAR = AUX_VAR + (P2_CPF(I) * PESO(J))
       END-PERFORM.

       MOVE 6 TO J.
       
       PERFORM VARYING I FROM 1 BY 1 UNTIL I=4
           COMPUTE J =  J + 1
           COMPUTE AUX_VAR = AUX_VAR + (P3_CPF(I) * PESO(J)) 
       END-PERFORM.

       COMPUTE AUX_VAR = FUNCTION MOD(AUX_VAR, 11).
       COMPUTE AUX_VAR = 11 - AUX_VAR.

       IF AUX_VAR>9
           MOVE ZERO TO AUX_VAR
       END-IF.

       MOVE AUX_VAR TO DIGIT_VERIFIC(2).
       MOVE ZERO TO AUX_VAR.

       IF DIGIT_VERIFIC(1) = P4_CPF(1) AND DIGIT_VERIFIC(2) = P4_CPF(2)
           DISPLAY CPF " (CPF VÁLIDO)"
       ELSE
           DISPLAY CPF " (CPF INVÁLIDO)"
       END-IF.   

       STOP RUN.
       